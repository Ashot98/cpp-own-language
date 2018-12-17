#pragma once

#include <vector>
#include <stack>
#include <memory>
#include <exception>
#include "Token.h"
#include "Expression.h"
#include "IntegerExpression.h"
#include "TextExpression.h"
#include "BinaryOperationExpression.h"

using ExpressionPointer = std::shared_ptr<Expression>;

class Parser
{
private:
	std::vector<Token> tokensToParse;
	int currentPosition;

	ExpressionPointer parseValue();
	ExpressionPointer parseMultiplicativeOp();
	ExpressionPointer parseAdditiveOp();
	ExpressionPointer parseToken();

	void validateTokens();

	bool matchType(TokenType);
	void incrementPosition();
public:
	Parser(std::vector<Token>);

	std::vector<ExpressionPointer> parse();
};



