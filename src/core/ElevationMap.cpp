/* 
 * File:   ElevationMap.cpp
 * Author: ms6401
 * 
 * Created on March 14, 2012, 9:22 AM
 */

#include "ElevationMap.h"

vector<ProfileTuple> ElevationMap::computeElevationProfile( vector<GeoDDCoordinate>const& inputPoints, const int nPoints ){
    
    //compute the total distance between points
    double dist = 0;
    vector<double> weights(inputPoints.size(), 0);
    for(size_t i=0; i<inputPoints.size()-1; i++){
        
        //compute weight of coordinate to total system
        weights[i+1] = GDAL_Utilities::surfaceDistance(inputPoints[i], inputPoints[i+1]);
        dist += weights[i+1];
    }
    
    //compute the weight between points as well as the intermediate range
    vector<int> numIntermediatePoints(inputPoints.size(), 0);
    for(size_t i=0; i<inputPoints.size()-1; i++){
        
        //compute weight
        numIntermediatePoints[i] = (weights[i+1]/dist)*nPoints-1;
    
        //compute respective weight
        weights[i+1] += weights[i];
    }
    
    
    //compute the intermediate points 
    vector<ProfileTuple> elevationProfile;
    vector<GeoDDCoordinate> iCoords;
    for(size_t i=0; i<inputPoints.size()-1; i++){
        
        //add first point to elevation profile
        elevationProfile.push_back(ProfileTuple(inputPoints[i],"",weights[i],0));
        
        //compute intermediate points
        iCoords = Interpolation::computeIntermediateCoordinates(inputPoints[i], inputPoints[i+1], numIntermediatePoints[i]);
        
        //add to elevation profile list
        for(size_t j=0; j<iCoords.size(); j++)
            elevationProfile.push_back(ProfileTuple( iCoords[j], "", weights[i]+GDAL_Utilities::surfaceDistance(inputPoints[i], iCoords[j])));
        
    }
    //add final point to elevation profile list
    elevationProfile.push_back(ProfileTuple(inputPoints.back(),"", weights.back()));
    
    //compute filenames for all points
    for(size_t i=0; i<elevationProfile.size(); i++)
        elevationProfile[i].snd() = GDAL_Utilities::computeFilename(elevationProfile[i].fst(), "SRTM");
    
    //cout << "BEFORE SORT" << endl;
    //for(size_t i=0; i<elevationProfile.size(); i++)
    //    cout << elevationProfile[i].fst().first << ", " << elevationProfile[i].fst().second << " -> " << elevationProfile[i].snd() << ", " << elevationProfile[i].trd() << ", " << elevationProfile[i].fth() << endl;
 
    sort( elevationProfile.begin(), elevationProfile.end(), ProfileTupleFilenameSort());
    
    
    //load 
    DTEM_Image * currentImage = NULL;
    
    if( elevationProfile.size() > 0 ){
        currentImage = new DTEM_Image(elevationProfile[0].snd());
        elevationProfile[0].fth() = currentImage->getElevation(elevationProfile[0].fst());
    }
    for(size_t i=1; i<elevationProfile.size(); i++){
        
        if( elevationProfile[i].snd() != currentImage->getFilename() ){
            
            delete currentImage;
            currentImage = new DTEM_Image(elevationProfile[i].snd());
        }
        elevationProfile[i].fth() = currentImage->getElevation(elevationProfile[i].fst());
    }
    
    if( currentImage != NULL)
        delete currentImage;
    
    sort( elevationProfile.begin(), elevationProfile.end(), ProfileTupleDistanceSort());
    
    return elevationProfile;
}