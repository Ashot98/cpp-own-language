#pragma once
#include "Value.h"
#include <Memory>

using ValuePointer = std::shared_ptr<Value>;

class Expression
{
public:
	virtual ValuePointer evaluate() = 0;
};

