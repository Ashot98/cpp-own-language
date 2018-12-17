#include "Lexer.h"

std::string Lexer::operators = "+-*/()=";
std::vector<TokenType> Lexer::operatorsTokenTypes = { PLUS, MINUS, STAR, SLASH, LEFT_PARENTHESES, RIGHT_PARENTHESES, EQUAL };

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
		else if (currentValue == '"') {
			tokenizeText();
		}
		else if (isalpha(currentValue)) {
			tokenizeWord();
		}
		else if (operators.find(currentValue) != -1) {
			tokenizeOperator();
		}
		else if (currentValue == '\n') {
			addToken(NEW_LINE);
			next();
		}
		else {
			next();
		}
	}

	addToken(END_OF_FILE);

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

void Lexer::tokenizeText()
{
	char currentValue = next();
	std::string textValue = "";

	while (currentValue != '"') {
		textValue.push_back(currentValue);
		currentValue = next();
		if (currentValue == '\0') {
			throw new std::runtime_error("Invalid String Literal");
		}
	}

	addToken(TEXT, textValue);
}

void Lexer::tokenizeWord()
{
	std::string textValue = "";
	textValue.push_back(input.at(currentPosition));
	char currentValue = next();

	while (isalpha(currentValue) || isdigit(currentValue) || currentValue == '_') {
		textValue.push_back(currentValue);
		currentValue = next();
	}

	if (textValue == "print") {
		addToken(PRINT);
		return;
	}

	addToken(WORD, textValue);
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
