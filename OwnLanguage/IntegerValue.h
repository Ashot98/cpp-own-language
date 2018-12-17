#pragma once

#include "Value.h"

class IntegerValue : public Value
{
private:
	int value;
	static std::string typeName;
public:
	IntegerValue(int);

	virtual int getInteger();
	virtual double getDouble();
	virtual std::string getString();
	virtual bool getBoolean();

	virtual std::string getTypeName();
};

