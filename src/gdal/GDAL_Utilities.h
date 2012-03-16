/* 
 * File:   GDAL_Utilities.h
 * Author: ms6401
 *
 * Created on March 14, 2012, 9:41 AM
 */

#ifndef GDAL_UTILITIES_H
#define	GDAL_UTILITIES_H

#include <gdal_priv.h>
#include <cpl_conv.h>

#include <iostream>
#include <cmath>
#include <sstream>
#include <string>
#include <vector>

#include "../enumerations/Enums.h"
#include "DTEM_Image.h"

using namespace std;

class GDAL_Utilities {
public:
    
    static vector<string> computeDTEDFileList( vector<GeoDDCoordinate>const& inputPoints );
    
    static double singlePointElevation( GeoDDCoordinate const& coord );
    
    static string computeFilename(const GeoDDCoordinate& coord, const string& type);
    
    static double surfaceDistance(const GeoDDCoordinate& p1, const GeoDDCoordinate& p2);
    
private:

};

#endif	/* GDAL_UTILITIES_H */

