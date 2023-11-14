#include "yamlConfigWriter.h"
#include <fstream>

void yamlConfigWriter::WriteFile()
{
	std::ofstream f(filename);
	auto config = YAML::Node();
	for (auto i = this->dict.begin(); i != this->dict.end(); i++)
	{
		config.force_insert<std::string, std::string>(i->first, i->second);
	}
	f << YAML::Dump(config);
	f.close();
}

void yamlConfigWriter::ReadFile()
{
	auto config = YAML::LoadFile(filename);
	for (auto i = config.begin(); i != config.end(); i++)
	{
		this->dict.emplace(i->first.as<std::string>(), i->second.as<std::string>());
	}
}
