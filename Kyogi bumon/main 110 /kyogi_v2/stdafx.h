// stdafx.h : 標準のシステム インクルード ファイルのインクルード ファイル、または
// 参照回数が多く、かつあまり変更されない、プロジェクト専用のインクルード ファイル
// を記述します。
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>
#include <tchar.h>
#include <time.h>

#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <Windows.h>


#include <boost/thread.hpp>
#include <boost/bind.hpp>

using namespace std;

// TODO: プログラムに必要な追加ヘッダーをここで参照してください。


void myopen( ifstream & ifs, string fname );
void myopen( ofstream & ofs, string fname );

//#define PROBLEM_PATH "\\\\192.168.1.89\\kyogi_public\\gameinfo\\problem.txt"
#define PROBLEM_PATH "C:\\kyogi_public\\gameinfo\\problem.txt"




/////////////////////////////////////////////////////////////////////////////////
// PCによって変更

#define DEFAULT_SEARCH_MODE		0
							// 0:全  1:近傍

//#define ANSWER_PATH "\\\\192.168.1.89\\kyogi_public\\gameinfo\\answer2.txt"
//																//  1 or 2

#define ANSWER_PATH "C:\\kyogi_public\\gameinfo\\answer1.txt"
												//  1 or 2
