#include "ConfigWriterFactory.h"
#include "iConfigWriter.h"
#include "jsonConfigWriter.h"
#include "yamlConfigWriter.h"
#include "plaintextConfigWriter.h"
#include <string>

IConfigWriter* ConfigWriterFactory::CreateWriter(std::string filename)
{

	
		if (filename.find(".json") != std::string::npos) 
		{
			return new jsonConfigWriter(filename);
		}
		if (filename.find(".yaml") != std::string::npos) 
		{
			return new yamlConfigWriter(filename);
		}
		if (filename.find(".txt") != std::string::npos) 
		{
			return new plaintextConfigWriter(filename);
		}
		return 0;
	
}