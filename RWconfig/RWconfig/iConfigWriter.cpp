#include "iConfigWriter.h"
#include <string>

void IConfigWriter::WriteKey(std::string key, std::string value)
{
	if (this->dict.count(key) > 0) {
		this->dict[key] = value;
	}
	else {
		this->dict.emplace(key, value);
	}
}

std::string IConfigWriter::ReadKey(std::string key)
{
	return this->dict.at(key);
}
