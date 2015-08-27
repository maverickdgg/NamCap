#ifndef _GAMEUI_H
#define _GAMEUI_H

#include<iostream>
#include<fstream>
#include<string>
#include"map.h"

using std::cout;
using std::endl;
using std::string;
using std::getline;
using std::ifstream;

short readfile(short sMapInUse[][38],string txt);
short readExactFile(short sMapInUse[][15],string txt);
void insertmap(PMAP sMap);
void printExactFile(short sMap[21][15]);
//void insertmap1(short** sMap);
#endif