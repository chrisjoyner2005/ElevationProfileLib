/* 
 * File:   main.cpp
 * Author: ms6401
 *
 * Created on March 14, 2012, 8:49 AM
 */

#include <fstream>
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
    inputPoints.push_back(GeoDDCoordinate(39.320753, -119.232233));
    //inputPoints.push_back(GeoDDCoordinate(39.527222, -119.821944));
    inputPoints.push_back(GeoDDCoordinate(39.320753, -119.264933));
    
    
    vector<ProfileTuple> results = ElevationMap::computeElevationProfile(inputPoints, 200);
    
   // cout << endl << endl << "Result" << endl;
   ///for(size_t i=0; i<results.size(); i++)
   //    cout << results[i].fst().first << ", " << results[i].fst().second << " -> " << results[i].snd() << ", " << results[i].trd() << ", " << results[i].fth() << endl;
   
    ofstream fout;
    fout.open("RESULTS.csv");
    for(size_t i=0; i<results.size(); i++){
        fout << results[i].trd() << ", " << results[i].fth() << endl;
    }
    fout.close();
    
    return 0;
}

