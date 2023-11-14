#include "jsonConfigWriter.h"
#include <nlohmann/json.hpp>
#include <fstream>


void jsonConfigWriter::WriteFile()
{
	std::ofstream f(filename);
	nlohmann::json object = nlohmann::json::basic_json();
	for (auto i = this->dict.begin(); i != this->dict.end(); i++)
	{
		object.emplace(i->first, i->second);
	}
	f << object.dump();
	f.close();
}

void jsonConfigWriter::ReadFile()
{
	std::ifstream f(filename);
	nlohmann::json object = nlohmann::json::parse(f);
	for (auto i = object.begin(); i != object.end(); i++)
	{
		this->dict.emplace(i.key(), i.value());
	}
	f.close();
}