/* 
 * File:   CoordinateUtils.h
 * Author: marvin_smith1
 *
 * Created on March 15, 2012, 11:19 PM
 */

#ifndef COORDINATEUTILS_H
#define	COORDINATEUTILS_H

#include "../enumerations/Enums.h"
#include "../enumerations/Vector.h"
#include "../enumerations/Quaternion.h"

class CoordinateUtils {
public:
    
    static vec Geodetic2Vector( const GeoDDCoordinate& coord );
    static GeoDDCoordinate Vector2Geodetic( const vec& coord );
    
private:

};

#endif	/* COORDINATEUTILS_H */

