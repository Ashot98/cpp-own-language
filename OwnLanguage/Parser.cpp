#include "Parser.h"


ExpressionPointer Parser::parseNumber()
{
	Token currentToken = tokensToParse.at(currentPosition);

	if (matchType(NUMBER)) {
		incrementPosition();
		IntegerExpression result(std::stoi(currentToken.getValue()));
		return std::make_shared<IntegerExpression>(result);
	}
	if (matchType(LEFT_PARENTHESES)) {
		incrementPosition();
		ExpressionPointer result = parseToken();
		if (matchType(RIGHT_PARENTHESES)) {
			incrementPosition();
		}
		return result;
	}
	throw new std::runtime_error("Invalid expression");
}

ExpressionPointer Parser::parseMultiplicativeOp()
{
	ExpressionPointer currentExpression = parseNumber();
	while (true) {
		if (matchType(SLASH)) {
			incrementPosition();
			BinaryOperationExpression result(SLASH, currentExpression, parseNumber());
			currentExpression = std::make_shared<BinaryOperationExpression>(result);
		}
		else if (matchType(STAR)) {
			incrementPosition();
			BinaryOperationExpression result(STAR, currentExpression, parseNumber());
			currentExpression = std::make_shared<BinaryOperationExpression>(result);
		}
		else {
			break;
		}
	}

	return currentExpression;
}

ExpressionPointer Parser::parseAdditiveOp()
{
	ExpressionPointer currentExpression = parseMultiplicativeOp();
	while (true) {
		if (matchType(PLUS)) {
			incrementPosition();
			BinaryOperationExpression result(PLUS, currentExpression, parseMultiplicativeOp());
			currentExpression = std::make_shared<BinaryOperationExpression>(result);
		}
		else if (matchType(MINUS)) {
			incrementPosition();
			BinaryOperationExpression result(MINUS, currentExpression, parseMultiplicativeOp());
			currentExpression = std::make_shared<BinaryOperationExpression>(result);
		}
		else {
			break;
		}
	}

	return currentExpression;
}

ExpressionPointer Parser::parseToken() 
{
	return parseAdditiveOp();
}

void Parser::validateTokens()
{
	std::stack<Token> parenthesesStack;
	for (auto token : tokensToParse) {
		if (token.getType() == LEFT_PARENTHESES) {
			parenthesesStack.push(token);
		}
		else if (token.getType() == RIGHT_PARENTHESES) {
			if (parenthesesStack.empty()) {
				throw new std::runtime_error("Invalid parentheses count");
			}
			else {
				parenthesesStack.pop();
			}
		}
	}
	if (!parenthesesStack.empty()) {
		throw new std::runtime_error("Invalid parentheses count");
	}
}

bool Parser::matchType(TokenType comparisionType)
{
	Token currentToken = tokensToParse.at(currentPosition);
	return currentToken.getType() == comparisionType;
}

void Parser::incrementPosition()
{
	++currentPosition;
}

Parser::Parser(std::vector<Token> initialList)
{
	tokensToParse.assign(initialList.begin(), initialList.end());
}

std::vector<ExpressionPointer> Parser::parse()
{
	validateTokens();

	std::vector<ExpressionPointer> result;
	while (tokensToParse.at(currentPosition).getType() != END_OF_FILE) {
		result.push_back(parseToken());
	}

	return result;
}
