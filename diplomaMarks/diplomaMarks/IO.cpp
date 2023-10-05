#include "IO.hpp"
#include <iostream>
#include <fstream>
#include "Student.hpp"
#include <string>
#include <vector>
#include <conio.h>
#include <algorithm>

std::vector<Student*> getStudentsVector(std::string filename)
{
	std::vector<Student*> stVector;
	std::ifstream inputFile(filename);
	if (!inputFile.is_open())
	{
		std::cout << "File did not opened" << std::endl;
		exit(1);
	}
	std::string lineToHandle;
	while (std::getline(inputFile, lineToHandle))
	{
		std::vector<std::string> personData = split(lineToHandle);
		Student* student = new Student(personData[0], personData[1], personData[2], personData[3], personData[4]);
		stVector.push_back(student);
	}
	inputFile.close();
	return stVector;
}

void writeStudentsVectorToFile(std::vector<Student*> stVector, std::string filename)
{
	std::ofstream outputFile(filename);
	if (!outputFile.is_open()) {
		std::cout << "File did not opened" << std::endl;
		exit(1);
	}
	for (int i = 0; i < stVector.size(); i++)
	{
		outputFile << stVector[i]->GetFirstName() << " ";
		outputFile << stVector[i]->GetSecondName() << " ";
		outputFile << stVector[i]->GetThirdName() << " ";
		outputFile << stVector[i]->GetAge() << " ";
		outputFile << stVector[i]->GetMark() << std::endl;
	}
	outputFile.close();
}

std::vector<std::string> split(std::string str) 
{
	std::vector<std::string> words;
	size_t start = 0;
	size_t end = str.find(' ');
	while (end != std::string::npos) {
		words.push_back(str.substr(start, end - start));
		start = end + 1;
		end = str.find(' ', start);
	}
	words.push_back(str.substr(start));
	return words;
}

void deleteStudentsInVector(std::vector<Student*> stVector)
{
	for (Student* st : stVector)
	{
		delete st;
	}
}

void addStudent(std::vector<Student*>* stVector)
{
	std::string firstname, secondname, thirdname, age, mark;
	std::cout << "Введите фамилию" << std::endl;
	std::cin >> firstname;
	std::cout << "Введите имя" << std::endl;
	std::cin >> secondname;
	std::cout << "Введите отчество" << std::endl;
	std::cin >> thirdname;
	std::cout << "Введите возраст" << std::endl;
	std::cin >> age;
	std::cout << "Введите оценку" << std::endl;
	std::cin >> mark;
	Student* student = new Student(firstname, secondname, thirdname, age, mark);
	stVector->push_back(student);
}

void deleteStudent(std::vector<Student*>* stVector)
{
	int indexToRemove;
	std::cout << "Введите номер студента, которого хотите удалить:\t";
	std::cin >> indexToRemove;
	indexToRemove--;
	if (indexToRemove >= 0 && indexToRemove < stVector->size()) {
		stVector->erase(stVector->begin() + indexToRemove);
	}
}

int mainMenu(std::vector<Student*>* stVector)
{
	system("cls");
	for (int i = 0; i < stVector->size(); i++)
	{
		(*stVector)[i]->printStudent(i);
	}
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "1. Добавить студента" << std::endl;
	std::cout << "2. Удалить студента" << std::endl;
	std::cout << "3. Сортировать по фамилии" << std::endl;
	std::cout << "4. Сортировать по имени" << std::endl;
	std::cout << "5. Сортировать по отчеству" << std::endl;
	std::cout << "6. Сортировать по возрасту" << std::endl;
	std::cout << "7. Сортировать по оценке" << std::endl;
	std::cout << "8. Выход" << std::endl;
	char command = _getch();
	switch (command)
	{
	case '1':
		addStudent(stVector);
		break;
	case '2':
		deleteStudent(stVector);
		break;
	case '3':
		std::sort(stVector->begin(), stVector->end(), [](Student* a, Student* b)
			{
				return a->GetFirstName() < b->GetFirstName();
			});
		break;
	case '4':
		std::sort(stVector->begin(), stVector->end(), [](Student* a, Student* b)
			{
				return a->GetSecondName() < b->GetSecondName();
			});
		break;
	case '5':
		std::sort(stVector->begin(), stVector->end(), [](Student* a, Student* b)
			{
				return a->GetThirdName() < b->GetThirdName();
			});
		break;
	case '6':
		std::sort(stVector->begin(), stVector->end(), [](Student* a, Student* b)
			{
				int aint = std::stoi(a->GetAge());
				int bint = std::stoi(b->GetAge());
				return aint < bint;
			});
		break;
	case '7':
		std::sort(stVector->begin(), stVector->end(), [](Student* a, Student* b)
			{
				return a->GetMark() < b->GetMark();
			});
		break;
	case '8':
		return 0;
	}
	return 1;
}

void Student::printStudent(int i)
{
	std::cout << i + 1 << " ";
	std::cout << this->firstName << " ";
	std::cout << this->secondName << " ";
	std::cout << this->thirdName << " ";
	std::cout << this->age << " ";
	std::cout << this->mark << std::endl;
}

