#include "AwesomeType.h"
#include "Tests.h"
#include <iostream>


void main()
{
	AwesomeType a;
	AwesomeType b (3);

	double i = b.ReadValueAs<int>();

	RunTests();

	system("pause");
}
