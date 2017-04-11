#include "Tests.h"
#include "AwesomeType.h"
#include <iostream>

#define ARE_EQ( x, y) \
 if (x == y) std::cout << "Passed" <<std::endl; else { std::cout<< "Failed " <<std::endl;  return;} 

#define ARE_EQ_CSTR( x, y) \
 if (strcmp(x, y) == 0) std::cout << "Passed" <<std::endl; else { std::cout<< "Failed " <<x <<" != " << y<<std::endl;  return;} 

void TestCtor()
{
	std::cout << "TestCtor:" << std::endl;

	AwesomeType a(5);
	ARE_EQ(5, a.ReadValueAs<int>());
	ARE_EQ(Types::Int, a.GetType());
}

void TestCopyCtor()
{
	std::cout << "TestCopyCtor:" << std::endl;

	AwesomeType a(3);
	AwesomeType b(a);
	ARE_EQ(a.ReadValueAs<int>(), b.ReadValueAs<int>());
	ARE_EQ(a.GetType(), b.GetType());
}

void TestMoveCtor()
{
	std::cout << "TestMoveCtor:" << std::endl;

	AwesomeType a(3);
	AwesomeType b = std::move(a);
	ARE_EQ(a.GetType(), Types::Undefined);
	ARE_EQ(3, b.ReadValueAs<int>());
	ARE_EQ(b.GetType(), Types::Int);
}

void TestAssignmentOperator()
{
	std::cout << "TestAssignmentOperator:" << std::endl;

	AwesomeType a('a');
	AwesomeType b('b');
	a = b;
	ARE_EQ(a.ReadValueAs<char>(), b.ReadValueAs<char>());
	ARE_EQ(a.GetType(), b.GetType());
}

void TestMoveOperator()
{
	std::cout << "TestMoveOperator:" << std::endl;

	AwesomeType a(5.f);
	AwesomeType b('b');
	a =std::move(b);
	ARE_EQ(a.ReadValueAs<char>(),'b');
	ARE_EQ(a.GetType(), Types::Char);
}

void TestTypeDetector()
{
	std::cout << "TestTypeDetector:" << std::endl;

	ARE_EQ(Types::Char, TypeDetector<char>());
}

void TestDestroy()
{
	std::cout << "TestDestroy:" << std::endl;

	AwesomeType ch('c');
	ARE_EQ('c', ch.ReadValueAs<char>());
	ARE_EQ(Types::Char, ch.GetType());

	AwesomeType::DestroyObject(ch);
	ARE_EQ(Types::Undefined, ch.GetType());
}

void TestReadValueAs()
{
	std::cout << "TestReadValueAs:" << std::endl;

	try
	{
		AwesomeType a(5);
		int b = a.ReadValueAs<int>();
		ARE_EQ(5, b);
		char c = a.ReadValueAs<char>();
	}
	catch (BadCast& e)
	{
		std::cout << "Passed" << std::endl;
	}
}

void TestSwap()
{
	std::cout << "TestSwap:" << std::endl;

	AwesomeType a('a');
	AwesomeType b(5);
	AwesomeType::Swap(a, b);
	ARE_EQ(5, a.ReadValueAs<int>());
	ARE_EQ(Types::Int, a.GetType());
	ARE_EQ('a', b.ReadValueAs<char>());
	ARE_EQ(Types::Char, b.GetType());
}

void RunTests()
{
	TestCtor();
	TestCopyCtor();
	TestMoveCtor();
	TestAssignmentOperator();
	TestMoveOperator();
	TestTypeDetector();
	TestDestroy();
	TestReadValueAs();
	TestSwap();
}