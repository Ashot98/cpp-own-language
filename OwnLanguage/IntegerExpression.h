#pragma once
#include "Expression.h"
#include "IntegerValue.h"

class IntegerExpression : public Expression
{
private:
	int value;
public:
	IntegerExpression(int);
	virtual ValuePointer evaluate();
};

