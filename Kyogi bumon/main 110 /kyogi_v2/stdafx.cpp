// stdafx.cpp : �W���C���N���[�h kyogi_v2.pch �݂̂�
// �܂ރ\�[�X �t�@�C���́A�v���R���p�C���ς݃w�b�_�[�ɂȂ�܂��B
// stdafx.obj �ɂ̓v���R���p�C���ς݌^��񂪊܂܂�܂��B

#include "stdafx.h"

// TODO: ���̃t�@�C���ł͂Ȃ��ASTDAFX.H �ŕK�v��
// �ǉ��w�b�_�[���Q�Ƃ��Ă��������B


void myopen( ifstream & ifs, string fname ){
	int i;
	i=0;
	do{
		i++;
		if( i>50 ) {
			cout << "error open " << fname << endl;
			getchar(); return;
		}
		ifs.open(fname);
	} while( ifs.bad() );

}

void myopen( ofstream & ofs, string fname ){
	int i;
	i=0;
	do{
		i++;
		if( i>50 ) {
			cout << "error open " << fname << endl;
			getchar(); return;
		}
		ofs.open(fname);
	} while( ofs.bad() );
}