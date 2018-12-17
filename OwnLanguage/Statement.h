#pragma once

#include <iostream>
#include <memory>
#include "Expression.h"
#include "Variables.h"

using ExpressionPointer = std::shared_ptr<Expression>;

class Statement {
public:
	virtual void execute() = 0;
};