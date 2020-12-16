#pragma once
#ifndef PRECEDENCEOBJ_H
#define PRECEDENCEOBJ_H

class [[nodiscard]]precObj //---> VC 17
{
public:
	precObj() {}
	int precedence;
	char operatorC;
	precObj(int pre, char oper) : precedence(pre), operatorC(oper) {}
	void setOperator(char oper);
	void setPrecedence(int prec);
};

#endif
