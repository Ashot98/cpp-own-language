#pragma once

#include <string>
#include <vector>
#include <cctype>
#include "Token.h"

class Lexer
{
private:
	static std::string operators;
	static std::vector<TokenType> operatorsTokenTypes;

	std::string input;
	std::vector<Token> tokenList;
	int currentPosition;
	
	void tokenizeNumber();
	void tokenizeText();
	void tokenizeOperator();

	char next();

	void addToken(TokenType);
	void addToken(TokenType, std::string);
public:
	Lexer(std::string);
	
	std::vector<Token> tokenize();
};

	

