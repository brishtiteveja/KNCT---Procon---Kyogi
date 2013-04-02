// kyogi_v2.cpp : �R���\�[�� �A�v���P�[�V�����̃G���g�� �|�C���g���`���܂��B
//

#include "stdafx.h"

#include "param.h"


#include "image.h"
#include "info.h"

#include "tree.h"
#include "sequential.h"
#include "func.h"

void (*p[32]) (GameInfo *) = { 
	//���`�T��
	sequential_main,	// 0  : �����T��(�S��)
	sequential2_main,	// 1  : �����T��(����)
	sequential3_main,	// 2  : �����T��(�����_������)
	NULL,//sequential4_main,	// 3  : �����T��(�S�ʁE�����K�p)
	NULL,				// 4
	NULL,				// 5
	NULL,				// 6
	NULL,				// 7
	//���D��T��
	engine_tree,		// 8  : ���D��Ǝ}����
	engine_tree,		// 9  : ���D��Ǝ}����(�����p�����[�^)
	NULL,				// 10
	NULL,				// 11
	NULL,				// 12
	NULL,				// 13
	NULL,				// 14
	NULL,				// 15
	//
	NULL,				// 16
	NULL,				// 17
	NULL,				// 18
	NULL,				// 19
	NULL,				// 20
	NULL,				// 21
	NULL,				// 22
	NULL,				// 23
	//
	NULL,				// 24
	NULL,				// 25
	NULL,				// 26
	NULL,				// 27
	NULL,				// 28
	NULL,				// 29
	NULL,				// 30
	NULL,				// 31

};


int _tmain(int argc, _TCHAR* argv[])
{
	GameInfo gi;
	string fname,num,alno_s,cmdn;
	int alno,mode;

	cout << "kyogi_main thread 1222_23 PARAM������" << endl;
	cout << "���FPC�ɂ���ăp�����[�^(stdfx.cpp�̍ŉ���)�̕ύX�K�v" << endl;

	//do{
	//	cout << "0 �{�I�p or 1 ���K��� : ";
	//	cin >> mode;
	//}while( !(mode==0 || mode==1) );

	//cout << "�R�}���h�ŗL�L��";
	//cin >> cmdn;
	//gi.cmd_fname = "C:\\kyogi\\cmd" + cmdn + ".txt";
	//
	//if( mode == 0 ){
	//	gi.reset_command();
	//	while( 1 ) {
	//		cout << "cmd_start�҂�";
	//		while( gi.cmd_start == 0 ) {
	//			cout << ".";
	//			Sleep(250);
	//			gi.read_command();
	//		}
	//		cout << endl;

	//		if( gi.cmd_start == 1 )
	//			gi.readfile("C:\\kyogi_public\\problem0.txt");
	//		else
	//			gi.readfile("C:\\kyogi_public\\problem1.txt");
	//		gi.cmd_start = 0;

	//		gi.t=time(NULL);
	//		cout << (int)(gi.shoki_discord->Count()/(double)(gi.h*gi.w)*100) << "% discord" << endl;
	//		//���C�����[�v
	//		gi.alno=gi.cmd_alno;;
	//		(*p[gi.alno])(&gi);
	//	}
	//}
	//else if( mode == 1 ) {
		//cout << "���ԍ�";
		//cin >> num;

		cout << "ANSWER_PATH : " << ANSWER_PATH << endl;

		gi.search_mode = DEFAULT_SEARCH_MODE;
		if( gi.search_mode == 0 ) {
			cout << "default �S�T��" << endl;
		}
		else {
			cout << "default �ߖT�T��" << endl;
		}

		

		cout << "Push Enter to read problem";
		getchar();
		gi.cmd_fname = "C:\\kyogi\\cmd.txt";
		num="0";

		gi.readfile(PROBLEM_PATH);

		//cout << "�v�l���[�`���ԍ�";
		//cin >> alno_s;\
		//alno=atoi(alno_s.c_str());
		alno = 8;
		if(p[alno]==NULL){
			cout << alno << ": Nothing is allocated in this number." << endl;
			getchar();
			return 0;
		}
	

		gi.t=time(NULL);
		cout << (int)(gi.shoki_discord->Count()/(double)(gi.h*gi.w)*100) << "% discord" << endl;

		//cout << "Set initial command." << endl;

		//���C�����[�v
		gi.alno=alno;
		(*p[alno])(&gi);

		time_t ft=time(NULL)-gi.t;
		std::cout << "time : " << (int)ft/60 << "min " << (int)ft%60 << "s";

		gi.OutAnswer();
	
		getchar();getchar();
	//}

	

	return 0;
}

