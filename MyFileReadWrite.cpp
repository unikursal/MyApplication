#include "MyFileReadWrite.h"

MyFileReadWrite::MyFileReadWrite ()
{
}


MyFileReadWrite::~MyFileReadWrite ()
{
  if (reader.is_open ())
    reader.close ();

  if (writer.is_open ())
    writer.close ();
}

DumpFile
MyFileReadWrite::openFile()
{
  reader.open(pathIn);
  writer.open(pathOut);

  DumpFile dump;

  if (!reader.is_open ())
    {
      std::cout<<"No such file "<<pathIn<<std::endl;
      dump.length_file = -1;
      return dump;
    }

  if (!writer.is_open ())
    {
      std::cout<<"Could not open/create file "<<pathOut<<std::endl;
      dump.length_file = -2;
      return dump;
    }

  reader.seekg (0, reader.end);
  dump.length_file = reader.tellg();
  
  reader.seekg (0, reader.beg);

  if (reader.fail () || reader.bad ())
    {
      std::cout<<"Error in seekg\n";
      dump.length_file = -3;
      return dump;
    }

  if (dump.length_file == 0)
    {
      std::cout<<"File is empty\n";
      return dump;
    }

  if (dump.length_file < READ_SIZE)
    {
      dump.read_size = dump.length_file;
      dump.begin = 0;
    }
  else
    {
      dump.read_size = READ_SIZE;
      dump.begin = dump.length_file - (dump.length_file % dump.read_size);
    }

  dump.buffer = new char[dump.read_size];    
  
  dump.end = dump.length_file;

  return dump;
}

void
MyFileReadWrite::closeFile ()
{
  if (reader.is_open ())
    reader.close ();

  if (writer.is_open ())
    writer.close ();
}

int
MyFileReadWrite::readFile (DumpFile& dump, bool position)
{  
    if (position == READ_WITH_BEGIN)
    {
      int read;
      
      reader.read(dump.buffer, dump.read_size);
      read = reader.gcount();

      if (reader.eof () && read == 0)
	{
	  return -1;
	}

      dump.str_len = read;
      
      return read;
    }
    
    if (dump.end == 0)
      {
	return -1;
      }
    
    int read, read_size = dump.end - dump.begin;
    reader.seekg (dump.begin, reader.beg);

    if (reader.fail () || reader.bad ())
      {
	std::cout<<"Error in seekg\n";
	return -2;
      }

    reader.read (dump.buffer, read_size);
    read = reader.gcount ();

    dump.end = dump.begin;
    dump.begin -= dump.read_size;

    dump.str_len = read;

    bool b = (dump.end == 0) ? true: false;

    modifyBuffer(dump, b);
    
    return read;
}

void
MyFileReadWrite::modifyBuffer(DumpFile& dump, bool is_end_file)
{
  int i, n = -1;

  if (is_end_file)
    {
      n = 0;
    }
  else
    {
      for (i = 0; i < dump.str_len; i++)
	{
	  char c = dump.buffer[i];
	  if (!(isdigit (c) || isalpha (c)))
	    {	      
	      n = i;
	      break;
	    }
	}
    }

  
  /*
    Begin of word is found
   */
  if (n >= 0)
    { 
      int len_new_buff = dump.str_len - n + dump.tmp_str_len;
      char* point_delimiter = dump.buffer + n;

      int allocate = len_new_buff > dump.read_size ? len_new_buff : dump.read_size;
      char* t_buff = new char[allocate];

      int j, size_for_copy = dump.str_len - n;

      if (size_for_copy > 0)
	memcpy(t_buff, point_delimiter, size_for_copy);

      if (dump.tmp_str_len > 0)
	{
	  char* point_t_buff = t_buff + size_for_copy;
      
	  memcpy(point_t_buff, dump.tmp_buff, dump.tmp_str_len);
	     
	  delete[] dump.tmp_buff;
	  dump.tmp_str_len = 0;
	}
  
      if (n > 0)
	{
	  dump.tmp_buff = new char[n];
	  dump.tmp_str_len = n;

	  memcpy(dump.tmp_buff, dump.buffer, n);
	}

      delete[] dump.buffer;

      dump.buffer = t_buff;
      dump.str_len = len_new_buff;
    }
  else
    {
      int len_new_buff = dump.str_len + dump.tmp_str_len;
      char *t_buff = new char[len_new_buff];

      memcpy(t_buff, dump.buffer, dump.str_len);

      if (dump.tmp_str_len > 0)
	{
	  char* offset_buff = t_buff + dump.str_len;
	  memcpy(offset_buff, dump.tmp_buff, dump.tmp_str_len);

	  delete[] dump.tmp_buff;
	}
      
      dump.str_len = 0;

      dump.tmp_buff = t_buff;
      dump.tmp_str_len = len_new_buff;
    }
}

int
MyFileReadWrite::writeToFile (std::string s)
{
  writer << s; 
}


