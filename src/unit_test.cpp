#include <iostream>

#include "math/TEST_math.h"
#include "test/Logger.h"

using namespace std;

int main( int argc, char* argv[] ){

   Logger logger;

   run_math_tests( logger );

   logger.print_log();

   return 0;
}
