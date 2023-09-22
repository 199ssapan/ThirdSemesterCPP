#pragma once 
#include "Object.hpp"

class Tree : Object
{
public:
	virtual void Do() const override;
	virtual void Draw() const override;
};