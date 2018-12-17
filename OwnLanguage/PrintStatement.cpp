#include "PrintStatement.h"



PrintStatement::PrintStatement(ExpressionPointer initialExpression)
	: expression(initialExpression)
{
}

void PrintStatement::execute()
{
	std::cout << ">> " << expression->evaluate()->getString() << std::endl;
}
