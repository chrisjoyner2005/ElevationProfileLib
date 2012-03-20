/* 
 * File:   DTEM_Image.cpp
 * Author: marvin_smith1
 * 
 * Created on March 14, 2012, 3:27 PM
 */

#include "DTEM_Image.h"

DTEM_Image::DTEM_Image(const string& fname) {

    filename = fname;

    //load GDAL
    GDALAllRegister();

    poDataset = (GDALDataset *) GDALOpen(filename.c_str(), GA_ReadOnly);
    if (poDataset == NULL) {
        throw string("Error: Dataset is NULL");
    }

    //load raster band
    poBand = poDataset->GetRasterBand(1);
    poBand->GetBlockSize(&nBlockXSize, &nBlockYSize);
    poDataset->GetGeoTransform(adfGeoTransform);

    //load size
    nXSize = poBand->GetXSize();
    nYSize = poBand->GetYSize();

    //create data storage
    elevationProfile = new double*[nXSize];
    for (int i = 0; i < nXSize; i++) {
        elevationProfile[i] = new double[nYSize];
    }

    //begin scanning lines
    float *pafScanline;

    pafScanline = (float *) CPLMalloc(sizeof (float) *nXSize);

    //iterate through each row
    for (int i = 0; i < nYSize; i++) {

        poBand->RasterIO(GF_Read, 0, i, nXSize, 1,
                pafScanline, nXSize, 1, GDT_Float32,
                0, 0);

        for (int j = 0; j < nXSize; j++) {
            elevationProfile[j][i] = pafScanline[j];
        }
    }

    //clean up holes
    remove_holes();
}

double DTEM_Image::getElevation(const GeoDDCoordinate & pnt) {

    //compute hemisphere
    bool xH, yH;
    if (pnt.first < 0) yH = false;
    else yH = true;

    if (pnt.second < 0) xH = false;
    else xH = true;

    //compute scale for point
    int valX, valY;
    if( xH == false )
        valX = (pnt.second - floor(pnt.second)) * nXSize; // * (fabs(adfGeoTransform[1]));
    else
        valX = (1-(pnt.second - floor(pnt.second))) * nXSize; // * (fabs(adfGeoTransform[1]));
    
    if( yH == false )
        valY = (pnt.first - floor(pnt.first)) * nYSize; // * (fabs(adfGeoTransform[5]));
    else
        valY = (1 - (pnt.first - floor(pnt.first))) * nYSize; // * (fabs(adfGeoTransform[5]));

    return elevationProfile[valX][valY];
}

void DTEM_Image::remove_holes() {

    //iterate over image, taking the median of the window
    double sum;
    int cnt;
    for (int i = 0; i < nXSize; i++)
        for (int j = 0; j < nYSize; j++) {

            //only fix if the pixel is invalid
            if (elevationProfile[i][j] < -10000) {
                
                //iterate over sub window, taking average of valid windows
                sum = 0;
                cnt = 0;
                for (int x = i - 2; x <= i + 2; x++)
                    for (int y = j - 2; y <= j + 2; y++) 
                        if( x > 0 && y > 0 && x < nXSize && y < nYSize && elevationProfile[x][y] > -10000) {
                            sum += elevationProfile[x][y];
                            cnt++;
                        }
                if(cnt < 1 )
                    cnt = 1;
                sum = sum/cnt;
                    
                elevationProfile[i][j] = sum;
            }

        }


}

string DTEM_Image::getFilename() const{
    return filename;
}