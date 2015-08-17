#ifndef _GAMEUI_H
#define _GAMEUI_H

#include<iostream>
#include<string>

using std::cout;
using std::endl;
using std::string;

struct Blocks
{
	string data;
	char symbol;
	char ch;
};

void printBlockText(const Blocks& txt);
void numbers(Blocks& txt, char sym, char ch = 178);
void printscore();

#endif