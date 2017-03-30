#include <iostream>
#include "AwesomeType.h"



void main()
{
	AwesomeType a;
	AwesomeType b (3);


	double i = b.ReadValueAs<int>();

	system("pause");
}