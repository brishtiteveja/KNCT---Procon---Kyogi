#include "stdafx.h"
#include "param.h"
#include "image.h"
#include "info.h"
#include "func.h"

void out_mega(float x) {
	cout << int(x/(float)1000000) << "." << int(x/(float)100000)%10 << int(x/(float)10000)%10 << " M";
}

//”äŠr‰ñ”ŠTŽZ
float trial_calc( GameInfo* gi ){
	float x=0, imgs=gi->w*gi->h;
	for( int i=0; i<gi->stamp->N(); i++ ) {
		SImage* sp=gi->PointStampImg(i);
		x += (sp->w * sp->h * imgs) * gi->stamp->sinf[i].use ;
	}
	cout << "”äŠr‰ñ”ŠTŽZ ";
	cout << int(x/1000000) << "." << int(x/100000)%10 << int(x/10000)%10 << "M" << endl;


	return x;
	//1•b‚ ‚½‚è‚Ì”äŠr‰ñ”‚Í–ñ 90*10^6 ‰ñ
}

int memorymaxc_calc( GameInfo* gi ){
	int i,j,k;
	int W = gi->w;
	int H = gi->h;
	float Mem = 1.8*pow(10.0,9.0);

	float I = (W/32+2)*H * 8;

	float Ps = 0;
	for( i=0; i<gi->stamp->N(); i++ ) {
		SImage * sp = gi->PointStampImg(i);
		Ps += ( (sp->w+gi->swmax) * (sp->h+gi->shmax) ) * 4;
	}
	Ps *= 4;

	float Nd = (float)W * (float)H * gi->stamp->N() * 50;

	float P = Mem / (I+Ps+Nd);
	/*float I = P * (W/32+2)*H * 8;

	float Ps = 0;
	for( i=0; i<gi->stamp->N(); i++ ) {
		SImage * sp = gi->PointStampImg(i);
		Ps += ( (sp->w+gi->swmax) * (sp->h+gi->shmax) ) * 4;
	}
	Ps *= P * 4;

	float Nd = P * (float)W * (float)H * gi->stamp->N() * 50;*/

	

	cout << "ƒpƒ‰ƒ[ƒ^ãŒÀŠTŽZ  ";
	/*cout << "Im=";		out_mega((float)I);		cout << "  ";
	cout << "Ps=";		out_mega((float)Ps);	cout << "  ";
	cout << "Nd=";		out_mega((float)Nd);	cout << "  ";
	cout << "Mem=";		out_mega((float)Mem);	cout << endl;*/
	cout << (int)P << endl;




	return (int)P;
	//1•b‚ ‚½‚è‚Ì”äŠr‰ñ”‚Í–ñ 90*10^6 ‰ñ
}




//Žw’è‚µ‚½Šm—¦‚Åtrue‚ð•Ô‚·ŠÖ”
bool probability( float p ) {
	if( p<=0 ) return false;
	if( p>=1 ) return true;
	float r=( rand()%10000 ) / 10000.0;
	if( p>r ) return true;
	else return false;
}

