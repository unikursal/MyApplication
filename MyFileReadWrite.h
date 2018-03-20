#pragma once

#include<string>
#include<iostream>
#include<fstream>
#include<cctype>
#include<cstring>

#include "Constant.h"

struct DumpFile
{
  int length_file;
  int begin;
  int end;
  int read_size = -1;
  
  char* buffer;
  int str_len;

  char* tmp_buff;
  int tmp_str_len = 0;
  
  bool
  is_open()
  {
    return (length_file >= 0);
  }

  ~DumpFile()
  {
    if (length_file > 0)
      delete[] buffer;

    if (tmp_str_len > 0)
      delete[] tmp_buff;
  }
};

class MyFileReadWrite
{
 private:
  std::ifstream reader;
  std:: ofstream writer;
  
  std::string pathIn = "example.txt";
  std::string pathOut = "example_out.txt";
  const int READ_SIZE = 8192;

  void modifyBuffer(DumpFile&, bool is_end_file);
  
 public:
  MyFileReadWrite ();
  ~MyFileReadWrite ();

  DumpFile openFile ();
  void closeFile ();
  
  int readFile (DumpFile& d, bool);
  int writeToFile (std::string);
};

