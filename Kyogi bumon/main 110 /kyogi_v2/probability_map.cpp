#include "stdafx.h"
#include "param.h"
#include "image.h"
#include "info.h"
#include "func.h"
#include "probability_map.h"

//�R���X�g���N�^
ProbMap::ProbMap( GameInfo* gameinfo ){
	int i,j,k;
	gi=gameinfo;

	//�̈�m��
	this->Map = new HProb** [gi->h + 128];
	this->Map += 128;
	for(i=-128; i<gi->h; i++){
		this->Map[i] = new HProb* [gi->w + 128];
		this->Map[i] += 128;
		for(j=-128; j<gi->w; j++){
			this->Map[i][j] = new HProb [gi->stamp->N()];
		}
	}

	//�m��������
	//���ケ���ɃA���S���Y����ǉ�
	for(i=-128; i<gi->h; i++) {
		for(j=-128; j<gi->w; j++) {
			for(k=0; k<gi->stamp->N(); k++) {
				this->Map[i][j][k].probability = 1.0;
			}
		}
	}

	//�{��������
	this->mag=1;
}

//�f�X�g���N�^
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

//���ϊm���ݒ�Ftime�Ŏw�肵�����ԂłP�肪�I���悤�ɂ���
void ProbMap::SetMag( float time ) {
	mag = ( (float)89000000 * time ) / ( trial_calc(gi) );
	Adjust();
}

//���ϒl�v�Z
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

//�m���l
float ProbMap::Prob( Move m ){
	//cout << "Get ProbMap[" << m.y << "," << m.x << "," << m.stamp << "]=" << Map[m.y][m.x][m.stamp].probability << endl ;
	return this->Map[m.y][m.x][m.stamp].probability;
}

//�m���l��x��������
void ProbMap::MultiProb( Move m, float x ){
	//cout << "ProbMap[" << m.y << "," << m.x << "," << m.stamp << "]=" << Map[m.y][m.x][m.stamp].probability << "  =>  " ;
	this->Map[m.y][m.x][m.stamp].probability *= x;
	//cout << /*"ProbMap[" << m.y << "," << m.x << "," << m.stamp << "]=" <<*/ Map[m.y][m.x][m.stamp].probability << endl ;
}

//�m������
void ProbMap::Adjust(){
	int i,j,k,n=0;
	float sum=0,ave,adj;

	//���ϒl�v�Z
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

	//����
	adj = ave / mag;

	for(i=-128; i<gi->h; i++) {
		for(j=-128; j<gi->w; j++) {
			for(k=0; k<gi->stamp->N(); k++) {
				this->Map[i][j][k].probability/= adj;
			}
		}
	}
}

