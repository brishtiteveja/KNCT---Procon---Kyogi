#include "stdafx.h"
#include "param.h"

#include "image.h"
#include "info.h"
#include "tree.h"
#include "func.h"


//void nextgene_to_thread1() {
//		//cout << k <<endl;
//		cout << "hello" <<endl;
//	}






//toThread* thrP;
toThread::toThread( ){
	plist.clear();
	clist.clear();

}


void toThread:: nextgene_to_thread(void *ptr) {
	//cout << k <<endl;
	toThread* thP = (toThread*) ptr;

	thP->next_gene_inthread();
}

void toThread::next_gene_inthread() {

	list<TNode>::iterator it = plist.begin();
	while( it != plist.end() )  // listの末尾まで
	{
		if( !make_child(&*it,&clist) )
			cout << "error next_gene";
		
		++it;  // イテレータを１つ進める
	}

	clist.sort();
}



//////////////////////////////////////////////////////////////////////////////////////

float toThread::calc_value(TNode* node){
	int x=0,i,j,k,t;

	x = StampTry( node->parent->img, gi->stamp->s[node->stamp], node->x, node->y );

	return (float)x;


	
	
}

int Tree::calc_discord(TNode* node)
{
	return node->img->Count();
}

int Tree::br_bs(TNode* node, Move m){
	int x=m.x ,y=m.y,br,bs;
	Image* sp = gi->stamp->s[m.stamp ]->simg [0];

	br = node->img->CalcBlack(m.x, m.y, m.x+sp->w, m.y+sp->h);

	int sx = (m.x<0) ? -m.x : 0;
	int sy = (m.y<0) ? -m.y : 0;
	int sxr = (m.x+sp->w >= gi->w) ? gi->w-m.x : sp->w;
	int syr = (m.y+sp->h >= gi->h) ? gi->h-m.y : sp->h;
	bs = sp->CalcBlack(sx, sy, sxr, syr);


	/////////////
	/*if(m.y < 0) y = 1;
	if(m.x < 0) x = 1;
	vector<vector <unsigned short int>> *tmp1,*tmp2;
	
	tmp1= &(node->img->ruiseki);

	Image* sp = gi->stamp->s[m.stamp ]->simg [0];


	br = */
	 
	//for stamp
	//tmp2 = &( gi->stamp->s[m.stamp ]->simg [0]->ruiseki );

	//int  stw =  sp->w - 1 ,          sth   =  sp->h -1 ;
	//int imgh =  node->img->h - 1,    imgw  =  node->img->w - 1;
 //  
	//if(m.x < 0){  // Left side of the image
	//	if(m.y < 0){ // 1. Up Left side
	//		br =  (*tmp1)[sth + m.y][stw + m.x] ;
	//		bs =  (*tmp2)[sth][stw] + (*tmp2)[- m.y -1][-m.x-1] - (*tmp2)[- m.y -1][stw] - (*tmp2)[sth][-m.x - 1] ;
	//	}
	//	else if(m.y + sth > imgh){ //2.Down Left
	//		br =  (*tmp1)[imgh][stw + m.x] - (*tmp1)[m.y][stw + m.x]  ;
	//		bs =  (*tmp2)[imgh - m.y][stw] - (*tmp2)[ imgh - m.y] [-m.x - 1] ;
	//	}
	//	else   {     //3.Middle Left
	//		br =   (*tmp1)[m.y + sth][stw + m.x] - (*tmp1) [m.y][stw + m.x];
	//		bs =  (*tmp2)[sth][stw] - (*tmp2) [sth][-m.x - 1];
	//	}
 //  }
	//else if(m.x + stw > imgw ){  //Right side of the  image
	//	if(m.y < 0){             //4.Up Right
	//		bs =  (*tmp)[sth][imgw - m.x] - (*tmp)[sth + m.y][imgw - m.x];
	//	}
	//	else if(m.y + sth > imgh){//5.down Right
	//		bs =  (*tmp)[imgh - m.y][imgw - m.x ] - (*tmp)[m.y -1 ][m.x + imgw + stw]  ;
	//	}         
	//	else                      //6.middle Right
	//		bs =  (*tmp)[imgw - m.x][sth];
	//}
	//else if(0<= m.x && m.x + stw <= imgw){ 
	//	if(m.y<0){						//7. Up side
	//		bs = (*tmp)[sth][stw] - (*tmp)[m.y - 1][stw];
	//	}
	//	else{                             //8.Down side
	//		bs = (*tmp)[stw][imgh - m.y];
	//	}
	//}
	//else{		
	//	br = (*tmp) [][];
	//	bs = (*tmp) [stw][sth];        // 9.inside
	//}
	//cout << "br=" << br<< " bs=" << bs << " br-bs=" << br-bs;

	return br- bs;
}



//１つの親から子を作る
bool toThread::make_child(TNode* parent, list<TNode>* clist){
	
	parent->img->MakeCumulative();



	TNode tnp;
	bool child_exist=false;
	int black_sum;


	int i,j,k,n=0;

	////黒の数計算
	//br_bsArray.resize(gi->stamp->N() * (gi->w+128) * (gi->h+128) );
	//for(k=0; k<gi->stamp->N(); k++){
	//	if( gi->stamp->sinf[k].use == 0 ) continue;
	//	for(i=1-gi->stamp->s[k]->h; i<parent->img->h; i++){
	//		for(j=1-gi->stamp->s[k]->w; j<parent->img->w; j++){
	//			//br_bsArray[n++]=br_bs(parent,Move(k,j,i));
	//		//	cout << k << " " << i << " " << j << " ";
	//			br_bs(parent,Move(k,j,i));
	//			//cout << endl;
	//		}
	//	}
	//}

	

	if( parent->parent==NULL ){ //親がtopのとき		
		for(k=0; k<gi->stamp->N(); k++){
			if( gi->stamp->sinf[k].use == 0 ) continue;
			for(i=1-gi->stamp->s[k]->h; i<parent->img->h; i++){
				//cout << k << " " << i <<  endl;
				for(j=1-gi->stamp->s[k]->w; j<parent->img->w; j++){
					tnp.parent=parent;
					tnp.stamp=k;
					tnp.x=j;
					tnp.y=i;
					if( parent->past->GetVal( tnp.getMove() ) == NONE ){
						tnp.value = calc_value(&tnp);
						parent->past->SetVal( tnp.getMove(), tnp.value );
					}
					else
						tnp.value = parent->past->GetVal(tnp.getMove());

					//評価が正でないものはこの時点でカット
					if( tnp.value>0 ){
						tnp.value += tnp.parent->value;
						clist->push_back(tnp);
						child_exist=true;
					}
				}
			}
		}
	}
	else{
		int i,j,k;
		child_exist = false;
		if( gi->search_mode == 1 ) {
			for(k=0; k<gi->stamp->N(); k++){
				if( gi->stamp->sinf[k].use == 0 ) continue;

				

			
				//近傍探索

				for(i=parent->y-gi->stamp->s[k]->h; i<parent->y+gi->stamp->s[parent->stamp]->h + gi->stamp->s[k]->h && i<parent->img->h; i++){
					for(j=parent->x-gi->stamp->s[k]->w; j<parent->x+gi->stamp->s[parent->stamp]->w + gi->stamp->s[k]->w && j<parent->img->w; j++){
						tnp.parent=parent;
						tnp.stamp=k;
						tnp.x=j;
						tnp.y=i;
						if( parent->past->GetVal( tnp.getMove() ) == NONE ){
							tnp.value = calc_value(&tnp);
							parent->past->SetVal( tnp.getMove(), tnp.value );
						}
						else
							tnp.value = parent->past->GetVal(tnp.getMove());

						//評価が正でないものはこの時点でカット
						if( tnp.value>0 ){
							tnp.value += tnp.parent->value;
							clist->push_back(tnp);
							if( tnp.value>=2 )
								child_exist=true;
						}
					
					}
				}
			}
			
		}
		
		if(child_exist==false){
			for(k=0; k<gi->stamp->N(); k++){
				if( gi->stamp->sinf[k].use == 0 ) continue;
				for(i=1-gi->stamp->s[k]->h; i<parent->img->h; i++){
					for(j=1-gi->stamp->s[k]->w; j<parent->img->w; j++){
						tnp.parent=parent;
						tnp.stamp=k;
						tnp.x=j;
						tnp.y=i;
						if( parent->past->GetVal( tnp.getMove() ) == NONE ){
							tnp.value = calc_value(&tnp);
							parent->past->SetVal( tnp.getMove(), tnp.value );
						}
						else
							tnp.value = parent->past->GetVal(tnp.getMove());

						//評価が正でないものはこの時点でカット
						if( tnp.value>0 ){
							tnp.value += tnp.parent->value;
							clist->push_back(tnp);
							child_exist=true;
						}
					}
				}
			}

		}

	
	

	}
	return child_exist;
}



//複数の親から次世代の子を作る
void Tree::next_gene(list<TNode>* plist, list<TNode>* clist){


	
	toThread *thrP = new toThread [THREAD_N];
	
	int i=0;

	for( i=0; i<THREAD_N; i++ ){
		thrP[i].index = i;
		thrP[i].gi = this->gi;
	}
	
	list<TNode>::iterator it = plist->begin();

	//仮　すべて平等に割り振る
	i=0;
	while( it != plist->end() )  // listの末尾まで
	{
		thrP[i%THREAD_N].plist.push_back(*it);
		it++; i++;
	}

	boost::thread_group thrg;

	for( i=0; i<THREAD_N; i++ ){
		thrg.create_thread(bind(&((thrP + i) ->nextgene_to_thread ),thrP + i));
	}

	thrg.join_all();

	for( i=0; i<THREAD_N; i++ ) {
		clist->merge( thrP[i].clist );
	}

	


	//以下は元のソース   
	//list<TNode>::iterator it = plist->begin();
	//while( it != plist->end() )  // listの末尾まで
	//{
	//	if( !make_child(&*it,clist) )
	//		cout << "error next_gene";
	//	
	//	++it;  // イテレータを１つ進める
	//}

	cout << " children:" << tnlist->size() << " "; 
}

void Tree::make_img(list<TNode>* clist)
{
	int i,j,k;
	long csum,csumd_n=0;
	vector<unsigned long>csumd(MAX_CHILDREN);
	bool complete=false;
	TNode tmp;
	int n=clist->size();

	vector<Image*> *oldvp, *newvp;
	vector<PastInfo*> *oldpp, *newpp;
	if( gene%2==1 ) { 
		oldvp=&parent_image; newvp=&parent_image2; 
		oldpp=&parent_past; newpp=&parent_past2; 
	}
	else {
		oldvp=&parent_image2; newvp=&parent_image; 
		oldpp=&parent_past2; newpp=&parent_past; 
	
	}



	for(int i=0;i<n;i++){
		tmp=clist->front();
		clist->pop_front();

		//make past
		(*newpp)[i]=new PastInfo(*(tmp.parent->past));
		(*newpp)[i]->DeletePart(tmp.getMove());

		//make image 
		
		(*newvp)[i]=new Image(*(tmp.parent->img));
	
		StampDo( (*newvp)[i], gi->stamp->s[tmp.stamp], tmp.x, tmp.y );

		//calclate sum
		csum=(*newvp)[i]->csum();
		

		//check sum
		for(j=0; j<csumd_n; j++) {
			if( csum == csumd[j] )
				tmp.value=0;
		}
		csumd[csumd_n++]=csum;

	/*	if( tmp.value != 0 ){
			Image *dimg = new Image(*(*newvp)[i]);
			DistanceTransformation(dimg);
			tmp.value += CountImg(dimg)/100000;
			delete dimg;
		}*/
		

		tmp.past = (*newpp)[i];//pastポインタをコピー
		tmp.img = (*newvp)[i]; //imgポインタをコピー
		clist->push_back(tmp);
		i=i;
	}

	for(i=0; i<(*oldvp).size(); i++) {
		if ( (*oldvp)[i]!=NULL ){
			delete (*oldvp)[i];
			(*oldvp)[i]=NULL;
		}
	}
	for(i=0; i<(*oldpp).size(); i++) {
		if ( (*oldpp)[i]!=NULL ){
			delete (*oldpp)[i];
			(*oldpp)[i]=NULL;
		}
	}
	
}



void Tree::msend( int gene ){
	
	TNode *tn = &(tree.back()->front());
	gi->answer_tesu=gene;
	gi->answer.resize(gi->answer_tesu);
	gi->answer[gi->answer_tesu-1]=Move(tn->stamp, tn->x, tn->y);
	for(int i=gi->answer_tesu-2; i>=0; i--){
		tn = tn->parent;
		gi->answer[i] = Move(tn->stamp, tn->x, tn->y);
	}
	gi->OutAnswer_Middle(gene,(tree.back()->front()).img);

	gi->cmd_msend = 0;
}

void Tree::outParentImg( Image * img ) {
	ofstream ofs;
	ofs.open("C:\\kyogi_public\\kyogi_final_test\\kyoyu\\mainToassist.txt");
	ofs << gene << endl;
	img->outimage(ofs);
	ofs.close();
}

void Tree::ParentImgInit(){
	ofstream ofs;
	ofs.open("C:\\kyogi_public\\kyogi_final_test\\kyoyu\\mainToassist.txt");
	ofs << "-1" << endl;
	ofs.close();
}
	
void Tree::treemain(){
	TNode tntmp;

	int dis;
	int pal_f=0;	//パラメータ変更に使用

	gene=1;
	string mctmp;

	//ParentImgInit();

	//比較回数試算
	float tcalc = trial_calc(gi);

	memorymaxc_calc( gi );
	

	switch(gi->alno) {
	case 8:
		if( gi->cmd_param1 != 0 ) {
			MAX_MAX_CHILDREN = gi->cmd_param1;
			cout << "Max_Param : " << MAX_MAX_CHILDREN;
		}
		else {
			//cout << "Max_Param : ";
			//cin >> mctmp;
			//MAX_MAX_CHILDREN = atoi(mctmp.c_str());
			MAX_MAX_CHILDREN = 100000;
		}
		if( gi->cmd_param2 != 0 ) {
			MAX_CHILDREN = gi->cmd_param2;
			cout << "Initial_Param : " << MAX_CHILDREN;
		}
		else {
			cout << "Initial_Param : ";
			cin >> mctmp;
			gi->cmd_param2 = MAX_CHILDREN = atoi(mctmp.c_str());
		}
		break;
	case 9:
		MAX_MAX_CHILDREN = MAX_CHILDREN = 900 * 1.0/(tcalc/1000000.0);
		cout << "Auto Param : " << PARAM_E << endl;
		if( PARAM_E <= 81 ) { cout << "このアルゴリズムでは解けません" << endl; return; }
		PARAM_R = 0;
		break;
	}

	gi->t=time(NULL);
	time_t t_mout = time(NULL);

	
	getchar();

	parent_image.resize(MAX_MAX_CHILDREN+1,NULL);
	parent_past.resize(MAX_MAX_CHILDREN+1,NULL);
	parent_image2.resize(MAX_MAX_CHILDREN+1,NULL);
	parent_past2.resize(MAX_MAX_CHILDREN+1,NULL);
	parent_image[0]=gi->CopyDiscordImg();
	parent_past[0]=new PastInfo(gi);

	top.img=parent_image[0];
	top.past = parent_past[0];
	top.parent=NULL;
	top.value=0;
	top.past = new PastInfo(gi);

	//コマンド読み込み
	gi->read_command();
	if( gi->alno==8 ){
		MAX_CHILDREN = gi->cmd_param2;
	}

	
	tnlist = new list<TNode>;
	tnlist->clear();
	cout << gene;// << endl;

	//outParentImg(top.img);

	list<TNode> topl;
	topl.push_back(top);
	next_gene(&topl,tnlist);

	

	//ソート
	tnlist->sort( greater<TNode>() );

	//選択
	for(int i=0; tnlist->size()>MAX_CHILDREN; i++) {
		tnlist->pop_back();
	}

	//IMG作成
	make_img(tnlist);

	//treeに格納
	tree.push_back(tnlist);
	
	tntmp=tnlist->front();
	cout << " use:" << tnlist->front().stamp << " topval:" << tnlist->front().value << " dis:" << calc_discord(&tntmp) << endl;

	gene++;

	//2世代目以降
	do{
		tnlist = new list<TNode>;

		cout << gene << " t:" << gi->Time() ;// << endl;
		next_gene(*(&tree.back()),tnlist);

		//ソート
		tnlist->sort( greater<TNode>() );

		

		//選択
		for(int i=0; tnlist->size()>MAX_CHILDREN; i++) {
			tnlist->pop_back();
		}

		

		//IMG作成
		make_img(tnlist);
		
		//親のImageを解放
		//delete_oldimg();

		//treeに格納
		tree.push_back(tnlist);
		 tntmp=tnlist->front();
		dis=calc_discord(&tntmp);
		cout << " stampno:" << tnlist->front().stamp << " topval:" << tnlist->front().value << " dis:" << dis << " te_max:" << gene+dis << endl;

	
		if( time(NULL) - t_mout > 1 ){
			
			//中間出力作成
			tnlist->front().img->middle_out( gene, dis );
			t_mout = time(NULL);

			//コマンド読み込み
			gi->read_command();
			if( gi->alno==8 ){
				MAX_CHILDREN = gi->cmd_param2;
				
			}

			if( gi->cmd_msend ) {
				//解答の中間出力
				msend(gene);
			}
		}

		
		gene++;
	} while( dis!=0 && gi->cmd_quit != 1 );
	if( dis==0 ) cout << "完成 ";
	if( gi->cmd_quit==1 ) cout << "探索打ち切り ";

	//中間出力
	
	(tree.back())->front().img->middle_out( gene-1, dis );
	
	
	//解答出力
	TNode *tn = &(tree.back()->front());
	gi->answer_tesu=gene-1;
	gi->answer.resize(gi->answer_tesu);
	gi->answer[gi->answer_tesu-1]=Move(tn->stamp, tn->x, tn->y);
	for(int i=gi->answer_tesu-2; i>=0; i--){
		tn = tn->parent;
		gi->answer[i] = Move(tn->stamp, tn->x, tn->y);
	}

	
}

void engine_tree(GameInfo* gi){
	Tree tree(gi);
	//tree.make_child = (tree.make_child_all) ;
	tree.treemain();
}