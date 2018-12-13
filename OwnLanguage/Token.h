#pragma once

#include <string>
#include <iostream>
#include "TokenTypes.h"

class Token
{
private:
	std::string value;
	TokenType type;

public:
	Token();
	Token(TokenType, std::string);

	TokenType getType();
	void setType(TokenType);

	std::string getValue();
	void setValue(std::string);

	friend std::ostream& operator<<(std::ostream &, Token);
};

