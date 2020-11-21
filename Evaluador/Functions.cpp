#include "Functions.h"
#include <list>
#include <vector>
#include <stack>

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

int Functions::operator^(const int& num)
{
    Functions temp(*this);
    int res = 0;
    res = pow((*this).x, num);
    return res;
}

int Functions::power(int num1, int num2)
{
    return pow(num1, num2);
}

void Functions::toPostfix(string exp)
{
    string result = "";
    list<string> results;
    list<string> operators;
    stack<int> operatorsx;

    for (int i = 0; i < exp.length(); i++)
    {
        
        if (i == 0 && exp.at(i) == '-')
        {
            result += exp.at(i);
        }
        else if (exp.at(i) == '-' && exp.at(i - 1) == '(')
        {
            result += exp.at(i);
        }
        else if (isdigit(exp.at(i)))
        {
            result += exp.at(i);
            if (i + 1 <= exp.length()-1 && !isdigit(exp.at(i + 1)))
            {
                result += ',';
            }
            
        }
        else if (exp.at(i) == ')')
        {
            list<string>::iterator it;
            list<string>::iterator its;
            //result += ',';
            for (it = operators.begin(); it != operators.end();)
            {
                //cout << "Hello";
                if (*it != "(")
                {
                    result += *it + ',';
                    /*
                    if (result.at(result.length()-1) != ',')
                    {
                        result += ',';
                    }
                    */
                    it = operators.erase(it);
                }
                else if(*it == "(")
                {
                    //result += *it + ',';
                    it = operators.erase(it);
                    break;
                }
            }
            cout << "->Loop break<-";
        }
        else 
        {
            //result += ',';
            string pass(1, exp.at(i));
            operators.push_front(pass);
        }
    }
    if (!operators.empty())
    {
        //operators.pop_front();
        if (result.at(result.length() - 1) != ',')
        {
            result += ',';
        }
        
        list<string>::iterator it;
        for (it = operators.begin(); it != operators.end();)
        {
            if (operators.size() == 1)
            {
                result += *it;
            }
            else
            {
                result += *it;
                result += ",";
            }
            
            it = operators.erase(it);
        }
    }
    cout << "\nPostFix Result: " << result;
}
