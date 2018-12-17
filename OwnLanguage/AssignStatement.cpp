#include "AssignStatement.h"


AssignStatement::AssignStatement(std::string initialName, ExpressionPointer initialExpression)
	: variableName(initialName), expressionToAssign(initialExpression)
{
}

void AssignStatement::execute()
{
	Variables::setVariable(variableName, expressionToAssign->evaluate());
}
