/* 
 * File:   Interpolation.h
 * Author: marvin_smith1
 *
 * Created on March 15, 2012, 9:40 PM
 */

#ifndef INTERPOLATION_H
#define	INTERPOLATION_H

#include <iostream>
#include <vector>

#include "../enumerations/Quaternion.h"
#include "../enumerations/Vector.h"
#include "../enumerations/Enums.h"

using namespace std;

class Interpolation {
public:
    
    static vec SLERP( vec const& p1, vec const& p2, const double& t);
    static Quaternion SLERP( Quaternion const& p1, Quaternion const& p2, const double& t);
    
    static vector<GeoDDCoordinate> computeIntermediateCoordinates( const GeoDDCoordinate& p1,
                                                                   const GeoDDCoordinate& p2, 
                                                                   const size_t& nPoints);
    
private:

};

#endif	/* INTERPOLATION_H */

