#pragma once
#include <exception>
//some comment
class BadCast: public std::exception
{
public:
	virtual const char* what() const throw() 
	{ 
		return "Cannot cast type!"; 
		//comment
	}
};