#include "Parser.h"


ExpressionPointer Parser::parseValue()
{
	Token currentToken = tokensToParse.at(currentPosition);

	if (matchType(NUMBER)) {
		move(1);
		IntegerExpression result(std::stoi(currentToken.getValue()));
		return std::make_shared<IntegerExpression>(result);
	}
	if (matchType(TEXT)) {
		move(1);
		TextExpression result(currentToken.getValue());
		return std::make_shared<TextExpression>(result);
	}
	if (matchType(WORD)) {
		move(1);
		ValuePointer value = Variables::getVariable(currentToken.getValue());
		IntegerExpression result(value->getInteger());
		return std::make_shared<IntegerExpression>(result);
	}
	if (matchType(LEFT_PARENTHESES)) {
		move(1);
		ExpressionPointer result = parseToken();
		if (matchType(RIGHT_PARENTHESES)) {
			move(1);
		}
		return result;
	}
	throw new std::runtime_error("Invalid expression");
}

ExpressionPointer Parser::parseMultiplicativeOp()
{
	ExpressionPointer currentExpression = parseValue();
	while (true) {
		if (matchType(SLASH)) {
			move(1);
			BinaryOperationExpression result(SLASH, currentExpression, parseValue());
			currentExpression = std::make_shared<BinaryOperationExpression>(result);
		}
		else if (matchType(STAR)) {
			move(1);
			BinaryOperationExpression result(STAR, currentExpression, parseValue());
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
			move(1);
			BinaryOperationExpression result(PLUS, currentExpression, parseMultiplicativeOp());
			currentExpression = std::make_shared<BinaryOperationExpression>(result);
		}
		else if (matchType(MINUS)) {
			move(1);
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

bool Parser::move(int steps)
{
	int newPosition = currentPosition + steps;
	if (newPosition >= tokensToParse.size()) {
		return false;
	}

	currentPosition = newPosition;
	return true;
}

Parser::Parser(std::vector<Token> initialList)
{
	tokensToParse.assign(initialList.begin(), initialList.end());
}

std::vector<StatementPointer> Parser::parse()
{
	validateTokens();

	std::vector<StatementPointer> result;
	Token currentToken = tokensToParse.at(currentPosition);
	while (currentToken.getType() != END_OF_FILE) {
		
		if (currentToken.getType() == NEW_LINE) {
			if (!result.empty()) {
				int lastIndex = result.size() - 1;
				result[lastIndex]->execute();
			}
			move(1);
		}
		else if (currentToken.getType() == WORD && tokensToParse.at(currentPosition + 1).getType() == EQUAL) {
			if (move(2)) {
				AssignStatement value(currentToken.getValue(), parseToken());
				result.push_back(std::make_shared<AssignStatement>(value));
			}
			
		}
		else if (currentToken.getType() == PRINT) {
			if (move(1)) {
				PrintStatement value(parseToken());
				result.push_back(std::make_shared<PrintStatement>(value));
			}
		}
		else {
			BasicStatement value(parseToken());
			result.push_back(std::make_shared<BasicStatement>(value));
		}
		currentToken = tokensToParse.at(currentPosition);
	}

	if (!result.empty()) {
		int lastIndex = result.size() - 1;
		result[lastIndex]->execute();
	}
	return result;
}
