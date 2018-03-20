#pragma once

#include "IProcessor.h"
#include "ProcessWithWord.h"
#include "ProcessWithPoint.h"
#include "ProcessWithSpace.h"

class MyFactory
{
public:
  MyFactory ();
  ~MyFactory ();

  IProcessor* createProcessor (char);
};

