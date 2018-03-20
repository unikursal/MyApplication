#include<iostream>

#include "Constant.h"
#include "MyFactory.h"
#include "IProcessor.h"
#include "MyFileReadWrite.h"

int
main (int argc, char **argv)
{
  if (argc != 2 || strlen (argv[1]) != 1)
    {
      std::cout<<"Invalid parrameter. Use A, B or C\n";
      return 1;
    }

  MyFactory mf;
  IProcessor *iProc = mf.createProcessor (argv[1][0]);

  if (iProc == nullptr)
    {
      return 2;
    }
  
  MyFileReadWrite mfRW;

  DumpFile dump = mfRW.openFile();

  if (!dump.is_open())
    {
      return 3;
    }


  while (mfRW.readFile(dump, iProc->getPosition()) > 0)
    {
      if (dump.str_len == 0)
	continue;
      
      std::string str = iProc->process(dump.buffer, dump.str_len);

      if (dump.end != 0 && iProc->getPosition () == READ_WITH_END)
	str.append(" ");

      mfRW.writeToFile(str);
    }

  mfRW.closeFile();
    

  delete iProc;
  
  return 0;
}
