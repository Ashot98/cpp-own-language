#include "BinaryOperationExpression.h"



BinaryOperationExpression::BinaryOperationExpression(TokenType initialOperation, ExpressionPointer initialLeftOperand, ExpressionPointer initialRightOperand)
	: operation(initialOperation), leftOperand(initialLeftOperand), rightOperand(initialRightOperand)
{
}


int BinaryOperationExpression::evaluate()
{

	switch (operation)
	{
	case PLUS:
		return leftOperand->evaluate() + rightOperand->evaluate();
		break;
	case MINUS:
		return leftOperand->evaluate() - rightOperand->evaluate();;
		break;
	case STAR:
		return leftOperand->evaluate() * rightOperand->evaluate();;
		break;
	case SLASH:
		return leftOperand->evaluate() / rightOperand->evaluate();;
		break;
	default:
		return 0;
		break;
	}
}
