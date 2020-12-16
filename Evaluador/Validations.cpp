#include "Validations.h"

bool Validations::checkParenthesis(string exp)noexcept(false)//---> VC 17
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

bool Validations::checkDecimalPoints(string exp)noexcept(false) //---> VC 17
{
    for (int i = 0; i < exp.length(); i++)
    {
        if (i != exp.length() - 1)
        {
            if (exp.at(i) == '.' && !isdigit(exp.at(i + 1)))
            {
                return false;
            }
        }
    }
    return true;
}

bool Validations::checkInvalidDenominator(string exp)noexcept(false)
{
    for (int i = 0; i < exp.length(); i++)
    {
        if (exp.at(i) == '/' || exp.at(i) == '%')
        {
            if (exp.at(i + 1) == '0')
            {
                return false;
            }
        }
    }
    return true;
}

bool Validations::checkInvalidChars(string exp)noexcept(false)//---> VC 17
{
    for (int i = 0; i < exp.length(); i++)
    {
        if (exp.at(i) != 'p' && exp.at(i) != 'i' && exp.at(i) != 'e' && isalpha(exp.at(i)))
        {
            return false;
        }
        if (i != exp.length() - 1 && exp.at(i) == 'p' && exp.at(i + 1) == 'i')
        {
            return true;
        }
    }
    return true;
}

bool Validations::checkOperatorRules(string exp) noexcept(false)//---> VC 17
{
    for (int i = 0; i < exp.length(); i++)
    {
        if (exp.at(0) == '+' || exp.at(0) == '*' || exp.at(0) == '/' || exp.at(0) == '%' || exp.at(0) == '^')
        {
            return false;
        }

        if (exp.at(i) == '+' || exp.at(i) == '*' || exp.at(i) == '/' || exp.at(i) == '%' || exp.at(i) == '^')
        {
            if (exp.at(i + 1) == '+' || exp.at(i + 1) == '-' || exp.at(i + 1) == '*' || exp.at(i + 1) == '/' || exp.at(i + 1) == '%' || exp.at(i + 1) == '^')
            {
                return false;
            }
        }

        if (exp.at(i) == '-')
        {
            if (exp.at(i + 1) == '+'  || exp.at(i + 1) == '*' || exp.at(i + 1) == '/' || exp.at(i + 1) == '%' || exp.at(i + 1) == '^')
            {
                return false;
            }
        }

        if (exp.at(0) == '-')
        {
            if (exp.length() > 1 && isdigit(exp.at(1)))
            {
                return true;
            }
            else if (exp.length() > 2 && exp.at(i + 1) == 'p' && exp.at(i + 2) == 'i')
            {
                return true;
            }
            else if (exp.length() > 1 && exp.at(i + 1) == 'e')
            {
                return true;
            }
            return false;
        }
        if (exp.at(i) == '+' || exp.at(i) == '-' || exp.at(i) == '*' || exp.at(i) == '/' || exp.at(i) == '%' || exp.at(i) == '^')
        {
            if (exp.at(i) == exp.at(exp.length() - 1))
            {
                return false;
            }
            if (exp.at(i + 1) == ')')
            {
                return false;
            }
            if (exp.at(i - 1) == '(' && exp.at(i) != '-')
            {
                return false;
            }
        }
    }
    return true;
}


string Validations::removeSpaces(string exp)noexcept(false)//---> VC 17
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