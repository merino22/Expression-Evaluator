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
public:
	Functions() {}
	int x;
	Functions(int _x) : x(_x) {}

	bool checkParenthesis(string);
	bool checkOperatorRules(string);
	bool checkDecimalPoints(string);
	bool checkInvalidChars(string);
	string removeSpaces(string);

	int operator^(const int& num);
	int power(int, int);

	string toPostfix(string);
	void postfixToResult(string);
};
#endif

