#include "IntegerExpression.h"


IntegerExpression::IntegerExpression(int initialValue)
	: value(initialValue)
{
}

ValuePointer IntegerExpression::evaluate()
{
	return std::make_shared<IntegerValue>(value);
}
