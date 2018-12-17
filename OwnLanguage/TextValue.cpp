#include "TextValue.h"

std::string TextValue::typeName = "str";

TextValue::TextValue(std::string initialValue)
	: value(initialValue)
{
}

int TextValue::getInteger()
{
	return std::stoi(value);
}

double TextValue::getDouble()
{
	return std::stof(value);
}

std::string TextValue::getString()
{
	return value;
}

bool TextValue::getBoolean()
{
	return value != "";
}

std::string TextValue::getTypeName()
{
	return typeName;
}
