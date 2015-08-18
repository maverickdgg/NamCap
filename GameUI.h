#ifndef _GAMEUI_H
#define _GAMEUI_H

#include<iostream>
#include<fstream>
#include<string>

using std::cout;
using std::endl;
using std::string;
using std::getline;
using std::ifstream;

//void printscore();
void level();
short readfile(short sMapInUse[][38]);
void insertmap(short sMap[21][38]);
//void insertmap1(short** sMap);
#endif