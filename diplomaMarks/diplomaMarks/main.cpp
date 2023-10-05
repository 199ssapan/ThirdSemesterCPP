#include <iostream>
#include <vector>
#include "IO.hpp"
#include <Windows.h>


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::string filename = "file.txt";
	std::vector<Student*> stVector = getStudentsVector(filename);
	while (mainMenu(&stVector)) {};
	writeStudentsVectorToFile(stVector, filename);
	deleteStudentsInVector(stVector);
	return 0;
}