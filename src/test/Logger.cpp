#include "Logger.h"

Status::Status():func_name(""),note(""), result(-1){}

Status::Status( const string& f, const int& r, const string& n):
         func_name(f), note(n), result(r){}

ostream& operator << (ostream& ostr, const Status& stat ){
   ostr << Color(BLUE) << "Function: " << Color(GREEN) << stat.func_name << Color(BLUE) << ", Result: ";
   if( stat.result == 1 )
      ostr << Color(GREEN) << "PASSED";
   else
      ostr << Color(RED) << "FAILED";
   ostr << ", " << stat.note << color_end;
   return ostr;
}


void Logger::append( const Status& stat ){
   log.push_back(stat);
}

void Logger::print_log( ){

   cout << endl;
   cout << "Log Status" << endl;
   cout << endl;
   for( size_t i=0; i<log.size(); i++)
      cout << log[i] << endl;

}

