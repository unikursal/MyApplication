#pragma once

#include<string>
#include<cctype>

#include "IProcessor.h"
#include "Constant.h"

class ProcessWithWord: public IProcessor
{
 private:
  const char SPACE = ' ';

  int copyWord(const char* source, char* target, int tmp_end, int  begin, int length, int i);
public:
  ProcessWithWord ();
  ~ProcessWithWord ();

  bool getPosition ();

  std::string process(const char*, int);
};

