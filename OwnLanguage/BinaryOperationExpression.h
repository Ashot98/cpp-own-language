#pragma once

#include <memory>
#include <typeinfo>
#include "Expression.h"
#include "TokenTypes.h"
#include "IntegerValue.h"
#include "TextValue.h"

using ExpressionPointer = std::shared_ptr<Expression>;

class BinaryOperationExpression	:	public Expression
{
private:
	ExpressionPointer leftOperand, rightOperand;
	TokenType operation;

public:
	BinaryOperationExpression(TokenType, ExpressionPointer, ExpressionPointer);

	virtual ValuePointer evaluate();
};

