#include "IntegerValue.h"

std::string IntegerValue::typeName = "int";

IntegerValue::IntegerValue(int initialValue)
	: value(initialValue)
{
}

int IntegerValue::getInteger()
{
	return value;
}

double IntegerValue::getDouble()
{
	return static_cast<double>(value);
}

std::string IntegerValue::getString()
{
	return std::to_string(value);
}

bool IntegerValue::getBoolean()
{
	return value != 0;
}

std::string IntegerValue::getTypeName()
{
	return typeName;
}
