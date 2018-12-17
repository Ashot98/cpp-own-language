#pragma once

#include "Statement.h"

class BasicStatement : public Statement
{
	ExpressionPointer expression;
public:
	BasicStatement(ExpressionPointer);

	virtual void execute();
};

