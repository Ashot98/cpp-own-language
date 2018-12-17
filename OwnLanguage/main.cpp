#include <iostream>
#include "Lexer.h"
#include "Parser.h"
#include "FileHandler.h"

int main() {
	
	FileHandler handler("./files/test.mylang");
	std::string input = handler.readAllBytes();

	Lexer lexer(input);
	
	std::vector<Token> tokens = lexer.tokenize();

	Parser parser(tokens);
	std::vector<StatementPointer> expressions = parser.parse();

	system("pause");
	return 0;
}