#pragma once
#include "Creature.hpp"

class Rat : Creature
{
public:
	Rat();
	void virtual Do() override;
	void virtual Draw() override;

};