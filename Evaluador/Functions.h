#pragma once
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <string>
#include <string.h>
#include "PrecedenceObj.h"

using namespace std;

class [[nodiscard]]Functions //---> VC 17
{
public:
	Functions() {}

	bool checkParenthesis(string); 
	bool checkOperatorRules(string);
	bool checkDecimalPoints(string);
	bool checkInvalidChars(string);
	bool checkInvalidDenominator(string);
	string removeSpaces(string);

	inline int operator^(const int& num); //---> VC 17
	inline int power(int, int)noexcept(false); //---> VC 17

	string toPostfix(string);
	void postfixToResult(string);
};
#endif

