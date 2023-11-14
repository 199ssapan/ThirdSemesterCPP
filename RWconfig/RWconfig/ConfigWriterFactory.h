#pragma once
#include "iConfigWriter.h"
#include <string>

class ConfigWriterFactory
{
public:
	static IConfigWriter* CreateWriter(std::string filename);
};
