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
		memcpy(m_value, other.m_value, 64);
		m_type = other.m_type;
	}
	return*this;
}

AwesomeType& AwesomeType::operator=(AwesomeType&& other)
{
	if (this != &other)
	{
		memcpy(m_value, other.m_value, 64);
		m_type = other.m_type;
		memset(other.m_value, 0, 64);
		other.m_type = TYPES::UNDEFINED;
	}
	return *this;
}

AwesomeType::AwesomeType(const AwesomeType& other)
	:m_type(other.m_type)
{
	memcpy(this->m_value, other.m_value, 64);
}

AwesomeType::AwesomeType(AwesomeType&& other)
	:m_type(other.m_type)
{
	memcpy(this->m_value, other.m_value, 64);
	memset(other.m_value, 0, 64);
	other.m_type = TYPES::UNDEFINED;
}

void AwesomeType::DestroyObject(AwesomeType& value)
{
	memset(value.m_value, 0, 64);
	value.m_type = TYPES::UNDEFINED;
}

void AwesomeType::Swap(AwesomeType& first, AwesomeType& second)
{
	AwesomeType temp(first);
	first = second;
	second = temp;
}
