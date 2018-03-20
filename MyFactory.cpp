#include "MyFactory.h"


MyFactory::MyFactory ()
{
}


MyFactory::~MyFactory ()
{
}

IProcessor* MyFactory::createProcessor (char param)
{
  IProcessor *ip;
  switch (param)
    {
    case 'A':
      ip = new ProcessWithWord();
      break;
    case 'B':
      ip = new ProcessWithPoint();
      break;
    case 'C':
      ip = new ProcessWithSpace();
      break;
    default :
      ip = nullptr;
    }

  return ip;
}
