#include <iostream>
#include <string>
#include <string.h>
#include <iterator>
#include <list>
#include "Functions.h"

using namespace std;

int main() {
	auto expression = ""s;//---> VC 14
	Functions funcs;
	while (expression != "quit")
	{
		int x = 0;
		cout << "[Exp]>: ";
		getline(cin, expression);
		static_assert(true,"Wrong character");
		if (expression == "quit")
		{
			break;
		}
		if (funcs.checkParenthesis(expression) == true )
		{
			if (funcs.checkOperatorRules(expression) == true)
			{
				if (funcs.checkDecimalPoints(expression) == true)
				{
					if (funcs.checkInvalidChars(expression) == true)
					{
						string refactoredExp = funcs.removeSpaces(expression);
						cout << "Refactored Expression: " << refactoredExp;
						string postfixExpression = funcs.toPostfix(refactoredExp);
						funcs.postfixToResult(postfixExpression);
					}
					else
					{
						cout << "ERROR: Syntax Error, alphanumeric characters encountered.";
					}
				}
				else
				{
					cout << "ERROR: Syntax Error,  float value mismatch";
				}
			}
			else
			{
				cout << "ERROR: Syntax Error, operator mismatch";
			}
		}
		else {
			cout << "ERROR: Syntax Error, missing parenthesis.";
		}

		cout << "\n\n";
	}
	
}