#include "ProcessWithPoint.h"

ProcessWithPoint::ProcessWithPoint ()
{
}


ProcessWithPoint::~ProcessWithPoint ()
{
}

std::string
ProcessWithPoint::process (const char* str, int length)
{
  char* tmp_ar = new char[length];

  int i = 0;
  for (i = 0; i < length; i++)
    {
      if (str[i] == COMMA)
	{
	  tmp_ar[i] = POINT;
	}
      else
	{
	  tmp_ar[i] = str[i];
	}
	
    }

  std::string s(tmp_ar, length);

  delete[] tmp_ar;
  
  return s;
}

bool
ProcessWithPoint::getPosition ()
{
  return READ_WITH_BEGIN;
}
