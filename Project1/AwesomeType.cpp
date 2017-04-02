#include "AwesomeType.h"

AwesomeType:: AwesomeType()
	:m_type(TYPES::UNDEFINED)
	, m_value()
{
}


AwesomeType& AwesomeType::operator=(const AwesomeType& other)
{
	if (this != &other)
	{
		m_value = other.m_value;
		m_type = other.m_type;
	}
	return*this;
}

AwesomeType& AwesomeType::operator=(AwesomeType&& other)
{
	if (this != &other)
	{
		m_value = std::move(other.m_value);
		m_type = std::move(other.m_type);
		other.m_type = TYPES::UNDEFINED;
	}
	return *this;
}

AwesomeType::AwesomeType(const AwesomeType& other)
	: m_value(other.m_value)
	, m_type(other.m_type)
{
}

AwesomeType::AwesomeType(AwesomeType&& other)
	: m_value(std::move(other.m_value))
	, m_type(std::move(other.m_type))
{
	other.m_type = TYPES::UNDEFINED;
}

void AwesomeType::DestroyObject(AwesomeType& value)
{
	value.m_type = TYPES::UNDEFINED;
}

void AwesomeType::Swap(AwesomeType& first, AwesomeType& second)
{
	if(first.m_value!=second.m_value)
		std::swap(first.m_value, second.m_value);
		std::swap(first.m_type, second.m_type);
}
