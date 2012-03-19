#include "TEST_math.h"

void run_math_tests( Logger& log ){

   log.append( TEST_Geodetic2Vector() );

}

Status TEST_Geodetic2Vector( ){

   string func_name = "Geodetic2Vector";

   GeoDDCoordinate pt01(  0,  0);
   GeoDDCoordinate pt02( 45, 45);
   GeoDDCoordinate pt03( 90, 90);

   vec p01 = CoordinateUtils::Geodetic2Vector(pt01);
   vec p02 = CoordinateUtils::Geodetic2Vector(pt02);
   vec p03 = CoordinateUtils::Geodetic2Vector(pt03);

   if( norm( p01, vec(0,0,1)) > 0.01 )
      return Status( func_name, 0, "Vector has invalid value");
   
   if( norm( p03, vec(0,1,0)) > 0.01 )
      return Status( func_name, 0, "Vector has invalid value");

   return Status(func_name, 1, "");
}
