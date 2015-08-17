#ifndef _GAMEUI_H
#define _GAMEUI_H

#include<iostream>
#include<string>
#include<fstream>

using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::getline;

struct Blocks
{
	string data;
	char symbol;
	char ch;
};

void printBlockText(const Blocks& txt);
//void numbers(Blocks& txt, char sym, char ch = 178);
void numbers();
void printscore();

#endif