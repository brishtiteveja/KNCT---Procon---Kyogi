// kyogi_v2.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"

#include "param.h"


#include "image.h"
#include "info.h"

#include "tree.h"
#include "sequential.h"
#include "func.h"

void (*p[32]) (GameInfo *) = { 
	//線形探索
	sequential_main,	// 0  : 逐次探索(全面)
	sequential2_main,	// 1  : 逐次探索(分割)
	sequential3_main,	// 2  : 逐次探索(ランダム高速)
	NULL,//sequential4_main,	// 3  : 逐次探索(全面・同時適用)
	NULL,				// 4
	NULL,				// 5
	NULL,				// 6
	NULL,				// 7
	//幅優先探索
	engine_tree,		// 8  : 幅優先と枝刈り
	engine_tree,		// 9  : 幅優先と枝刈り(自動パラメータ)
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

	cout << "kyogi_main thread 1222_23 PARAM自動化" << endl;
	cout << "注：PCによってパラメータ(stdfx.cppの最下部)の変更必要" << endl;

	//do{
	//	cout << "0 本選用 or 1 練習問題 : ";
	//	cin >> mode;
	//}while( !(mode==0 || mode==1) );

	//cout << "コマンド固有記号";
	//cin >> cmdn;
	//gi.cmd_fname = "C:\\kyogi\\cmd" + cmdn + ".txt";
	//
	//if( mode == 0 ){
	//	gi.reset_command();
	//	while( 1 ) {
	//		cout << "cmd_start待ち";
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
	//		//メインループ
	//		gi.alno=gi.cmd_alno;;
	//		(*p[gi.alno])(&gi);
	//	}
	//}
	//else if( mode == 1 ) {
		//cout << "問題番号";
		//cin >> num;

		cout << "ANSWER_PATH : " << ANSWER_PATH << endl;

		gi.search_mode = DEFAULT_SEARCH_MODE;
		if( gi.search_mode == 0 ) {
			cout << "default 全探索" << endl;
		}
		else {
			cout << "default 近傍探索" << endl;
		}

		

		cout << "Push Enter to read problem";
		getchar();
		gi.cmd_fname = "C:\\kyogi\\cmd.txt";
		num="0";

		gi.readfile(PROBLEM_PATH);

		//cout << "思考ルーチン番号";
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

		//メインループ
		gi.alno=alno;
		(*p[alno])(&gi);

		time_t ft=time(NULL)-gi.t;
		std::cout << "time : " << (int)ft/60 << "min " << (int)ft%60 << "s";

		gi.OutAnswer();
	
		getchar();getchar();
	//}

	

	return 0;
}

