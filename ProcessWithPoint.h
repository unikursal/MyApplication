#pragma once

#include<string>

#include "IProcessor.h"
#include "Constant.h"

class ProcessWithPoint: public IProcessor
{
 private:
  const char  COMMA = ',', POINT = '.';
  
public:
  ProcessWithPoint ();
  ~ProcessWithPoint ();

  bool getPosition ();

  std::string process (const char*, int);
};

