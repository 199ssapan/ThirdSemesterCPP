#pragma once
#include <string>

class Student
{
private:
	std::string firstName;
	std::string secondName;
	std::string thirdName;
	std::string age;
	std::string mark;
	Student();
public:
	Student(std::string firstName, std::string secondName, std::string thirdName, std::string age, std::string mark);
	Student(Student* student);
	Student(const Student &student);
	std::string GetFirstName();
	std::string GetSecondName();
	std::string GetThirdName();
	std::string GetAge();
	std::string GetMark();
	void printStudent(int i);
};