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
    
    GeoDDCoordinate eC(  0,   0);
    GeoDDCoordinate nP( 90,   0);
    GeoDDCoordinate p1( 45, -45);
    GeoDDCoordinate p2(-45, -45);
    
    vec pEC = CoordinateUtils::Geodetic2Vector(eC);
    vec pNP = CoordinateUtils::Geodetic2Vector(nP);
    vec pP1 = CoordinateUtils::Geodetic2Vector(p1);
    vec pP2 = CoordinateUtils::Geodetic2Vector(p2);
    
    GeoDDCoordinate a01 = CoordinateUtils::Vector2Geodetic(pEC);
    GeoDDCoordinate a02 = CoordinateUtils::Vector2Geodetic(pNP);  
    GeoDDCoordinate a03 = CoordinateUtils::Vector2Geodetic(pP1);
    GeoDDCoordinate a04 = CoordinateUtils::Vector2Geodetic(pP2);
    cout << "pec: " << eC.first << ", " << eC.second << "  =  " << a01.first << ", " << a01.second << endl;
    cout << "pec: " << nP.first << ", " << nP.second << "  =  " << a02.first << ", " << a02.second << endl;
    cout << "pec: " << p1.first << ", " << p1.second << "  =  " << a03.first << ", " << a03.second << endl;
    cout << "pec: " << p2.first << ", " << p2.second << "  =  " << a04.first << ", " << a04.second << endl;
    
    vector<GeoDDCoordinate> inter = Interpolation::computeIntermediateCoordinates(eC, nP, 1);
    cout << eC.first << ", " << nP.second << endl;
    for(size_t i=0; i<inter.size(); i++)
        cout << inter[i].first << ", " << inter[i].second << endl;
    cout << nP.first << ", " << nP.second << endl;
    
    //vector<double> elevationProfile = ElevationMap::computeElevationProfile( inputPoints);
    
    //cout << "elevation: " << GDAL_Utilities::singlePointElevation(GeoDDCoordinate(39.320753,-119.232233)) << endl;
    
    //cout << "distance: " << setprecision(9) << GDAL_Utilities::surfaceDistance(GeoDDCoordinate(39.320753,-119.232233),GeoDDCoordinate(39.540575,119.8207));
    
    
    
    return 0;
}

