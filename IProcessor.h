#pragma once

#include<string>

#include "Constant.h"

class IProcessor
{
public:
  IProcessor ();
  virtual ~IProcessor ();

  virtual std::string
  process (const char* str, int length)
  {
    return std::string (str, length);
  }

  /*true - with begin to end, false with end to begin*/
  virtual bool
  getPosition ()
  {
    return READ_WITH_BEGIN;
  }
};

