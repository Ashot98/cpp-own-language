#pragma once

#include <memory>
#include "Expression.h"
#include "TokenTypes.h"

using ExpressionPointer = std::shared_ptr<Expression>;

class BinaryOperationExpression	:	public Expression
{
private:
	ExpressionPointer leftOperand, rightOperand;
	TokenType operation;

public:
	BinaryOperationExpression(TokenType, ExpressionPointer, ExpressionPointer);

	virtual int evaluate();
};

