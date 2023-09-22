#pragma once
#include "Creature.hpp"


class Bird : Creature
{
public:
	Bird();
	virtual void Do() override;
	virtual void Draw() override;
};