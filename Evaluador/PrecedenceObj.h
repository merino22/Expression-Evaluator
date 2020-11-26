#pragma once
#ifndef PRECEDENCEOBJ_H
#define PRECEDENCEOBJ_H

class precObj
{
public:
	precObj() {}
	int precedence = 0;
	char operatorC = ' ';
	precObj(int pre, char oper) : precedence(pre), operatorC(oper) {}
	void setOperator(char oper);
	void setPrecedence(int prec);
	
};

#endif
