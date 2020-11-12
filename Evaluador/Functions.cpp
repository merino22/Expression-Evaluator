#include "Functions.h"
#include <list>
#include <vector>

bool Functions::checkParenthesis(string exp)
{
    int leftPar = 0, rightPar = 0;
    for (int i = 0; i < exp.length(); i++)
    {
        if (exp.at(i) == '(') {
            leftPar++;
        }
        else if (exp.at(i) == ')') {
            rightPar++;
        }
    }
    if (leftPar != rightPar) {
        return false;
    }
    return true;
}

bool Functions::checkOperatorRules(string exp)
{
    for (int i = 0; i < exp.length(); i++)
    {
        if (exp.at(0) == '+' || exp.at(0) == '*' || exp.at(0) == '/' || exp.at(0) == '%' || exp.at(0) == '^')
        {
            return false;
        }
        else if (exp.at(0) == '-')
        {
            if (exp.length() > 1 && isdigit(exp.at(1)))
            {
                return true;
            }
            return false;
        }

        if (exp.at(i) == '+' || exp.at(i) == '-' || exp.at(i) == '*' || exp.at(i) == '/' || exp.at(i) == '%' || exp.at(i) == '^')
        {
            if (exp.at(i) == exp.at(exp.length()-1))
            {
                return false;
            }
            if (exp.at(i + 1) == ')')
            {
                return false;
            }
            if (exp.at(i - 1) == '(')
            {
                return false;
            }
        }
    }
    return true;
}

string Functions::removeSpaces(string exp)
{
    string refactoredExp = "";
    for (int i = 0; i < exp.length(); i++) 
    {
        if (exp.at(i) != ' ')
        {
            refactoredExp += exp.at(i);
        }
    }
    return refactoredExp;
}

void Functions::toPostfix(string exp)
{
    string result = "";
    list<string> operators;

    for (int i = 0; i < exp.length(); i++)
    {
        if (isdigit(exp.at(i)))
        {
            result += exp.at(i);
            result += ',';
        }
        else if (exp.at(i) == ')')
        {
            list<string>::iterator it;
            list<string>::iterator its;
            for (it = operators.begin(); it != operators.end();)
            {
                //cout << "Hello";
                if (*it != "(")
                {
                    result += *it + ',';
                    it = operators.erase(it);
                }
                else if(*it == "(")
                {
                    //result += *it + ',';
                    it = operators.erase(it);
                    break;
                }
            }
            cout << "Loope break<-";
        }
        else 
        {
            string pass(1, exp.at(i));
            operators.push_front(pass);
        }
    }
    if (!operators.empty())
    {
        list<string>::iterator it;
        for (it = operators.begin(); it != operators.end();)
        {
            result += *it;
            result += ",";
            it = operators.erase(it);
        }
    }
}
