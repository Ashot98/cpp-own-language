#include <iostream>
#include "Lexer.h"
#include "Parser.h"
#include "FileHandler.h"

int main() {
	
	FileHandler handler("./files/test.txt");
	std::string input = handler.readAllBytes();

	Lexer lexer(input);
	
	std::vector<Token> tokens = lexer.tokenize();
	for (auto token : tokens) {
		std::cout << token << std::endl;
	}

	Parser parser(tokens);
	std::vector<ExpressionPointer> expressions = parser.parse();

	for (auto expr : expressions) {
		std::cout << expr->evaluate()->getString() << std::endl;
	}

	system("pause");
	return 0;
}