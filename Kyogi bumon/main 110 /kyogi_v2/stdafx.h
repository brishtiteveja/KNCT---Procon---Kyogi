// stdafx.h : �W���̃V�X�e�� �C���N���[�h �t�@�C���̃C���N���[�h �t�@�C���A�܂���
// �Q�Ɖ񐔂������A�����܂�ύX����Ȃ��A�v���W�F�N�g��p�̃C���N���[�h �t�@�C��
// ���L�q���܂��B
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

// TODO: �v���O�����ɕK�v�Ȓǉ��w�b�_�[�������ŎQ�Ƃ��Ă��������B


void myopen( ifstream & ifs, string fname );
void myopen( ofstream & ofs, string fname );

//#define PROBLEM_PATH "\\\\192.168.1.89\\kyogi_public\\gameinfo\\problem.txt"
#define PROBLEM_PATH "C:\\kyogi_public\\gameinfo\\problem.txt"




/////////////////////////////////////////////////////////////////////////////////
// PC�ɂ���ĕύX

#define DEFAULT_SEARCH_MODE		0
							// 0:�S  1:�ߖT

//#define ANSWER_PATH "\\\\192.168.1.89\\kyogi_public\\gameinfo\\answer2.txt"
//																//  1 or 2

#define ANSWER_PATH "C:\\kyogi_public\\gameinfo\\answer1.txt"
												//  1 or 2
