#pragma once
#include <iostream>

enum TokenType {
	NUMBER,
	TEXT,
	WORD,

	PLUS,
	MINUS,
	STAR,
	SLASH,
	EQUAL,

	LEFT_PARENTHESES,
	RIGHT_PARENTHESES,

	NEW_LINE,
	END_OF_FILE,

	PRINT
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
	case WORD:
		out << "WORD";
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
	case EQUAL:
		out << "EQUAL";
		break;
	case END_OF_FILE:
		out << "END_OF_FILE";
		break;
	case NEW_LINE:
		out << "NEW_LINE";
		break;
	case LEFT_PARENTHESES:
		out << "LEFT_PARENTHESES";
		break;
	case RIGHT_PARENTHESES:
		out << "RIGHT_PARENTHESES";
		break;
	case PRINT:
		out << "PRINT";
		break;
	default:
		break;
	}

	return out;
}