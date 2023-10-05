#include "Student.hpp"
#include <iostream>

Student::Student(std::string firstName, std::string secondName, std::string thirdName, std::string age, std::string mark)
{
	this->firstName = firstName;
	this->secondName = secondName;
	this->thirdName = thirdName;
	this->age = age;
	this->mark = mark;
}

Student::Student(Student* student)
{
	this->firstName = student->firstName;
	this->secondName = student->secondName;
	this->thirdName = student->thirdName;
	this->age = student->age;
	this->mark = student->mark;
}

std::string Student::GetFirstName()
{
	return this->firstName;
}

std::string Student::GetSecondName()
{
	return this->secondName;
}

std::string Student::GetThirdName()
{
	return this->thirdName;
}

std::string Student::GetAge()
{
	return this->age;
}

std::string Student::GetMark()
{
	return this->mark;
}
