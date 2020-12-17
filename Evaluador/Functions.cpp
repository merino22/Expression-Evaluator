#include "Functions.h"
#include <list>
#include <vector>
#include <stack>
#include <sstream>

template<typename t> [[maybe_unused]]std::string type_name();

template<typename T> // ---> VC 14
constexpr static T pi = T(3.141592653589793238462643383); // ---> VC 14, 14

template<typename T>
constexpr static T e = T(2.718281828); //---> VC 14, 14

auto sum = [](auto x, auto y) { return x + y; }; //---> VC 14
auto sub = [](auto x, auto y) { return x - y; };//---> VC 14
auto mult = [](auto x, auto y) { return x * y; };//---> VC 14
auto mod = [](auto x, auto y) { return x % y; };//---> VC 14
auto expn = [](auto x, auto n) { return pow(x, n); };//---> VC 14

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

//---> VC 17
bool [[maybe_unused]]isFloat(string s) noexcept(false) { //---> VC 17
    istringstream iss(s);
    float floatx;
    iss >> noskipws >> floatx;
    return iss && iss.eof();     // Result converted to bool
}


void Functions::postfixToResult(string exp)
{
    int valueCount = 1;
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
                    result = expn(x, y);
                    break;
                case '*':
                    result = mult(x, y);
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
                        result = mod(x, y);
                    }
                    else
                    {
                        result = 0;
                    }
                    
                    break;
                case '+':
                    result = sum(x, y);
                    break;
                case '-':
                    result = sub(x, y);
                    break;
                }
                *it = to_string(result);
            }
            else
            {
                switch (operation)
                {
                case '^':
                    dresult = expn(dx, dy);
                    break;
                case '*':
                    dresult = mult(dx, dy);
                    break;
                case '/':
                    if (dy != 0)
                    {
                        dresult = dx / dy;
                    }
                    else {
                        dresult = 0;
                    }
                    
                    break;
                case '%':
                    if (dy != 0)
                    {
                        dresult = mod((int)dx, (int)dy);
                    }
                    else {
                        dresult = 0;
                    }
                    break;
                case '+':
                    dresult = sum(dx, dy);
                    break;
                case '-':
                    dresult = sub(dx, dy);
                    break;
                }
                *it = to_string(dresult);
            }
        }
    }

    cout << "Postfix Result: " << values.front();
}

void Functions::toPostfix(string exp)
{
    string result = "";
    list<string> results;
    stack<precObj*>operatorsz;

    for (int i = 0; i < exp.length(); i++)
    {
        //Check if first number is signed and concat to postfix result
        if (i == 0 && exp.at(i) == '-')
        {
            result += exp.at(i);
        }
        else if (exp.at(i) == '-' && exp.at(i - 1) == '(') //Check if first number inside parenthesis is signed and concat to result
        {
            result += exp.at(i);
        }
        else if (exp.at(i) == '-' && !isdigit(exp.at(i-1)) && exp.at(i-1) != 'i' && exp.at(i-1) != 'e' && exp.at(i) != '.') //Check if negative sign is used as operator or used to represent signed number
        {
            result += exp.at(i);
        }
        else if (isdigit(exp.at(i)) || exp.at(i) == '.')// If character found is a digit or decimal point then concat to postfix result
        {
            result += exp.at(i);
            if (i + 1 <= exp.length()-1 && !isdigit(exp.at(i + 1)) && exp.at(i+1) != '.') // If next char is not end of expression, isn't a digit and isn't decimal point then concat ',' 
            {
                result += ',';
            }
            
        }
        else if (exp.at(i) == 'e') //if char at is constant e then concat to postfix result
        {
            result += to_string(e<float>);
            if (i + 1 <= exp.length() - 1)
            {
                result += ',';
            }
        }
        else if (exp.at(i) == 'p') //If char at is pi then concat to postfix result
        {
            result += to_string(pi<float>);
            if (i + 1 <= exp.length() - 1)
            {
                result += ',';
            }
            i++;
        }
        else if (exp.at(i) == ')') //If right parenthesis is found then empty operators in stack until left parenthesis is found
        {
            while (!operatorsz.empty())
            {
                if (operatorsz.top()->operatorC != '(') //If operator found is not '('  
                {
                    cout << operatorsz.top()->operatorC;
                    result += operatorsz.top()->operatorC; //Concat operator to postfix result
                    result += ',';                         //Concat comma to postfix result as separator
                    operatorsz.pop();                      //Pop the operator from the stack
                }
                else if (operatorsz.top()->operatorC == '(') //If operator found is '(' then pop from stack and break from stack iteration
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
            // Variable temp used for new operator found in expression
            precObj* temp = nullptr; // ---> VC 11

            //Depending on what operator is found create a new precedence object and save its char value and precedence
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

            if (operatorsz.empty()) //If stack is empty then push temp
            {
                operatorsz.push(temp);    
            }
            else //If stack is not empty iterate through stack to compare precedence values
            {
                while(!operatorsz.empty())
                {
                    if (operatorsz.top()->precedence > temp->precedence && temp->precedence != 0) //If precedence of stack.top() operator is > temp precedence
                    {
                        result += operatorsz.top()->operatorC; //Concat operator to postfix result
                        result += ','; 
                        operatorsz.pop();                      //Pop operator from stack
                    } 
                    else //Else precedence of stack.top() is less than temp precedence
                    {
                        operatorsz.push(temp); //Push temp to stack
                        temp = nullptr;       //Set temp to null
                        break;
                    }
 
                    if (temp != nullptr && !operatorsz.empty() && operatorsz.top()->precedence < temp->precedence)
                    {
                        operatorsz.push(temp);
                        break;
                    }
                    //If stack is empty before end of last iteration and temp is not null, then push temp to stack
                    if (operatorsz.empty() && temp != nullptr)
                    {
                        operatorsz.push(temp);
                        temp = nullptr;
                        break;
                    }
                }   
            }
        }
    } //End of expression evaluation

    //If operator stack is not empty after expression evaluation then concat all operators to result until stack is left empty
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

    cout << "PostFix Result: " << result;
    postfixToResult(result);
}

inline int power(int, int) noexcept
{
    return 0;
}
