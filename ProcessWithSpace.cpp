#include "ProcessWithSpace.h"

ProcessWithSpace::ProcessWithSpace ()
{
}


ProcessWithSpace::~ProcessWithSpace ()
{
}

std::string
ProcessWithSpace::process (const char* str,int length)
{
  char* tmp_ar = new char[length];

  int i, j = 0;
  for (i = 0; i < length; i++)
    {
      if (str[i] != SPACE)
	{
	  tmp_ar[j] = str[i];
	  j++;
	}
    }

  std::string s (tmp_ar, j);
		
  delete[] tmp_ar;
  
  return s;
}

bool
ProcessWithSpace::getPosition ()
{
  return READ_WITH_BEGIN;
}
