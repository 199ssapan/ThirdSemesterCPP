#pragma once
#include "iConfigWriter.h"
#include <yaml-cpp/yaml.h>
class yamlConfigWriter :
    public IConfigWriter
{
public:

	yamlConfigWriter(std::string filename) : IConfigWriter(filename) {};

	virtual void WriteFile();
	virtual void ReadFile();
};

