#pragma once
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <string>
#include <string.h>

using namespace std;

class Functions
{
private:
public:
	bool checkParenthesis(string);
	bool checkOperatorRules(string);
	string removeSpaces(string);
	void toPostfix(string);
};
#endif

