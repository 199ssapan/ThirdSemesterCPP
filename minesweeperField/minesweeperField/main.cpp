#include <iostream>
#include "Field.h"

int main()
{
	Field f = Field(20, 20);
	f.inputCoords(3, 5);
	f.PrintField();
	return 0;
}