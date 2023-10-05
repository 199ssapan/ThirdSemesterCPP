#pragma once
#include "Student.hpp"
#include <vector>
std::vector<Student*> getStudentsVector(std::string filename);
std::vector<std::string> split(std::string str);
void addStudent(std::vector<Student*>* stVector);
void writeStudentsVectorToFile(std::vector<Student*> stVector, std::string filename);
void deleteStudent(std::vector<Student*>* stVector);
int mainMenu(std::vector<Student*>* stVector);
void deleteStudentsInVector(std::vector<Student*> stVector);
