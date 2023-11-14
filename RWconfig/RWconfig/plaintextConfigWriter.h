#pragma once
#include "iConfigWriter.h"
class plaintextConfigWriter :
    public IConfigWriter
{
public:

	plaintextConfigWriter(std::string filename) : IConfigWriter(filename) {};

	virtual void WriteFile();
	virtual void ReadFile();
};

