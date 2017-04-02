#include <iostream>
#include "AwesomeType.h"
#include "Tests.h"



void main()
{
	AwesomeType a;
	AwesomeType b (3);

	double i = b.ReadValueAs<int>();

	RunTests();

	system("pause");
}
