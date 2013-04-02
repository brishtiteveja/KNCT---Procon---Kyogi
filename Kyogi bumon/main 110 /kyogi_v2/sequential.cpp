#include "stdafx.h"
#include "param.h"
#include "image.h"
#include "info.h"
#include "sequential.h"
#include "func.h"
#include "probability_map.h"


int seqval_discord(GameInfo* gi, Image* img, Move m );
void seq_adapt( GameInfo* gi, Image* img, Move m );
ProbMap* probmap;

/**************************************
  sequential1 : 逐次探索
				探索：全探索(過去の探索を活用)
				評価：不一致解消数と距離画像
 **************************************/
void seq_search( GameInfo* gi, Image* img, int tesu, PastInfo* past );
float seqval_distance(GameInfo* gi, Image* img, Move m);

void sequential_main(GameInfo* gi){
	cout << "sequential 1" << endl;
	trial_calc(gi);
	getchar(); getchar();
	int discord;
	int tesu=0;
	Image* img = gi->CopyDiscordImg();
	discord=img->Count();

	PastInfo past(gi);

	
	cout << "初期  不一致:" << discord << endl;

	while( discord!=0 ){
		cout << "第" << ++tesu << "手 " ;
		gi->answer.resize(tesu);
		seq_search(gi,img,tesu,&past);
		discord=img->Count();
		cout << "不一致:" << discord << " temin:" << discord+tesu << endl;
		img->middle_out( tesu-1, discord );
		
		//getchar();
		//img->test_out();
	}
	cout << "完成";
	gi->answer_tesu=tesu;
	
	getchar(); getchar();
}

void seq_search( GameInfo* gi, Image* img, int tesu, PastInfo* past ){
	int i,j,k;
	float v1,v2,v;
	float maxv=-1;
	Move maxm,tmp;
	
	for(k=0;k<gi->stamp->N(); k++){
		for(i=1-gi->PointStampImg(k)->h; i<gi->h; i++){
			for(j=1-gi->PointStampImg(k)->w; j<gi->w; j++){
				tmp=Move(k,j,i);

				if( past->GetVal(tmp) == NONE ) {
				
					v=v1=seqval_discord(gi,img,tmp);
					//if( v1 < 0 ){
					//	v2=seqval_distance(gi,img,tmp);
					//	v+=v2*v1;
					//}
					past->SetVal( tmp, v );
				}
				else {
					v = past->GetVal( tmp ) ;
				}
				
				if( v>maxv ){
					maxv=v; maxm=tmp;
				}
					
				
			}
		}
	}
	seq_adapt(gi,img,maxm);
	cout << "Mov[" << maxm.stamp << "," << maxm.x << "," << maxm.y << "](" << maxv << ")" ;

	gi->answer[tesu-1]=maxm;

	past->DeletePart( maxm );
	

}

int seqval_discord(GameInfo* gi, Image* img, Move m ){
	return StampTry( img, gi->stamp->s[m.stamp], m.x, m.y );
}

//float seqval_distance(GameInfo* gi, Image* img, Move m){
//	Image *di=DistanceTransformation(img);
//	float x=CountImgPow2(di);
//	delete di;
//	return (x/1);
//}

void seq_adapt( GameInfo* gi, Image* img, Move m ){
	StampDo( img, gi->stamp->s[m.stamp], m.x, m.y );
}



/**************************************
  sequential2 : 逐次探索
				探索：分割
				評価：不一致解消数と距離画像
 **************************************/
#define SEQ2_SPLIT 32
#define STAMP_MAX 128
void seq2_search( GameInfo* gi, Image* img );

void sequential2_main(GameInfo* gi){
	cout << "sequential 2" << endl;
	int discord;
	int tesu=0;
	Image* img = gi->CopyDiscordImg();
	discord=img->Count();
	cout << "初期  不一致:" << discord << endl;

	while( discord!=0 ){
		cout << "第" << ++tesu << "手 " ;
		seq2_search(gi,img);
		discord=img->Count();
		cout << "不一致:" << discord << " temin:" << discord+tesu << endl;
		img->middle_out( tesu-1, discord );
		//img->test_out();
		//getchar();
	}
	cout << "完成";
	getchar(); getchar();
}

void seq2_search( GameInfo* gi, Image* img ){
	int i,j,k;
	float v1,v2,v;
	float maxv=-1;
	Move maxm,tmp;

	static int phasey=0,phasex=0;
	static int phasey_max= ( gi->h+gi->shmax%SEQ2_SPLIT==0 ) ? (gi->h+gi->shmax)/SEQ2_SPLIT : (gi->h+gi->shmax)/SEQ2_SPLIT+1;
	static int phasex_max= ( gi->w+gi->swmax%SEQ2_SPLIT==0 ) ? (gi->w+gi->swmax)/SEQ2_SPLIT : (gi->w+gi->swmax)/SEQ2_SPLIT+1;
	
	
restart:
	for(k=0;k<gi->stamp->N(); k++){
		for(i=phasey*SEQ2_SPLIT+1-STAMP_MAX; i<gi->h && i<(phasey+1)*SEQ2_SPLIT-STAMP_MAX; i++){
			for(j=phasex*SEQ2_SPLIT+1-STAMP_MAX; j<gi->w && j<(phasex+1)*SEQ2_SPLIT-STAMP_MAX; j++){
				tmp=Move(k,j,i);
				v=v1=seqval_discord(gi,img,tmp);
				//if( v1 < 0 ){
				//	v2=seqval_distance(gi,img,tmp);
				//	v+=v2*v1;
				//}
				if( v>maxv ){
					maxv=v; maxm=tmp;
				}
			}
		}
	}
	if(maxv<=1){
		if(phasex==phasex_max && phasey==phasey_max)
			goto output;
		if(phasex==phasex_max){
			phasex=0; phasey++;
		}
		else
			phasex++;
		goto restart;
	}
	seq_adapt(gi,img,maxm);
output:
	cout << "phase[" << phasey << "," << phasex << "] Mov[" << maxm.stamp << "," << maxm.x << "," << maxm.y << "](" << maxv << ")" ;
	
}


/**************************************
  sequential3 : 逐次探索
				探索：ランダム
				評価：不一致解消数と距離画像
 **************************************/

void seq3_search( GameInfo* gi, Image* img, int rnd_n );
void sequential3_main(GameInfo* gi){
	cout << "sequential 3" << endl;
	int rnd_n;
	cout << "Rand_n : ";
	cin >> rnd_n;
	int discord;
	int tesu=0;
	Image* img = gi->CopyDiscordImg();
	discord=img->Count();
	cout << "初期  不一致:" << discord << endl;

	while( discord!=0 ){
		cout << "第" << ++tesu << "手 " ;
		seq3_search(gi,img,rnd_n);
		discord=img->Count();
		cout << "不一致:" << discord << " temin:" << discord+tesu << endl;
		//img->test_out();
	}
	cout << "完成" << endl;
}

void seq3_search( GameInfo* gi, Image* img, int rnd_n ){
	int i,j,k;
	float v1,v2,v;
	float maxv=-1;
	Move maxm,tmp;
	static int l_one=0; 

	if(l_one<200){
restart:
		for(i=0;i<rnd_n;i++){
			tmp=Move(rand()%gi->stamp->N(),rand()%gi->w,tmp.y=rand()%gi->h);
			v=v1=seqval_discord(gi,img,tmp);
			/*if( v1 < 0 ){
				v2=seqval_distance(gi,img,tmp);
				v+=v2*v1;
			}*/
			if( v>maxv ){
				maxv=v; maxm=tmp;
			}
		}
		if(maxv<=0) goto restart;
	}
	else{
		for(i=1-gi->stamp->s[gi->stamp->Min()]->h; i<gi->h; i++){
			for(j=1-gi->stamp->s[gi->stamp->Min()]->w; j<gi->w; j++){
				if(img->GetPixel(j,i)==1){
					maxm=Move(gi->stamp->Min(),j,i);
					goto adpt;
				}
			}
		}
	}
adpt:
	seq_adapt(gi,img,maxm);
	cout << "Mov[" << maxm.stamp << "," << maxm.x << "," << maxm.y << "](" << maxv << ")" ;

	if(maxm.stamp==gi->stamp->Min())
		l_one++;
	else
		l_one=0;

}


/**************************************
  sequential4 : 逐次探索(同時適用)
				探索：全探索
				評価：不一致解消数と距離画像
				重なり防止のマップ使用、同時適用にはキュー使用
 **************************************/
//
//void seq_search4( GameInfo* gi, Image* img, list<Move> *mq, int *tesu  );
//int seqval4_discord(GameInfo* gi, Image* img, Move m, Image* wmap, bool* is_fallon);
//void seqval4_fill_wmap(GameInfo* gi, Move m, Image* wmap);
//
//void sequential4_main(GameInfo* gi){
//	cout << "sequential 4" << endl;
//	int discord;
//	int tesu=0;
//	Image* img = gi->CopyDiscordImg();
//	list<Move> mq;
//	discord=img->Count();
//	cout << "初期  不一致:" << discord << endl;
//	while( discord!=0 ){
//		
//		seq_search4(gi,img,&mq,&tesu);
//		discord=img->Count();
//		img->middle_out( tesu-1, discord );
//		cout << "不一致:" << discord << " temin:" << discord+tesu << endl;
//	}
//	cout << "完成";
//	getchar(); getchar();
//}
//
//void seq_search4( GameInfo* gi, Image* img, list<Move> *mq, int *tesu ){
//	int i,j,k;
//	float v1,v2,v;
//	float maxv=-1;
//	bool is_fallon=false;
//	Move maxm,tmp;
//	Image* wmap = new Image(gi->w,gi->h);
//	wmap->init(0);
//	mq->clear();
//	
//	for(k=0;k<gi->stamp->N(); k++){
//		for(i=1-gi->PointStampImg(k)->height(); i<gi->h; i++){
//			for(j=1-gi->PointStampImg(k)->width(); j<gi->w; j++){
//				tmp=Move(k,j,i);
//				v=v1=seqval4_discord(gi,img,tmp,wmap,&is_fallon);
//				//if( v1 < 0 ){
//				//	v2=seqval_distance(gi,img,tmp);
//				//	v+=v2*v1;
//				//}
//				if( v>0 && v>maxv*1.2 ){
//					
//					maxv=v; 
//					mq->clear(); wmap->init(0);
//					seqval4_fill_wmap(gi,tmp,wmap);
//					mq->push_front(tmp);
//					
//				}
//				else if( v>0 && v>=maxv*0.8 && is_fallon==false ){
//					
//					seqval4_fill_wmap(gi,tmp,wmap);
//					mq->push_front(tmp);
//					
//				}
//				
//			}
//		}
//	}
//	while( !mq->empty() ){
//		cout << "第" << ++*tesu << "手 " ;
//		tmp=mq->back();
//		seq_adapt(gi,img,tmp);
//		cout << "Mov[" << tmp.stamp << "," << tmp.x << "," << tmp.y << "](" << maxv << ")" << endl ;
//		mq->pop_back();
//	}
//
//	delete wmap;
//	
//}
//
//int seqval4_discord(GameInfo* gi, Image* img, Move m, Image* wmap, bool* is_fallon){
//	int i,j,k,val=0;
//	*is_fallon=false;
//	for(i=0; i<gi->PointStampImg(m.stamp)->height(); i++){
//		for(j=0; j<gi->PointStampImg(m.stamp)->width() ;j++){			
//			if( 0<=i+m.y && i+m.y<gi->h && 0<=j+m.x && j+m.x<gi->w ) {
//				if( gi->PointStampImg(m.stamp)->img[i][j]==1 ){
//					if( wmap->img[i+m.y][j+m.x]==1 ){
//						*is_fallon=true;
//					}
//					if( img->img[i+m.y][j+m.x]==1 ) 
//						val++;
//					else 
//						val--;
//				}
//			}
//		}
//	}
//	return val;
//}
//
//void seqval4_fill_wmap(GameInfo* gi, Move m, Image* wmap){
//	int i,j;
//	for(i=0; i<gi->PointStampImg(m.stamp)->height(); i++)
//		for(j=0; j<gi->PointStampImg(m.stamp)->width() ;j++)	
//			if( 0<=i+m.y && i+m.y<gi->h && 0<=j+m.x && j+m.x<gi->w )
//				if( gi->PointStampImg(m.stamp)->img[i][j]==1 )
//					wmap->img[i+m.y][j+m.x]=1;
//}
//

//
///**************************************
//  sequential5 : 確率マップ
//				探索：確率マップ
//				評価：不一致解消数と距離画像
// **************************************/
//void seq_search( GameInfo* gi, Image* img, int tesu );
//float seqval_distance(GameInfo* gi, Image* img, Move m);
//
//void sequential_main(GameInfo* gi){
//	cout << "sequential 1" << endl;
//	trial_calc(gi);
//	getchar(); getchar();
//	int discord;
//	int tesu=0;
//	Image* img = gi->CopyDiscordImg();
//	discord=CountImg(img);
//
//	probmap = new ProbMap(gi);
//	probmap->SetMag(10.0);
//
//	
//	cout << "初期  不一致:" << discord << endl;
//
//	while( discord!=0 ){
//		cout << "第" << ++tesu << "手 " ;
//		gi->answer.resize(tesu);
//		seq_search(gi,img,tesu);
//		discord=CountImg(img);
//		cout << "不一致:" << discord << " temin:" << discord+tesu << endl;
//		img->middle_out( tesu-1, discord );
//		probmap->SetMag(0.02);
//		//getchar();
//		//img->test_out();
//	}
//	cout << "完成";
//	gi->answer_tesu=tesu;
//	getchar(); getchar();
//}
//
//void seq_search( GameInfo* gi, Image* img, int tesu ){
//	int i,j,k;
//	float v1,v2,v;
//	float maxv=-1;
//	Move maxm,tmp;
//	
//	for(k=0;k<gi->stamp->N(); k++){
//		for(i=1-gi->PointStampImg(k)->height(); i<gi->h; i++){
//			for(j=1-gi->PointStampImg(k)->width(); j<gi->w; j++){
//				tmp=Move(k,j,i);
//				if( !probability( probmap->Prob(tmp) ) ) continue;
//				v=v1=seqval_discord(gi,img,tmp);
//				//if( v1 < 0 ){
//				//	v2=seqval_distance(gi,img,tmp);
//				//	v+=v2*v1;
//				//}
//				if( v>0 )
//					probmap->MultiProb( tmp,(2*v)/maxv );
//				else
//					probmap->MultiProb( tmp,0 ) ;
//
//				if( v>maxv ){
//					maxv=v; maxm=tmp;
//				}
//					
//				
//			}
//		}
//	}
//	seq_adapt(gi,img,maxm);
//	cout << "Mov[" << maxm.stamp << "," << maxm.x << "," << maxm.y << "](" << maxv << ")" ;
//	probmap->MultiProb( maxm,0 );
//	gi->answer[tesu-1]=maxm;
//
//}