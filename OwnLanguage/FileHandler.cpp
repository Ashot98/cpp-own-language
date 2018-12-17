#include "FileHandler.h"

FileHandler::FileHandler(std::string inputFileName)
	: fileName(inputFileName)
{
	fileStream.open(inputFileName, std::ios::in);
}

FileHandler::~FileHandler()
{
	fileStream.close();
}

std::string FileHandler::readAllBytes()
{
	if (fileStream.is_open()) {
		fileBuffer << fileStream.rdbuf();
	}

	return fileBuffer.str();
}
