#pragma once
#include <string>
#include <map>

class IConfigWriter
{
public:
	void virtual WriteFile() = 0;
	void virtual ReadFile() = 0;
	std::string ReadKey(std::string key);
	void WriteKey(std::string, std::string);
protected:
	std::map<std::string, std::string> dict;
	std::string filename;
	IConfigWriter(std::string filename)
	{
		this->dict = std::map<std::string, std::string>();
		this->filename = filename;
	}
};