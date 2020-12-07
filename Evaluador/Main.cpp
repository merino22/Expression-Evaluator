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
		//cin.getline(expression, sizeof(expression));
		getline(cin, expression);
		static_assert(true,"Wrong character");
		if (expression == "quit")
		{
			break;
		}
		//string usable = " " + expression + " ";
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
		

		
		/*for (int i = 0; i < expression.length(); i++) {
			int pos = expression.at(i);
			string res = "";
			if (isdigit(expression.at(i))) {
				res += pos;
			}
			else{
				if (res != " ")
				{
					expPostFija.push_back(res);
					res = "";
				}
				else {
					cout << "ERROR: Syntax error";
				}
				
			}
		}*/

		/*for (int i = 0; i < expression.length(); i++)
		{
			if (expression.at(i) == '(') {
				leftPar++;
			}
			else if (expression.at(i) == ')') {
				rightPar++;
			}
		}

		if (leftPar != rightPar) {
			cout << "\nError: Syntax error, missing Parenthesis";
		}*/

		/*if (!std::isdigit(expression.at(expression.length()-1)))
		{
			cout << "\nERROR: Syntax error at end of line, invalid character or incomplete expression -> " << expression.at(expression.length()-1);
		}*/

		cout << "\n\n";
	}
	
}