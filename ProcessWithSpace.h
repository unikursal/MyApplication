#pragma once

#include<string>

#include "IProcessor.h"
#include "Constant.h"

class ProcessWithSpace: public IProcessor
{
 private:
  const char SPACE = ' ';
public:
  ProcessWithSpace ();
  ~ProcessWithSpace ();

  bool getPosition ();

  std::string process (const char*, int);
};

