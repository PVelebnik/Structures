#pragma once
#include <iostream>
#include <fstream>
#include <exception>
#include <array>
#include "BadCast.h"

//#define ReturnIfSame(x, y) \
//if(std::is_same<T, x>::value) return y

enum class TYPES
{
	UNDEFINED,
	BOOL,
	CHAR,
	UNSIGNED_CHAR,
	WCHAR_T,
	INT,
	UNSIGNED_INT,
	SHORT_INT,
	UNSIGNED_SHORT_INT,
	LONG_INT,
	UNSIGNED_LONG_INT,
	LONG_LONG_INT,
	UNSIGNED_LONG_LONG_INT,
	FLOAT,
	DOUBLE,
	LONG_DOUBLE
};

template <typename T>
TYPES TypeDetector(T)
{
	//ReturnIfSame(bool, TYPES::BOOL);

	if (std::is_same<T, bool>::value)
		return TYPES::BOOL;
	if (std::is_same<T, char>::value)
		return TYPES::CHAR;
	if (std::is_same<T, unsigned char>::value)
		return TYPES::UNSIGNED_CHAR;
	if (std::is_same<T, wchar_t>::value)
		return TYPES::WCHAR_T;
	if (std::is_same<T, int>::value)
		return TYPES::INT;
	if (std::is_same<T, unsigned int>::value)
		return TYPES::UNSIGNED_INT;
	if (std::is_same<T, short int>::value)
		return TYPES::SHORT_INT;
	if (std::is_same<T, unsigned short int>::value)
		return TYPES::UNSIGNED_SHORT_INT;
	if (std::is_same<T, long int>::value)
		return TYPES::LONG_INT;
	if (std::is_same<T, unsigned long int>::value)
		return TYPES::UNSIGNED_LONG_INT;
	if (std::is_same<T, long long int>::value)
		return TYPES::LONG_LONG_INT;
	if (std::is_same<T, unsigned long long int>::value)
		return TYPES::UNSIGNED_LONG_LONG_INT;
	if (std::is_same<T, float>::value)
		return TYPES::FLOAT;
	if (std::is_same<T, double>::value)
		return TYPES::DOUBLE;
	if (std::is_same<T, long double>::value)
		return TYPES::LONG_DOUBLE;
	
	return TYPES::UNDEFINED;
}


class AwesomeType
{
public:
	AwesomeType();
	template <typename T>
	AwesomeType(T value);
	AwesomeType(const AwesomeType& other);
	AwesomeType(AwesomeType&& other);

	AwesomeType& operator = (const AwesomeType& other);
	AwesomeType& operator=(AwesomeType&& other);

	template <typename T>
	T ReadValueAs();
	static void DestroyObject(AwesomeType& value);
	static void Swap(AwesomeType& first, AwesomeType& second);
	TYPES GetType() { return m_type; }

private:
	std::array<char, 8> m_value;
	TYPES m_type;
};

template <typename T>
AwesomeType::AwesomeType(T value)
	: m_type(TypeDetector(value))
{
	static_assert(!std::is_null_pointer<T>::value, "Invalid value! nullptr_t cannot be an input type");
	static_assert(!std::is_void<T>::value, "Invalid value! void cannot be an input type");
	static_assert((std::is_integral<T>::value || std::is_floating_point<T>::value), "Unsupported type");
	memcpy(m_value.data(), &value, sizeof(T));
}

template <typename T>
T AwesomeType::ReadValueAs()
{
	if (TypeDetector(T()) == m_type)
	{
		return *(reinterpret_cast<T*>(m_value.data()));
	}
	throw BadCast();
}