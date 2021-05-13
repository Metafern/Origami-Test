#pragma once
#include <exception>
#include <string>

class Exceptions : public std::exception {
	virtual const char* getType();
	const std::string& getFile();
	const std::string& getOriginString();
 
protected:
	mutable std::string whatBuffer;
};