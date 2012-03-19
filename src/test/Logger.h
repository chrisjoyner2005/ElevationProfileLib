#ifndef __SRC_TEST_LOGGER_H__
#define __SRC_TEST_LOGGER_H__

#include <iostream>
#include <string>
#include <vector>

#include "Color.h"

using namespace std;

class Status{

   public:
      Status();
      Status( const string& f, const int& r, const string& n = "");

      string func_name;
      string note;
      int result;

};
ostream& operator << (ostream& ostr, const Status& stat );

class Logger{

   public:

      void append( const Status& stat );
      
      void print_log( );

      vector<Status> log;
};

#endif
