#pragma once
#include <iostream>

enum TokenType {
	NUMBER,

	PLUS,
	MINUS,
	STAR,
	SLASH,

	END_OF_FILE
};

inline std::ostream & operator<<(std::ostream & out, TokenType tokenType) {
	switch (tokenType)
	{
	case NUMBER:
		out << "NUMBER";
		break;
	case PLUS:
		out << "PLUS";
		break;
	case MINUS:
		out << "MINUS";
		break;
	case STAR:
		out << "STAR";
		break;
	case SLASH:
		out << "SLASH";
		break;
	case END_OF_FILE:
		out << "END_OF_FILE";
		break;
	default:
		break;
	}

	return out;
}