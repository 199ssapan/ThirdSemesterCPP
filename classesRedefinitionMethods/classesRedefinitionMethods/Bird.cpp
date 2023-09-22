#include "Bird.hpp"
#include <iostream>


void Bird::Do()
{
	std::cout << "I am a bird!" << std::endl;
}

void Bird::Draw()
{
    std::cout << "     \\  /" << std::endl;
    std::cout << "     (o o)" << std::endl;
    std::cout << "    /  V  \\" << std::endl;
    std::cout << "   /   _   \\" << std::endl;
    std::cout << "  /   (_)   \\" << std::endl;
    std::cout << " /___________\\" << std::endl;
    std::cout << "   /       \\" << std::endl;
    std::cout << "  /_________\\" << std::endl;
}