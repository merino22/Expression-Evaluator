#pragma once
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <string>
#include <string.h>
#include "PrecedenceObj.h"

using namespace std;

class Functions
{
private:
public:
	Functions() {}
	int x;
	Functions(int _x) : x(_x) {}
	bool checkParenthesis(string);
	bool checkOperatorRules(string);
	bool checkDecimalPoints(string);
	string removeSpaces(string);
	int operator^(const int& num);
	int power(int, int);
	void toPostfix(string);
};
#endif

