#pragma once

#include <vector>
#include <stack>
#include <memory>
#include <exception>
#include "Token.h"
#include "IntegerExpression.h"
#include "TextExpression.h"
#include "BinaryOperationExpression.h"
#include "BasicStatement.h"
#include "AssignStatement.h"
#include "PrintStatement.h"

using ExpressionPointer = std::shared_ptr<Expression>;
using StatementPointer = std::shared_ptr<Statement>;

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
	bool move(int);
public:
	Parser(std::vector<Token>);

	std::vector<StatementPointer> parse();
};



