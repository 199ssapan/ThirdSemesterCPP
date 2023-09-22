#pragma once 
#include "Object.hpp"

class Tree : Object
{
public:
	Tree();
	virtual void Do()  override;
	virtual void Draw()  override;
};