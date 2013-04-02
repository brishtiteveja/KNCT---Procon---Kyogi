#include "stdafx.h"
#include "param.h"
#include "image.h"
#include "info.h"
#include "func.h"
#include "probability_map.h"

//コンストラクタ
ProbMap::ProbMap( GameInfo* gameinfo ){
	int i,j,k;
	gi=gameinfo;

	//領域確保
	this->Map = new HProb** [gi->h + 128];
	this->Map += 128;
	for(i=-128; i<gi->h; i++){
		this->Map[i] = new HProb* [gi->w + 128];
		this->Map[i] += 128;
		for(j=-128; j<gi->w; j++){
			this->Map[i][j] = new HProb [gi->stamp->N()];
		}
	}

	//確率初期化
	//今後ここにアルゴリズムを追加
	for(i=-128; i<gi->h; i++) {
		for(j=-128; j<gi->w; j++) {
			for(k=0; k<gi->stamp->N(); k++) {
				this->Map[i][j][k].probability = 1.0;
			}
		}
	}

	//倍率初期化
	this->mag=1;
}

//デストラクタ
ProbMap::~ProbMap(){
	for(int i=-128; i<gi->h; i++) {
		for(int j=-128; j<gi->w; j++) {
			delete[] this->Map[i][j];
		}
		this->Map[i]-=128;
		delete[] this->Map[i];
	}
	this->Map-=128;
	delete[] this->Map;
}

//平均確率設定：timeで指定した時間で１手が終わるようにする
void ProbMap::SetMag( float time ) {
	mag = ( (float)89000000 * time ) / ( trial_calc(gi) );
	Adjust();
}

//平均値計算
float ProbMap::average() {
	int i,j,k,n=0;
	float sum=0,ave;
	for(i=-128; i<gi->h; i++) {
		for(j=-128; j<gi->w; j++) {
			for(k=0; k<gi->stamp->N(); k++) {
				sum += this->Map[i][j][k].probability ;
				n++;
			}
		}
	}
	return sum/n;
}

//確率値
float ProbMap::Prob( Move m ){
	//cout << "Get ProbMap[" << m.y << "," << m.x << "," << m.stamp << "]=" << Map[m.y][m.x][m.stamp].probability << endl ;
	return this->Map[m.y][m.x][m.stamp].probability;
}

//確率値にxをかける
void ProbMap::MultiProb( Move m, float x ){
	//cout << "ProbMap[" << m.y << "," << m.x << "," << m.stamp << "]=" << Map[m.y][m.x][m.stamp].probability << "  =>  " ;
	this->Map[m.y][m.x][m.stamp].probability *= x;
	//cout << /*"ProbMap[" << m.y << "," << m.x << "," << m.stamp << "]=" <<*/ Map[m.y][m.x][m.stamp].probability << endl ;
}

//確率調整
void ProbMap::Adjust(){
	int i,j,k,n=0;
	float sum=0,ave,adj;

	//平均値計算
	for(i=-128; i<gi->h; i++) {
		for(j=-128; j<gi->w; j++) {
			for(k=0; k<gi->stamp->N(); k++) {
				if( Map[i][j][k].probability > 1 ) Map[i][j][k].probability = 1;
				if( Map[i][j][k].probability < 0 ) Map[i][j][k].probability = 0;
				Map[i][j][k].probability += 0.0005;
				sum += this->Map[i][j][k].probability ;
				n++;
			}
		}
	}
	ave = sum/n;

	//調整
	adj = ave / mag;

	for(i=-128; i<gi->h; i++) {
		for(j=-128; j<gi->w; j++) {
			for(k=0; k<gi->stamp->N(); k++) {
				this->Map[i][j][k].probability/= adj;
			}
		}
	}
}

