#include "Lexer.h"

std::string Lexer::operators = "+-*/()";
std::vector<TokenType> Lexer::operatorsTokenTypes = { PLUS, MINUS, STAR, SLASH, LEFT_PARENTHESES, RIGHT_PARENTHESES };

Lexer::Lexer(std::string initialInput) {
	input = initialInput;
	currentPosition = 0;
}

std::vector<Token> Lexer::tokenize() {
	while (currentPosition < input.length()) {
		char currentValue = input.at(currentPosition);
		if (std::isdigit(currentValue)) {
			tokenizeNumber();
			
		}
		else if (operators.find(currentValue) != -1) {
			tokenizeOperator();
		}
		else {
			next();
		}
	}

	tokenList.push_back(Token(END_OF_FILE, ""));

	return tokenList;
}

void Lexer::tokenizeNumber()
{
	char currentValue = input.at(currentPosition);
	std::string numberValue = "";
	while (isdigit(currentValue)) {
		numberValue.push_back(currentValue);
		currentValue = next();
	}
	addToken(NUMBER, numberValue);
}

void Lexer::tokenizeOperator()
{
	char currentValue = input.at(currentPosition);
	int operatorIndex = operators.find(currentValue);
	
	addToken(operatorsTokenTypes.at(operatorIndex));
	next();
}

char Lexer::next()
{
	currentPosition++;
	if (currentPosition >= input.length()) {
		return '\0';
	}
	return input.at(currentPosition);
}

void Lexer::addToken(TokenType newTokenType)
{
	tokenList.push_back(Token(newTokenType, ""));
}

void Lexer::addToken(TokenType newTokenType, std::string newTokenValue)
{
	tokenList.push_back(Token(newTokenType, newTokenValue));

}
