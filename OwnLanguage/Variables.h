#pragma once

#include <unordered_map>
#include <string>
#include <memory>
#include "Value.h"

using ValuePointer = std::shared_ptr<Value>;
using VariableContainer = std::unordered_map<std::string, ValuePointer>;

class Variables
{
private:
	static VariableContainer variableList;
public:
	Variables();

	static ValuePointer getVariable(std::string);
	static void setVariable(std::string, ValuePointer);
	static bool exists(std::string);
};

