#pragma once
#include "BadCast.h"
#include <iostream>
#include <fstream>
#include <exception>
#include <array>

//#define ReturnIfSame(x, y) \
//if(std::is_same<T, x>::value) return y

enum class Types
{
	Undefined,
	Bool,
	Char,
	UnsignedChar,
	WcharT,
	Int,
	UnsignedInt,
	ShortInt,
	UnsignedShortInt,
	LongInt,
	UnsignedLongInt,
	LongLongInt,
	UnsignedLongLongInt,
	Float,
	Double,
	LongDouble
};

template <typename T>
Types TypeDetector()
{
	//ReturnIfSame(bool, TYPES::BOOL);

	if (std::is_same<T, bool>::value)
		return Types::Bool;
	if (std::is_same<T, char>::value)
		return Types::Char;
	if (std::is_same<T, unsigned char>::value)
		return Types::UnsignedChar;
	if (std::is_same<T, wchar_t>::value)
		return Types::WcharT;
	if (std::is_same<T, int>::value)
		return Types::Int;
	if (std::is_same<T, unsigned int>::value)
		return Types::UnsignedInt;
	if (std::is_same<T, short int>::value)
		return Types::ShortInt;
	if (std::is_same<T, unsigned short int>::value)
		return Types::UnsignedShortInt;
	if (std::is_same<T, long int>::value)
		return Types::LongInt;
	if (std::is_same<T, unsigned long int>::value)
		return Types::UnsignedLongInt;
	if (std::is_same<T, long long int>::value)
		return Types::LongLongInt;
	if (std::is_same<T, unsigned long long int>::value)
		return Types::UnsignedLongLongInt;
	if (std::is_same<T, float>::value)
		return Types::Float;
	if (std::is_same<T, double>::value)
		return Types::Double;
	if (std::is_same<T, long double>::value)
		return Types::LongDouble;
	
	return Types::Undefined;
}


class AwesomeType
{
public:
	AwesomeType();
	template <typename T>
	AwesomeType(T value);
	AwesomeType(const AwesomeType& other);
	AwesomeType(AwesomeType&& other);

	AwesomeType& operator= (const AwesomeType& other);
	AwesomeType& operator= (AwesomeType&& other);

	template <typename T>
	T ReadValueAs();
	static void DestroyObject(AwesomeType& value);
	static void Swap(AwesomeType& first, AwesomeType& second);
	Types GetType() { return type; }

private:
	std::array<char, 8> value;
	Types type;
};

template <typename T>
AwesomeType::AwesomeType(T value)
	: type(TypeDetector<T>())
{
	static_assert(!std::is_null_pointer<T>::value, "Invalid value! nullptr_t cannot be an input type");
	static_assert(!std::is_void<T>::value, "Invalid value! void cannot be an input type");
	static_assert((std::is_integral<T>::value || std::is_floating_point<T>::value), "Unsupported type");
	memcpy(this->value.data(), &value, sizeof(T));
}

template <typename T>
T AwesomeType::ReadValueAs()
{
	if (TypeDetector<T>() == type)
	{
		return *(reinterpret_cast<T*>(value.data()));
	}
	throw BadCast();
}