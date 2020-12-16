#include "Functions.h"
#include <list>
#include <vector>
#include <stack>
#include <sstream>

template <typename t> std::string type_name();

template<typename T> // ---> VC 14
constexpr T pi = T(3.141592653589793238462643383); // ---> VC 14

template<typename T>
constexpr T e = T(2.718281828); //---> VC 14

auto sum = [](auto x, auto y) {x = x + y; return x; }; //---> VC 14

static bool isFloatNumber(const std::string& string) noexcept(false) { //---> VC 17
    std::string::const_iterator it = string.begin();
    bool decimalPoint = false;
    int minSize = 0;
    if (string.size() > 0 && (string[0] == '-' || string[0] == '+')) {
        it++;
        minSize++;
    }
    while (it != string.end()) {
        if (*it == '.') {
            if (!decimalPoint) decimalPoint = true;
            else break;
        }
        else if (!std::isdigit(*it) && ((*it != 'f') || it + 1 != string.end() || !decimalPoint)) {
            break;
        }
        ++it;
    }
    return string.size() > minSize && it == string.end();
}


bool isFloat(string s) noexcept(false) {
    istringstream iss(s);
    [[maybe_unused]]float floatx; // ---> VC 17
    iss >> noskipws >> floatx;
    return iss && iss.eof();     // Result converted to bool
}

bool Functions::checkParenthesis(string exp)noexcept(false)//---> VC 17
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

bool Functions::checkOperatorRules(string exp) noexcept(false)//---> VC 17
{
    bool check = false;
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
                check = true;
            }
            else if (exp.length() > 2 && exp.at(i + 1) == 'p' && exp.at(i + 2) == 'i')
            {
                check = true;
            }
            else if (exp.length() > 1 && exp.at(i + 1) == 'e')
            {
                check = true;
            }
            return false;
        }

        if (exp.at(i) == '+' || exp.at(i) == '-' || exp.at(i) == '*' || exp.at(i) == '/' || exp.at(i) == '%' || exp.at(i) == '^')
        {
            if (exp.at(i + 1) == '+' || exp.at(i + 1) == '-' || exp.at(i + 1) == '*' || exp.at(i + 1) == '/' || exp.at(i + 1) == '%' || exp.at(i + 1) == '^')
            {
                return false;
            }
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
            if (exp.at(i - 1) == '(' && exp.at(i) != '-')
            {
                return false;
            }
        }
    }
    return true;
}

bool Functions::checkDecimalPoints(string exp)noexcept(false) //---> VC 17
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

bool Functions::checkInvalidDenominator(string exp)noexcept(false)
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

bool Functions::checkInvalidChars(string exp)noexcept(false)//---> VC 17
{
    for (int i = 0; i < exp.length(); i++)
    {
        if (exp.at(i) != 'p' && exp.at(i) != 'i' && exp.at(i) != 'e' && isalpha(exp.at(i)))
        {
            return false;
        }
        if (i != exp.length()-1 && exp.at(i) == 'p' && exp.at(i + 1) == 'i')
        {
            return true;
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

    vector<string>::iterator it;
    auto x = 0, y = 0;  // ---> VC 11
    auto dx = 0.0, dy = 0.0; // ---> VC 11
    auto result =0; // ---> VC 11
    auto dresult = 0.0;
    char operation;
    bool isFloatx = false;
    string dot = ".";
    for (it = values.begin(); it != values.end(); ++it)
    {
        
        if (*it == "*" || *it == "^" || *it == "/" || *it == "%" || *it == "+" || *it == "-")
        {
            
            operation = (*it).at(0);
            //it = values.erase(it);
            it = prev(it);
            if ((*it).find(".") != string::npos) // ---> VC 11
            {
                dy = stod(*it);
                it = prev(it);
                dx = stof(*it);
                isFloatx = true;
            }
            else
            {
                y = stoi(*it);
                it = prev(it);
                if ((*it).find(".") != string::npos) // ---> VC 11
                {
                    dx = stof(*it);
                    dy = y;
                    isFloatx = true;
                }
                else
                {
                    x = stoi(*it);
                }
            }
            
            it = values.erase(it);
            it = values.erase(it);

            if (isFloatx == false)
            {
                switch (operation)
                {
                case '^':
                    result = pow(x, y);
                    break;
                case '*':
                    result = x * y;
                    break;
                case '/':
                    if (y != 0)
                    {
                        result = x / y;
                    }
                    else
                    {
                        result = 0;
                    }
                    
                    break;
                case '%':
                    if (y != 0)
                    {
                        result = x % y;
                    }
                    else
                    {
                        result = 0;
                    }
                    
                    break;
                case '+':
                    result = x + y;
                    break;
                case '-':
                    result = x - y;
                    break;
                }
                *it = to_string(result);
            }
            else
            {
                switch (operation)
                {
                case '^':
                    dresult = pow(dx, dy);
                    break;
                case '*':
                    dresult = dx * dy;
                    break;
                case '/':
                    dresult = dx / dy;
                    break;
                case '%':
                    dresult = (int)dx % (int)dy;
                    break;
                case '+':
                    dresult = sum(dx, dy);
                    break;
                case '-':
                    dresult = dx - dy;
                    break;
                }
                *it = to_string(dresult);
            }
            
            
            //it = next(it);
            //cout << "X: " << x;
            //cout << "Y: " << y;
        }
    }

    cout << "Postfix Result: " << values.front();
}

string Functions::removeSpaces(string exp)noexcept(false)//---> VC 17
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

int Functions::operator^(const int& num)noexcept(false) //---> VC 17
{
    Functions temp(*this);
    int res = 0;
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
        else if (exp.at(i) == '-' && !isdigit(exp.at(i-1)) && exp.at(i-1) != 'i' && exp.at(i-1) != 'e' && exp.at(i) != '.')
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
        else if (exp.at(i) == 'e')
        {
            result += to_string(e<float>);
            if (i + 1 <= exp.length() - 1)
            {
                result += ',';
            }
        }
        else if (exp.at(i) == 'p')
        {
            result += to_string(pi<float>);
            if (i + 1 <= exp.length() - 1)
            {
                result += ',';
            }
            i++;
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
            precObj* temp = nullptr; // ---> VC 11
            switch (exp.at(i))
            {
            case '(':
                temp = new precObj{ 0, '(' }; // ---> VC 11
                break;
            case '^':
                temp = new precObj{ 6, '^' };
                break;
            case '*':
                temp = new precObj{ 5, '*' };
                break;
            case '/':
                temp = new precObj{ 4, '/' };
                break;
            case '%':
                temp = new precObj{3, '%'};
                break;
            case '+':
                temp = new precObj{ 2, '+' };
                break;
            case '-':
                temp = new precObj{ 1, '-' };
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

    cout << "\nPostFix Result: " << result;
    return result;
}

inline int power(int, int) noexcept
{
    return 0;
}
