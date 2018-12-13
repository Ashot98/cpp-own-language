#include "Token.h"



Token::Token() {

}

Token::Token(TokenType initialType, std::string initialValue)
	: type(initialType), value(initialValue) 
{

}


TokenType Token::getType() {
	return type;
}

void Token::setType(TokenType newType) {
	type = newType;
}

std::string Token::getValue() {
	return value;
}

void Token::setValue(std::string newValue) {
	value = newValue;
}

std::ostream & operator<<(std::ostream & out, Token token) {
	out << token.type << ' ' << token.value;
	return out;
}