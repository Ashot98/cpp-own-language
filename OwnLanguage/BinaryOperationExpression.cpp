#include "BinaryOperationExpression.h"



BinaryOperationExpression::BinaryOperationExpression(TokenType initialOperation, ExpressionPointer initialLeftOperand, ExpressionPointer initialRightOperand)
	: operation(initialOperation), leftOperand(initialLeftOperand), rightOperand(initialRightOperand)
{
}


ValuePointer BinaryOperationExpression::evaluate()
{
	ValuePointer leftValue = leftOperand->evaluate();
	ValuePointer rightValue = rightOperand->evaluate();

	if (leftValue->getTypeName() == "str") {
		std::string value;
		switch (operation)
		{
		case PLUS:
			value = leftValue->getString() + rightValue->getString();
			return std::make_shared<TextValue>(value);
			break;
		default:
			return std::make_shared<TextValue>("");
			break;
		}
	}

	int value;
	switch (operation)
	{
	case PLUS:
		value = leftOperand->evaluate()->getInteger() + rightOperand->evaluate()->getInteger();
		return std::make_shared<IntegerValue>(value);
		break;
	case MINUS:
		value = leftOperand->evaluate()->getInteger() - rightOperand->evaluate()->getInteger();
		return std::make_shared<IntegerValue>(value);
		break;
	case STAR:
		value = leftOperand->evaluate()->getInteger() * rightOperand->evaluate()->getInteger();
		return std::make_shared<IntegerValue>(value);
		break;
	case SLASH:
		value = leftOperand->evaluate()->getInteger() / rightOperand->evaluate()->getInteger();
		return std::make_shared<IntegerValue>(value);
		break;
	default:
		return std::make_shared<IntegerValue>(0);
		break;
	}
}
