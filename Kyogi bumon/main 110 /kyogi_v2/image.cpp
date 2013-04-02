#include "stdafx.h"
#include "image.h"


Image::Image(int width,int height, Image* m, vector<unsigned short int> * _precom){
	mask=m;
	precom = _precom;
	w=width; h=height;
	PGw = (w-1)/32+2; //stampimageを作る時を考慮し、１個余分に
	img = new PG32 *[h];
	for(int i=0; i<h; i++){
		img[i]= new PG32[PGw];
		for(int j=0; j<PGw; j++)
		img[i][j]=0;
	}
}



//コピーコンストラクタ
Image::Image(const Image &obj){
	mask=obj.mask;
	precom = obj.precom;
	w=obj.w; h=obj.h; PGw=obj.PGw;
	img= new PG32*[h];
	for(int i=0;i<h;i++){
		img[i]=new PG32[w];
		for(int j=0;j<PGw;j++)
			img[i][j]=obj.img[i][j];
	}
}

//XOR演算を行うコピーコンストラクタ
Image::Image(const Image &obj1, const Image &obj2){
	mask=obj1.mask;
	precom = obj1.precom;
	w=obj1.w; h=obj1.h; PGw=obj1.PGw;
	img= new PG32*[h];
	for(int i=0;i<h;i++){
		img[i]=new PG32[w];
		for(int j=0;j<PGw;j++)
			img[i][j]=obj1.img[i][j] ^ obj2.img[i][j];
	}
}

void Image::getimage(ifstream& fs){
	int i,j,k; 
	string line;
	for(i=0;i<h;i++){
		getline(fs,line);
		for(j=0;j<w;j++){
			SetPixel(j,i,(char)(line[j]-'0'));
		}
	}
}

void Image::outimage(ofstream& fs) {
	int i,j,k;
	for(i=0;i<h;i++){
		for(j=0;j<w;j++){
			fs << (int)( GetPixel(j,i) );
			
		}
		fs << endl;
	}
}

bool Image::is1px(){
	if(w==1 && h==1 && GetPixel(0,0)==1) return true;
	return false;
}

Image::~Image(){
	for(int i=0; i<h; i++)
		delete[] img[i];
	delete[] img;
}

//test
void Image::test_out(){
	int i,j;
	for(i=0;i<h;i++){
		for(j=0;j<w;j++){
			if(GetPixel(j,i)) cout << "■";
			else			cout << "・";
		}
		cout << endl;
	}
}

//中間出力作成
void Image::middle_out( int tesu, int dis ){
	ofstream ofs;
	do{
		ofs.open( "C:\\kyogi\\m_out.txt");
	}while(!ofs);
	ofs << tesu << endl;	//手数
	ofs << dis << endl;		//不一致
	ofs << this->w << endl;
	ofs << this->h << endl;
	this->outimage(ofs);
	
	ofs.close();
}

void Image::SetPixel(int x, int y, char val) {
	set_b( img[y][x/32], x%32, val );
}
char Image::GetPixel(int x, int y) {
	return get_b( img[y][x/32], x%32 );
}

int Image::Count(){
	int x=0;
	for(int i=0;i<h;i++){
		for(int j=0;j<PGw;j++)
			x += count_b( img[i][j] );
	}
	return x;
}

PG32 Image::GetPG(int x,int y) {
	return img[y][x];
}

unsigned long long Image::csum() {
	unsigned long x=0;
	for(int i=0;i<h;i++){
		for(int j=0;j<PGw;j++){
			x += (i*23+j*37)*img[i][j];
		}
	}
	return x;
}
void Image::MakeCumulative(){
	int i ,j;
	ruiseki.resize(h+1);
	
	for(i = 0 ;i<= h ;i++){
		ruiseki[i].resize(w+1);
	}

	for(i=0;i<=h;i++)
		ruiseki[i][0]=0;
	for(i=0;i<=w;i++)
		ruiseki[0][w]=0;


	for(i = 1 ; i <= h ;i++){
		for(j = 1 ;j <= w ; j++){
            
				ruiseki[i][j] = GetPixel(j-1,i-1) + ruiseki[i - 1][j] + ruiseki[i][j-1] - ruiseki[i-1][j-1];
			/*else if(i == 0 && j == 0)
				continue;
			else if( j == 0)
				ruiseki[i][j] = GetPixel(j,i) + ruiseki[i - 1][j];
			else if( i == 0)
				ruiseki[i][j] = GetPixel(j,i) + ruiseki[i][j-1];*/
			
		}
	}
    
}

int Image::CalcBlack(int x, int y, int xran, int yran) {
	if( x<1 ) x=0;
	if( y<1 ) y=0;
	if( xran>w ) xran = w;
	if( yran>h ) yran = h;
	
	return ruiseki[yran][xran] - ruiseki[y][xran] - ruiseki[yran][x] + ruiseki[y][x];
}


//private:

PG32 Image::bit_p(int k) {
	return (PG32)(pow(2.0,k));
}

void Image::set_b(PG32& d, int k, char val) {
	int mask = bit_p(k);
	int x = d & mask;
	if( x==0 && val==1 )
		d += mask;
	else if( x==1 && val==0 )
		d -= mask;
}

char Image::get_b(PG32& s, int k) {
	int mask =bit_p(k);
	int x = s & mask;
	if( x==0 )	return 0;
	else		return 1;
}

int Image::count_b(PG32 s) {
	int x = (int)(s&0x0000FFFF);
	int x1 = (*precom)[x] ;
	int y = (int)(s/65536); 
	int y1 = (*precom)[y] ;
	return x1+y1;
}



char Image::r_shift_b(PG32 & dest, char lsb) {
	char x = get_b( dest, 31 );
	dest *= 2;
	set_b( dest, 0, lsb );
	return x;
}


void Image::r_shift(){
	char tmp;
	for(int i=0;i<h;i++){
		tmp=0;
		for(int j=0;j<PGw;j++)
			tmp=r_shift_b(img[i][j],tmp);
	}
}

int Image::_stampTry( Image *st, int PGx, int y ) {
	int i,j,val=0;
	for( i=0; i<st->h; i++ ) {
		for( j=0; j<(st->w-1)/32+2; j++ ) {
			if( is_range(PGx+j,y+i) ) {
				PG32 tmp = img[i+y][j+PGx];
				tmp ^= st->GetPG(j,i);
				tmp &= mask->GetPG(j+PGx,i+y);
				val += count_b(img[i+y][j+PGx]) - count_b(tmp);
				i=i;
			}	
		}
	}
	return val;
}

void Image::_stampDo( Image *st, int PGx, int y ) {
	int i,j;
	for( i=0; i<st->h; i++ ) {
		for( j=0; j<(st->w-1)/32+2; j++ )  {
			if( is_range(PGx+j,y+i) ) {
				img[i+y][j+PGx] ^= (st->GetPG(j,i) & mask->GetPG(j+PGx,i+y));
			}	
		}
	}
}

bool Image::is_range( int PGx, int y ) {
	if( 0<=PGx && PGx<(this->w-1)/32+2 && 0<=y && y<this->h )
		return true;
	else return false;
}


//////////////////////////////////////////////////////////////////////////////////////

// SImage

SImage::SImage( Image &obj ){
	w=obj.w; h=obj.h; 
	simg[0] = new Image( obj );
	for( int i=1; i<32; i++ ){
		simg[i] = new Image( (*simg[i-1]) );
		simg[i]->r_shift();
	}
}






//////////////////////////////////////////////////////////////////////////////////////

// スタンプ関数

int StampTry( Image* d, SImage *st, int x, int y ) {
	x += 128;
	Image *img = st->simg[x%32];
	int PGx = x/32;
	x -= 128;  PGx -= 4;
	return d->_stampTry( img, PGx, y );
}

void StampDo( Image* d, SImage *st, int x, int y ) {
	x += 128;
	Image *img = st->simg[x%32];
	int PGx = x/32;
	x -= 128;  PGx -= 4;
	d->_stampDo( img, PGx, y );
}

	

