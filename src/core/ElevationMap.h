/* 
 * File:   ElevationMap.h
 * Author: ms6401
 *
 * Created on March 14, 2012, 9:22 AM
 */

#ifndef ELEVATIONMAP_H
#define	ELEVATIONMAP_H

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

#include "../enumerations/Enums.h"
#include "../gdal/GDAL_Utilities.h"
#include "../math/Interpolation.h"

using namespace std;

class ElevationMap {
public:
    static vector<ProfileTuple> computeElevationProfile( vector<GeoDDCoordinate>const& inputPoints, const int numpoints);
    
private:

};

#endif	/* ELEVATIONMAP_H */

