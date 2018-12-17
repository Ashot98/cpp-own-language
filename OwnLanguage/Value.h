#pragma once

#include <string>

class Value
{
public:
	virtual int getInteger() = 0;
	virtual double getDouble() = 0;
	virtual std::string getString() = 0;
	virtual bool getBoolean() = 0;

	virtual std::string getTypeName() = 0;
};

