#include "Rat.hpp"
#include <iostream>

void Rat::Do() 
{
	std::cout << "I am Rat!" << std::endl;
}

void Rat::Draw() 
{
    std::cout << "   \\/" << std::endl;
    std::cout << "   (-)O" << std::endl;
    std::cout << "   / | \\" << std::endl;
    std::cout << "   / |  \\" << std::endl;
    std::cout << "  / / \\  \\" << std::endl;
    std::cout << " (   |   )" << std::endl;
    std::cout << "  \\__|__/" << std::endl;
}

Rat :: Rat(){}