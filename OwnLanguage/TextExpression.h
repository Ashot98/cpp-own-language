#pragma once
#include "Expression.h"
#include "TextValue.h"

class TextExpression : public Expression
{
private:
	std::string value;
public:
	TextExpression(std::string);
	virtual ValuePointer evaluate();
};

