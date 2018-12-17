#include "Variables.h"
#include <iostream>

VariableContainer Variables::variableList = {};

Variables::Variables()
{
}


ValuePointer Variables::getVariable(std::string variableName)
{
	return variableList.at(variableName);
}

void Variables::setVariable(std::string variableName, ValuePointer variableValue)
{
	variableList.insert(std::make_pair(variableName, variableValue));
}

bool Variables::exists(std::string variableName)
{
	return variableList.find(variableName) != variableList.end();
}
