/* 
 * File:   CoordinateUtils.cpp
 * Author: marvin_smith1
 * 
 * Created on March 15, 2012, 11:19 PM
 */

#include "CoordinateUtils.h"

vec CoordinateUtils::Geodetic2Vector( const GeoDDCoordinate& coord ){
    
    //compute the transformation, converting degrees to radians
    return vec( cos(coord.first*M_PI/180.0)*sin(coord.second*M_PI/180.0), 
                sin(coord.first*M_PI/180.0),
                cos(coord.first*M_PI/180.0)*cos(coord.second*M_PI/180.0));
    
}

GeoDDCoordinate CoordinateUtils::Vector2Geodetic( const vec& axis ){
    
    double r = axis.mag();
    
    GeoDDCoordinate pt;
    pt.first  = atan2(axis[2], axis[0])*180/M_PI;
    pt.second = acos(axis[1])*180/M_PI;
    return pt;
}