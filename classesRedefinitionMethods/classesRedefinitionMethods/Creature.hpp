#pragma once
#include "Object.hpp"

class Creature : Object
{
	
public:
	virtual void Do() = 0;
	virtual void Draw() = 0;
};