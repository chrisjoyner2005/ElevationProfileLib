/* 
 * File:   main.cpp
 * Author: ms6401
 *
 * Created on March 14, 2012, 8:49 AM
 */

#include <iostream>
#include <vector>
#include <iomanip>

#include "enumerations/Enums.h"
#include "enumerations/Quaternion.h"
#include "enumerations/Vector.h"
#include "core/ElevationMap.h"
#include "math/Interpolation.h"
#include "math/CoordinateUtils.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    vector<GeoDDCoordinate> inputPoints;
    inputPoints.push_back(GeoDDCoordinate(39.320753,-119.232233));
    inputPoints.push_back(GeoDDCoordinate(39.540575,-119.8207));
    inputPoints.push_back(GeoDDCoordinate(39.160833, -119.753889));
    
    GeoDDCoordinate p1(  0,   0);
    GeoDDCoordinate p2( 45,  45);
    
    vec pP1 = CoordinateUtils::Geodetic2Vector(p1);
    vec pP2 = CoordinateUtils::Geodetic2Vector(p2);
    
    GeoDDCoordinate a01 = CoordinateUtils::Vector2Geodetic(pP1);
    GeoDDCoordinate a02 = CoordinateUtils::Vector2Geodetic(pP2);
    
    vector<GeoDDCoordinate> inter = Interpolation::computeIntermediateCoordinates(p1, p2, 1);
    cout << endl << endl;
    cout << p1.first << ", " << p1.second << endl;
    for(size_t i=0; i<inter.size(); i++)
        cout << inter[i].first << ", " << inter[i].second << endl;
    cout << p2.first << ", " << p2.second << endl;
    
    //vector<double> elevationProfile = ElevationMap::computeElevationProfile( inputPoints);
    
    //cout << "elevation: " << GDAL_Utilities::singlePointElevation(GeoDDCoordinate(39.320753,-119.232233)) << endl;
    
    //cout << "distance: " << setprecision(9) << GDAL_Utilities::surfaceDistance(GeoDDCoordinate(39.320753,-119.232233),GeoDDCoordinate(39.540575,119.8207));
    
    
    
    return 0;
}

