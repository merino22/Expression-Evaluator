#ifndef VALIDATIONS_H
#define VALIDATIONS_H

#include <iostream>
#include <string>
#include <string.h>

using namespace std;

class Validations
{
public: 
	bool checkParenthesis(string);
	bool checkOperatorRules(string);
	bool checkDecimalPoints(string);
	bool checkInvalidChars(string);
	bool checkInvalidDenominator(string);
	bool checkForPi(string);
	string removeSpaces(string);
};
#endif