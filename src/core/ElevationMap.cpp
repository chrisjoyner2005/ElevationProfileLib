/* 
 * File:   ElevationMap.cpp
 * Author: ms6401
 * 
 * Created on March 14, 2012, 9:22 AM
 */

#include "ElevationMap.h"

vector<double> ElevationMap::computeElevationProfile( vector<GeoDDCoordinate>const& inputPoints ){
    
    vector<double> output;
    
    //first we need to get a list of files for loading dted
    vector<string> fileList = GDAL_Utilities::computeDTEDFileList(inputPoints);
    
    for(size_t i=0; i<fileList.size(); i++)
        cout << "file: " << fileList[i] << endl;
    
    return output;
}