#pragma once

#include "Statement.h"

class AssignStatement : public Statement
{
private:
	std::string variableName;
	ExpressionPointer expressionToAssign;
public:
	AssignStatement(std::string, ExpressionPointer);

	virtual void execute();
};

