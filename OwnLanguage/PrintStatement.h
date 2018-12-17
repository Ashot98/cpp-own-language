#pragma once
#include "Statement.h"
class PrintStatement : public Statement
{
private:
	ExpressionPointer expression;
public:
	PrintStatement(ExpressionPointer);

	virtual void execute();
};

