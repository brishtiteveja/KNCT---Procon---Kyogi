// stdafx.cpp : 標準インクルード kyogi_v2.pch のみを
// 含むソース ファイルは、プリコンパイル済みヘッダーになります。
// stdafx.obj にはプリコンパイル済み型情報が含まれます。

#include "stdafx.h"

// TODO: このファイルではなく、STDAFX.H で必要な
// 追加ヘッダーを参照してください。


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