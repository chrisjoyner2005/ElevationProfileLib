/* 
 * File:   GDAL_Utilities.cpp
 * Author: ms6401
 * 
 * Created on March 14, 2012, 9:41 AM
 */

#include "GDAL_Utilities.h"

vector<string> GDAL_Utilities::computeDTEDFileList(vector<GeoDDCoordinate>const& inputPoints) {

    vector<string> fileList;
    const int max_steps = 1000;
    
    /**
     * List of steps to complete
     * 
     * 1. Compute intermediate points to link waypoints
     */
    double distance = 0;
    for(size_t i=0; i<inputPoints.size()-1; i++)
        distance += GDAL_Utilities::surfaceDistance(inputPoints[i], inputPoints[i+1]);
    
    /**
     * 2. compute interval between points and start interpolating 
     */
    double step = distance/max_steps;
    
    
    
    

    int latMin = (inputPoints[0].first >= 0) ? floor(inputPoints[0].first) : ceil(inputPoints[0].first);
    int latMax = (inputPoints[0].first >= 0) ? floor(inputPoints[0].first) : ceil(inputPoints[0].first);
    int lonMin = (inputPoints[0].second >= 0) ? floor(inputPoints[0].second) : ceil(inputPoints[0].second);
    int lonMax = (inputPoints[0].second >= 0) ? floor(inputPoints[0].second) : ceil(inputPoints[0].second);

    for (size_t i = 0; i < inputPoints.size(); i++) {
        if (latMin > inputPoints[i].first) latMin = inputPoints[i].first;
        if (latMax < inputPoints[i].first) latMax = inputPoints[i].first;
        if (lonMin > inputPoints[i].second) lonMin = inputPoints[i].second;
        if (lonMax < inputPoints[i].second) lonMax = inputPoints[i].second;
    }

    int latDiff = latMax - latMin;
    int lonDiff = lonMax - lonMin;

    /**
     * 3. Convert difference into list of strings
     */
    vector<string> diffList;
    stringstream sin;

    for (int i = latMin; i < latMax; i++) {
        cout << "Val: " << i << endl;

    }

    cout << "difference: " << latDiff << ", " << lonDiff << endl;


    return fileList;
}

double GDAL_Utilities::singlePointElevation(GeoDDCoordinate const& coord) {

    //compute filename for object
    string filename = computeFilename(coord, "SRTM");

    //create DTEM Image Object
    DTEM_Image* dtem = new DTEM_Image(filename);

    double maxElevation = dtem->getElevation(coord);

    return maxElevation;
}

string GDAL_Utilities::computeFilename(GeoDDCoordinate const& point, const string& type) {

    //compute floor values
    int minX = floor(point.second);
    int minY = floor(point.first);
    char hX, hY;

    if (minX < 0) {
        minX = fabs(minX);
        hX = 'W';
    } else
        hX = 'E';
    if (minY < 0) {
        minY = fabs(minY);
        hY = 'S';
    } else
        hY = 'N';

    //construct output
    string tx, ty;
    stringstream sin;
    sin << minY;
    sin >> ty;
    string filename = hY + ty;
    sin.clear();
    sin.str("");
    sin << minX;
    sin >> tx;
    filename += hX + tx;

    if (type == "SRTM")
        filename += ".hgt";

    cout << "FILENAME: " << filename << endl;
    return filename;
}

double GDAL_Utilities::surfaceDistance(GeoDDCoordinate const& p1, GeoDDCoordinate const& p2) {

    double a = 6378137.0;
    double f = 1 / 298.257223563;
    double b = (1-f)*a;
    
    double U1 = atan((1 - f) * tan(p1.first*M_PI/180.0));
    double U2 = atan((1 - f) * tan(p2.first*M_PI/180.0));

    double L = p2.second*M_PI/180.0 - p1.second*M_PI/180.0;
    double lambda = L;
    double sigma;
    double sinA, cos2A, cos2sigM, C, lambdaP;

    //start looping
    double sinSig = sqrt(pow(cos(U2) * sin(lambda), 2) + pow(cos(U1) * sin(U2) - sin(U1) * cos(U2), 2));
    double cosSig = sin(U1) * sin(U2) + cos(U1) * cos(U2) * cos(lambda);
    sigma = atan2(sinSig, cosSig);
    sinA = cos(U1) * cos(U2) * sin(lambda) / sinSig;
    cos2A = 1 - sinA * sinA;
    cos2sigM = cosSig - 2 * sin(U1) * sin(U2) / cos2A;
    C = (f / 16) * cos2A * (4 * f * (4 - 3 * cos2A));
    lambdaP = L + (1 - C) * f * sinA * (sigma + C * sinSig * (cos2sigM + C * cosSig * (-1 + 2 * cos2sigM * cos2sigM)));

            //end of loop
            double u2 = cos2A * (a * a - b * b) / (b * b);

            double A = 1 + u2 / 16384 * (4096 + u2 * (-768 + u2 * (320 - 175 * u2)));
            double B = u2 / 1024 * (256 + u2 * (-128 + u2 * (74 - 47 * u2)));

            double dSig = B * sinSig * (cos2sigM + (B / 4)*(cosSig * (-1 + 2 * cos2sigM * cos2sigM) - (B / 6) * cos2sigM * (-3 + 4 * sinSig * sinSig)*(-3 + 4 * cos2sigM * cos2sigM)));

            double s = b * A * (sigma - dSig);

    return s;

}