#include <yaml-cpp/yaml.h>
#include <nlohmann/json.hpp>
#include "ConfigWriterFactory.h"

int main()
{
	auto cw = ConfigWriterFactory::CreateWriter("testfile.json");
	cw->ReadFile();
	cw->WriteKey("Hello", "World");
	cw->WriteFile();
	cw = ConfigWriterFactory::CreateWriter("testfile.txt");
	cw->ReadFile();
	cw->WriteKey("Hello", "World");
	cw->WriteFile();
	cw = ConfigWriterFactory::CreateWriter("testfile.yaml");
	cw->ReadFile();
	cw->WriteKey("Hello", "World");
	cw->WriteFile();
	return 0;
}