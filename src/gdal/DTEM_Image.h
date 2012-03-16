/* 
 * File:   DTEM_Image.h
 * Author: marvin_smith1
 *
 * Created on March 14, 2012, 3:27 PM
 */

#ifndef DTEM_IMAGE_H
#define	DTEM_IMAGE_H

#include <gdal_priv.h>
#include <cpl_conv.h>

#include <iostream>
#include <string>

#include "../enumerations/Enums.h"

using namespace std;

class DTEM_Image {
public:
    
    DTEM_Image(string const& fname);
    
    double getElevation( const GeoDDCoordinate& pnt );
    
private:
    
    void remove_holes();
    
    string filename;
    
    GDALDataset *poDataset;
    GDALRasterBand *poBand;
    
    int nBlockXSize;
    int nBlockYSize;
    
    int nXSize;
    int nYSize;
    
    double adfGeoTransform[6];
    double ** elevationProfile;
    
};

#endif	/* DTEM_IMAGE_H */

