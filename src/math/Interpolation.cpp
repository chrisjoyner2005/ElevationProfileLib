/* 
 * File:   Interpolation.cpp
 * Author: marvin_smith1
 * 
 * Created on March 15, 2012, 9:40 PM
 */

#include "Interpolation.h"
#include "CoordinateUtils.h"

vec Interpolation::SLERP( vec const& p1, vec const& p2, const double& t){
 
    Quaternion q1;  q1.real() = 0; q1.imag() = p1;
    Quaternion q2;  q2.real() = 0; q2.imag() = p2;
    return SLERP(q1, q2, t).imag();
}
    
Quaternion Interpolation::SLERP( Quaternion const& p1, Quaternion const& p2, const double& t){
    
    double omega = acos(dot(p1.imag(),p2.imag()));
    
    
    return (sin((1-t)*omega)/sin(omega))*p1 + (sin(t*omega)/sin(omega))*p2;
}


vector<GeoDDCoordinate> Interpolation::computeIntermediateCoordinates( 
                                                                    const GeoDDCoordinate& p1,
                                                                    const GeoDDCoordinate& p2, 
                                                                    size_t const& nPoints){
               
    //create output list
    vector<GeoDDCoordinate> outputList;
    
    //compute the t interval
    double t = 1.0/(nPoints+1);
    double sum = t;
    vec P1 = CoordinateUtils::Geodetic2Vector(p1);
    vec P2 = CoordinateUtils::Geodetic2Vector(p2);
    cout << "t: " << t << " => " << P1 << ", " << P2 << endl;
    
    for(size_t i=0; i<nPoints; i++){
        
        vec pp = SLERP(P1, P2, sum);
        cout << "p1 : " << P1 << endl;
        cout << "SUM: " << sum << "  -> PP: " << pp << endl;
        cout << "p2 : " << P2 << endl;
        
        outputList.push_back( CoordinateUtils::Vector2Geodetic(SLERP(P1, P2, sum)));
        sum += t;
    }
    
    return outputList;
    
}