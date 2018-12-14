#pragma once
#include "Expression.h"

class IntegerExpression : public Expression
{
private:
	int value;
public:
	IntegerExpression(int);
	virtual int evaluate();
};

