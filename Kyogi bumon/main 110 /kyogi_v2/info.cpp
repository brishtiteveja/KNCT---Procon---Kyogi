#include "stdafx.h"
#include "param.h"
#include "image.h"
#include "info.h"


Stamp::Stamp( int stamp_n = 0 ) {
	s_n_max=stamp_n;
	s_n=0; s_min=-1;
	s.resize(s_n_max);
	sinf.resize(s_n_max);
	
}

Stamp::Stamp(const Stamp &obj){
	s=obj.s;
	sinf = obj.sinf;
	s_n=obj.s_n;
	s_n_max=obj.s_n_max;
	s_min=obj.s_min;
}

Stamp::~Stamp(){
	s.clear(); 
}

void Stamp::append(SImage* stampimg){
	s[s_n]=stampimg;
	sinf[s_n].use = 1;
	if(stampimg->is1px()) s_min=s_n;
	s_n++;

}

bool Stamp::check(){
	if(s_n==s_n_max && s_min!=0) return true;
	return false;
}



//////////////////////////////////////////////////////////////////////////////////

void GameInfo::set_discord(){
	shoki_discord=new Image(*shoki,*saishu);
		
	discord_rate=(float)discord/(w*h);
}

GameInfo::GameInfo() {
	precom.resize(65536);
	unsigned short int tmp,x;
	//set precom
	for( int i=0; i<65536; i++ ) {
		x=0;
		tmp = (unsigned short int) i;
		for( int j=0; j<16; j++ ){
			
			x += tmp & 0x01;
			tmp = tmp / 2;
		}
		precom[i] = x;
	}
	 cmd_start = 0;
	 cmd_quit  = 0;
	 cmd_alno  = 0;
	 cmd_msend = 0;
	 cmd_param1 = 0;
	 cmd_param2 = 0;
};

GameInfo::GameInfo (const GameInfo &obj){
	shoki=new Image(*(obj.shoki));
	saishu=new Image(*(obj.saishu));
	stamp=new Stamp(*(obj.stamp));
}

GameInfo::~GameInfo(){
	delete shoki;
	delete saishu;
	delete stamp;
}

void GameInfo::readfile(string fname){

	//コマンドのリセット
	reset_command();

	


	ifstream fs(fname);
	
	string line;
	int w,h,i,j;
	Image* ip;
	SImage* ip2;

	

	
	//w,h
	getline(fs,line);
	w=atoi(line.c_str());
	getline(fs,line);
	h=atoi(line.c_str());

	//マスク作成
	mask=new Image(w,h,NULL,&precom);
	for(i=0; i<h; i++)
		for(j=0; j<w; j++ )
			mask->SetPixel(j,i,1);

	//初期画像
	shoki=new Image(w,h,mask,&precom);

	shoki->getimage(fs);
	this->w=shoki->w; this->h=shoki->h;
	//cout << "shoki" << endl;
	//shoki->test_out();

	//最終画像
	getline(fs,line);
	w=atoi(line.c_str());
	getline(fs,line);
	h=atoi(line.c_str());
	saishu=new Image(w,h,mask,&precom);
	saishu->getimage(fs);
	//cout << "saishu" << endl;
	//saishu->test_out();
	
	//スタンプ
	swmax=1; shmax=1;
	getline(fs,line);
	int stamp_n=atoi(line.c_str());
	stamp=new Stamp(stamp_n);
	for(i=0;i<stamp_n;i++){
		getline(fs,line);
		w=atoi(line.c_str());
		if(w>swmax) swmax=w;
		getline(fs,line);
		h=atoi(line.c_str());
		if(h>shmax) shmax=h;
		ip=new Image(w,h,mask,&precom);
		ip->getimage(fs);
		ip2 = new SImage(*ip);
		stamp->append(ip2);
		stamp->s[i]->simg [0]->MakeCumulative ();
	}

	fs.close();
	//stamp->test_out();
	if(stamp->check()==true)
		cout << "Input file succeed" << endl;
	set_discord();
	shoki_discord->MakeCumulative ();
	//cout << "discord" << endl;
	//shoki_discord->test_out();

	read_command();
}

void GameInfo::read_command() {
	ifstream ifs;
	
	int i,tmp;
	string line;

	myopen(ifs,cmd_fname);

	//ヘッダの読み取り
	getline(ifs,line);

	//開始・解答・終了コマンド
	getline(ifs,line);
	tmp = atoi(line.c_str());

	switch(tmp) {
	case 1: 
		cmd_start = 1; break;
	case 2: 
		cmd_start = 2; break;
	case 3: 
		cmd_msend = 1; break;
	case 4:
		cmd_quit = 1; break;
	case 5:
		cmd_quit = 1;
		cmd_start = 2; break;
	}

	//アルゴリズム番号コマンド
	getline(ifs,line);
	if( atoi(line.c_str()) == 1 ){
		cout << "command_read SEARCH_MODE 全探索" << endl;
		search_mode = 0;
	}
	else if( atoi(line.c_str()) == 2 ){
		cout << "command_read SEARCH_MODE 近傍探索" << endl;
		search_mode = 1;
	}

	//パラメータ変更コマンド
	getline(ifs,line);
	if( 0 > atoi(line.c_str()) ){
			cout << "command 不正なフォーマット" << endl;
			goto close;
		}
	if( 0 < atoi(line.c_str())){
		
		cmd_param1 = atoi(line.c_str());
		cout << "command_read PARAM_1 " << cmd_param1 << endl;
	}
	getline(ifs,line);
	if( 0 > atoi(line.c_str()) ){
			cout << "command 不正なフォーマット" << endl;
			goto close;
		}
	if( 0 < atoi(line.c_str())){
		
		cmd_param2 = atoi(line.c_str());
		cout << "command_read PARAM_2 " << cmd_param2 << endl;
	}

	//use変更コマンド
	getline(ifs,line);
	
	while( 0 <= atoi(line.c_str()) ){
		int index = atoi(line.c_str());
		getline(ifs,line);
		if( 0 > atoi(line.c_str()) ){
			cout << "command 不正なフォーマット" << endl;
			break;
		}
		stamp->sinf[index].use = atoi(line.c_str());
		cout <<  "command_read USE " << index << " " << stamp->sinf[index].use << endl;
		getline(ifs,line);
	}
close:

	ifs.close();
	reset_command();
}

void GameInfo::reset_command(){
	ofstream ofs;
	myopen(ofs,cmd_fname);
	ofs << "0" << endl << "0" << endl << "0" << endl << "0" << endl << "0" << endl << "-1" << endl;
	ofs.close();
}


void GameInfo::OutAnswer(){
	
	ofstream ofs(ANSWER_PATH);
	
	
	ofs << answer_tesu << endl;
	
	for(int i=0;i<answer_tesu;i++){
		ofs << answer[i].stamp << " " << answer[i].x << " " << answer[i].y << endl;
	}
	ofs.close();
	cout << "OutAnswer(Final) tesu=" << answer_tesu << endl;  

}

void GameInfo::OutAnswer_Middle( int mtesu, Image * img ){
	int i,j,k,n=0;

	ofstream ofs(ANSWER_PATH);
	
	ofs << mtesu + img->Count() << endl;

	//後で書き換え

	for(j=0; j<img->h; j++) {
		for(k=0; k<img->w; k++) 
			if( img->GetPixel(k,j) == 1 ) 
				ofs << stamp->Min() << " " << k << " " << j << endl;
	}


	
	
	for(int i=0;i<answer_tesu;i++){
		ofs << answer[i].stamp << " " << answer[i].x << " " << answer[i].y << endl;
	}
	ofs.close();

	cout << "OutAnswer(Middle) tesu=" << answer_tesu + img->Count() << endl;  


}




///////////////////////////////////////////////////////////////////////////////////////////////

// PastInfo

PastInfo::PastInfo( GameInfo* inf ) {
	gi=inf; 

	val = new float ** [gi->stamp->N()];
	for( int i=0; i<gi->stamp->N(); i++ ) {
		val[i] = new float * [gi->h+gi->shmax-1];
		for( int j=0; j<gi->h+gi->shmax-1; j++ ) {
			val[i][j] = new float [gi->w+gi->swmax-1];
			for( int k=0; k<gi->w+gi->swmax-1; k++ ) {
				val[i][j][k] = NONE;
			}
		}
	}
}

PastInfo::PastInfo( const PastInfo &obj ) {
	gi=obj.gi;

	val = new float ** [gi->stamp->N()];
	for( int i=0; i<gi->stamp->N(); i++ ) {
		val[i] = new float * [gi->h+gi->shmax-1];
		for( int j=0; j<gi->h+gi->shmax-1; j++ ) {
			val[i][j] = new float [gi->w+gi->swmax-1];
			for( int k=0; k<gi->w+gi->swmax-1; k++ ) {
				val[i][j][k] = obj.val[i][j][k];
			}
		}
	}

}

PastInfo::~PastInfo() {
	for( int i=0; i<gi->stamp->N(); i++ ) {
		for( int j=0; j<gi->h+gi->shmax-1; j++ ) {
			delete[] val[i][j];
		}
		delete[] val[i];
	}
	delete[] val;
}

float PastInfo::GetVal( Move m ) {
	if( m.x+gi->swmax-1 < 0 || m.y+gi->shmax-1 < 0 ) return 0;
	if( m.x >= gi->w || m.y >= gi->h ) return 0;
	return val[m.stamp][m.y+gi->shmax-1][m.x+gi->swmax-1] ;
}

void PastInfo::SetVal( Move m, float v ) {
	if( m.x+gi->swmax-1 < 0 || m.y+gi->shmax-1 < 0 ) return ;
	if( m.x >= gi->w || m.y >= gi->h ) return ;
	val[m.stamp][m.y+gi->shmax-1][m.x+gi->swmax-1] = v;
}

void PastInfo::DeletePart( Move m ) {
	//test_out();
	int i,j,k;
	for( i=0; i<gi->stamp->N(); i++ ) {
		for( j = m.y - gi->PointStampImg(i)->h + 1 ;
			 j < m.y + gi->PointStampImg(m.stamp)->h ; j++ )
		{
			for( k = m.x - gi->PointStampImg(i)->w + 1 ;
				 k < m.x + gi->PointStampImg(m.stamp)->w ; k++ )
			{
				if( -gi->shmax < j &&  j< gi->h && -gi->swmax < k && k < gi->w )
					val[i][j+gi->shmax-1][k+gi->swmax-1] = NONE;
			}
		}
	}
	//test_out();
}

void PastInfo::test_out() {
	cout << endl;
	for( int i=0; i<gi->stamp->N(); i++ ) {
		for( int j=0; j<gi->h+gi->shmax-1; j++ ) {
			for( int k=0; k<gi->w+gi->swmax-1; k++ ) {
				if( val[i][j][k]==NONE )
					printf("  -");
				else
					printf("%3d",(int)val[i][j][k]);
			}
			cout << endl;
		}
		cout << endl;
	}
	
}

