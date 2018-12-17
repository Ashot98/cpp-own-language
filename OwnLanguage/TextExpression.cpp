#include "TextExpression.h"


TextExpression::TextExpression(std::string initialValue)
	: value(initialValue)
{
}

ValuePointer TextExpression::evaluate()
{
	return std::make_shared<TextValue>(value);;
}
