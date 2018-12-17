#pragma once
#include "Value.h"
class TextValue : public Value
{
private:
	std::string value;
	static std::string typeName;
public:
	TextValue(std::string);

	virtual int getInteger();
	virtual double getDouble();
	virtual std::string getString();
	virtual bool getBoolean();

	virtual std::string getTypeName();
};

