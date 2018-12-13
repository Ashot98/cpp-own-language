#include <iostream>
#include "Lexer.h"

int main() {
	std::string input = "10 + 25 - 5 * 7";
	Lexer lexer(input);
	
	std::vector<Token> tokens = lexer.tokenize();
	for (auto token : tokens) {
		std::cout << token << std::endl;
	}

	system("pause");
	return 0;
}