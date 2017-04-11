#include "AwesomeType.h"

AwesomeType:: AwesomeType()
	: type(Types::Undefined)
	, value()
{
}


AwesomeType& AwesomeType::operator=(const AwesomeType& other)
{
	if (this != &other)
	{
		value = other.value;
		type = other.type;
	}
	return*this;
}

AwesomeType& AwesomeType::operator=(AwesomeType&& other)
{
	if (this != &other)
	{
		value = std::move(other.value);
		type = std::move(other.type);
		other.type = Types::Undefined;
	}
	return *this;
}

AwesomeType::AwesomeType(const AwesomeType& other)
	: value(other.value)
	, type(other.type)
{
}

AwesomeType::AwesomeType(AwesomeType&& other)
	: value(std::move(other.value))
	, type(std::move(other.type))
{
	other.type = Types::Undefined;
}

void AwesomeType::DestroyObject(AwesomeType& value)
{
	value.type = Types::Undefined;
}

void AwesomeType::Swap(AwesomeType& first, AwesomeType& second)
{
	if (&first.value != &second.value)
	{
		std::swap(first.value, second.value);
		std::swap(first.type, second.type);
	}
}
