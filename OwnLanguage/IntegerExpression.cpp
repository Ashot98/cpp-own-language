#include "IntegerExpression.h"


IntegerExpression::IntegerExpression(int initialValue)
	: value(initialValue)
{
}

int IntegerExpression::evaluate()
{
	return value;
}
