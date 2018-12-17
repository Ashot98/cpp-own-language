#pragma once

#include <fstream>
#include <string>
#include <sstream>

class FileHandler
{
private:
	std::string fileName;
	std::fstream fileStream;
	std::stringstream fileBuffer;
public:
	FileHandler(std::string);
	~FileHandler();

	std::string readAllBytes();
};

