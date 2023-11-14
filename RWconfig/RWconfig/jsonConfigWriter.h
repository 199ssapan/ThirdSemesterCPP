#pragma once
#include "iConfigWriter.h"
#include <string>
class jsonConfigWriter : public IConfigWriter
{
public:
    jsonConfigWriter(std::string filename) : IConfigWriter(filename) {};
    virtual void WriteFile() override;
    virtual void ReadFile() override;
};

