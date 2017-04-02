#pragma once
#include <exception>

class BadCast: public std::exception
{
public:
	virtual const char* what() const throw() 
	{ 
		return "Cannot cast type!"; 
	}
};