#pragma once
#include <iostream>

enum TokenType {
	NUMBER,
	TEXT,

	PLUS,
	MINUS,
	STAR,
	SLASH,

	LEFT_PARENTHESES,
	RIGHT_PARENTHESES,

	END_OF_FILE
};

inline std::ostream & operator<<(std::ostream & out, TokenType tokenType) {
	switch (tokenType)
	{
	case NUMBER:
		out << "NUMBER";
		break;
	case TEXT:
		out << "TEXT";
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
	case LEFT_PARENTHESES:
		out << "LEFT_PARENTHESES";
		break;
	case RIGHT_PARENTHESES:
		out << "RIGHT_PARENTHESES";
		break;
	default:
		break;
	}

	return out;
}