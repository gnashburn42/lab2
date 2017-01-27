#include "ReadFile.h"
#include <iostream>
#include <string>

ReadFile:ReadFile(const char* file_name)
{
   input_file.open(file_name);
   closed = false;
   eof = false;

   return rf;
}

ReadFile::~ReadFile()
{
   close();
   
   delete this;
}

bool ReadFile::eof()
{
   return _eof;
}

void ReadFile::close()
{
   if (!closed)
   {
      input_file.close();
      closed = true;
   }
}

String* ReadFile::readLine()
{
   if (closed) return NULL;
   if (_eof) return NULL;

   string text;
   _eof = !(getline(this->input_file, text));	//check out later

   return new String((const char*) text.c_str());
   
}
