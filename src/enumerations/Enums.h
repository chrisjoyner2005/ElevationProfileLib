/* 
 * File:   Enums.h
 * Author: ms6401
 *
 * Created on March 14, 2012, 9:16 AM
 */

#ifndef ENUMS_H
#define	ENUMS_H

#include <string>
#include <utility>

#include "../core/Tuple.h"

using namespace std;

typedef pair<double,double> GeoDDCoordinate;

typedef Quad< GeoDDCoordinate, string, double, double> ProfileTuple;

class ProfileTupleFilenameSort{
public:
    bool operator()(const ProfileTuple& a, const ProfileTuple& b);
};

class ProfileTupleDistanceSort{
public:
    bool operator()(const ProfileTuple& a, const ProfileTuple& b);
};


class Enums {
public:
    
private:

};

#endif	/* ENUMS_H */

