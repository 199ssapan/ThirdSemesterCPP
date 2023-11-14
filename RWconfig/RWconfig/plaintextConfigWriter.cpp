#include "plaintextConfigWriter.h"
#include <fstream>


void plaintextConfigWriter::WriteFile()
{
	std::ofstream file(filename);
	for (auto i = this->dict.begin(); i != this->dict.end(); i++)
	{
		file << i->first << ":" << i->second << std::endl;
	}
	file.close();
}

void plaintextConfigWriter::ReadFile()
{
	std::ifstream file(filename);
	for (std::string line; getline(file, line); )
	{
		int pos = line.find(':');
		if (pos == std::string::npos) {
			continue;
		}
		this->dict.emplace(line.substr(0, pos), line.substr(pos + 1));
	}
	file.close();
}