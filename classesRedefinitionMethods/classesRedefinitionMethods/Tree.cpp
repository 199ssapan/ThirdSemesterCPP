#include "Tree.hpp"
#include <iostream>
void Tree::Do()
{
	std::cout << "I am tree!" << std::endl;
}

void Tree::Draw() 
{
    for (int i = 1; i <= 5; ++i) {
        for (int j = 0; j < 5 - i; ++j) {
            std::cout << " ";
        }
        for (int k = 0; k < 2 * i - 1; ++k) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }

    for (int i = 0; i < 5 - 1; ++i) {
        for (int j = 0; j < 5 - 1; ++j) {
            std::cout << " ";
        }
        std::cout << "|" << std::endl;
    }
}

Tree :: Tree(){}