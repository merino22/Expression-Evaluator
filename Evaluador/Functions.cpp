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

bool Functions::checkDecimalPoints(string exp)
{
    for (int i = 0; i < exp.length(); i++)
    {
        if (i != exp.length()-1)
        {
            if (exp.at(i) == '.' && !isdigit(exp.at(i + 1)))
            {
                return false;
            }
        }
    }
    return true;
}

void Functions::postfixToResult(string exp)
{
    int valueCount = 1;
    /*for (int i = 0; i < exp.length(); i++)
    {
        if (exp.at(i) == ',')
        {
            valueCount++;
        }
    }*/
    vector<string> values;
    string temp = "";
    for (int i = 0; i < exp.length(); i++)
    {  
        if (exp.at(i) != ',')
        {
            temp += exp.at(i);
        }
        else
        {
            values.push_back(temp);
            temp = "";
        }

        if (i == exp.length() - 1)
        {
            values.push_back(temp);
        }
    }
    cout << "\n";
    for (auto& it : values)
    {
        cout << it << ',';
    }
    cout << "\n!Values are inside vector";
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

string Functions::toPostfix(string exp)
{
    string result = "";
    list<string> results;
    list<string> operators;
    stack<string> operatorsx;
    stack<precObj*>operatorsz;

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
        else if (isdigit(exp.at(i)) || exp.at(i) == '.')
        {
            result += exp.at(i);
            if (i + 1 <= exp.length()-1 && !isdigit(exp.at(i + 1)) && exp.at(i+1) != '.')
            {
                result += ',';
            }
            
        }
        else if (exp.at(i) == ')')
        {
            //list<string>::iterator it;
            //list<string>::iterator its;
            //result += ',';
            while (!operatorsz.empty())
            {
                if (operatorsz.top()->operatorC != '(')
                {
                    cout << operatorsz.top()->operatorC;
                    result += operatorsz.top()->operatorC;
                    result += ',';
                    operatorsz.pop();
                }
                else if (operatorsz.top()->operatorC == '(')
                {
                    operatorsz.pop();
                    break;
                }
                
            }
            
            cout << "->Loop break<-";
        }
        else 
        {
            string pass(1, exp.at(i));
            precObj* temp = nullptr;
            switch (exp.at(i))
            {
            case '(':
                temp = new precObj(0, '(');
                break;
            case '^':
                temp = new precObj(6, '^');
                break;
            case '*':
                temp = new precObj(5, '*');
                break;
            case '/':
                temp = new precObj(4, '/');
                break;
            case '%':
                temp = new precObj(3, '%');
                break;
            case '+':
                temp = new precObj(2, '+');
                break;
            case '-':
                temp = new precObj(1, '-');
                break;
            }

            if (operatorsz.empty())
            {
                operatorsz.push(temp);
               
            }
            else
            {
                while(!operatorsz.empty())
                {
                    if (operatorsz.top()->precedence > temp->precedence && temp->precedence != 0)
                    {
                        result += operatorsz.top()->operatorC;
                        result += ',';
                        operatorsz.pop();
                    }
                    else
                    {
                        operatorsz.push(temp);
                        temp = nullptr;
                        break;
                    }

                    if (temp != nullptr && !operatorsz.empty() && operatorsz.top()->precedence < temp->precedence)
                    {
                        operatorsz.push(temp);
                        break;
                    }

                    if (operatorsz.empty() && temp != nullptr)
                    {
                        operatorsz.push(temp);
                        temp = nullptr;
                        break;
                    }
                }
                
            }

            operatorsx.push(pass);
           // operatorsz.push(temp);
            //operators.push_front(pass);
        }
    }
    if (!operatorsz.empty())
    {
        if (result.at(result.length() - 1) != ',')
        {
            result += ',';
        }

        while (!operatorsz.empty())
        {
            if (operatorsz.size() == 1)
            {
                result += operatorsz.top()->operatorC;
            }
            else
            {
                result += operatorsz.top()->operatorC;
                result += ',';
            }
            operatorsz.pop();
        }
    }

    while (!operatorsz.empty())
    {
        cout << "\n\nOperator: " << operatorsz.top()->operatorC;
        cout << "\nPrecedence: " << operatorsz.top()->precedence;
        operatorsz.pop();
    }
    cout << "\nPostFix Result: " << result;
    return result;
}
