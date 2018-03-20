#include "ProcessWithWord.h"


ProcessWithWord::ProcessWithWord ()
{
}


ProcessWithWord::~ProcessWithWord ()
{
}

std::string
ProcessWithWord::process (const char* str, int length)
{
  char* tmp_ar = new char[length];
  int i, begin = 0,  tmp_end = length;

  for (i = 0; i < length; i++)
    {
      if (isdigit(str[i]) || isalpha(str[i]))
	continue;

      if (begin < i)
	{
	  tmp_end = copyWord (str, tmp_ar,  tmp_end, begin, length, i);
	  
	  begin = i;
	}
     
	begin++;
    }

  if (begin < length)
    {
      tmp_end = copyWord (str, tmp_ar, tmp_end, begin, length, length);
    }
  
  char* ptr = tmp_ar + tmp_end;
  std::string s (ptr, (length - tmp_end));

  delete[] tmp_ar;
  
  return s;
}

int
ProcessWithWord::copyWord (const char* source, char* target,  int tmp_end, int begin, int length, int i)
{
  if (tmp_end != length)
    {
      tmp_end -= 1;
      target[tmp_end] = SPACE;
    }

  int size_word = i - begin, j;
  int begin_write = tmp_end - size_word;
  int k  = begin_write;

  for (j = begin; j < i; j++)
    {
      target[k] = source[j];
      k++;
    }

  return begin_write;
}


bool
ProcessWithWord::getPosition ()
{
  return READ_WITH_END;
}
