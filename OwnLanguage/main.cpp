#include <iostream>
#include "Lexer.h"
#include "Parser.h"

int main() {
	std::string input = "2 + (4 + 21) * 3";
	Lexer lexer(input);
	
	std::vector<Token> tokens = lexer.tokenize();
	for (auto token : tokens) {
		std::cout << token << std::endl;
	}

	Parser parser(tokens);
	std::vector<ExpressionPointer> expressions = parser.parse();

	for (auto expr : expressions) {
		std::cout << expr->evaluate() << std::endl;
	}

	system("pause");
	return 0;
}