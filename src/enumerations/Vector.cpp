#include "Vector.h"

/**
 * Cross product between two vectors
 * @param a first vector
 * @param b second vector
 * @return cross product vector
 */
vec cross( const vec& a, const vec& b ){
    
    return vec( a[1]*b[2] - a[2]*b[1], a[2]*b[0] - a[0]*b[2], a[0]*b[1] - a[1]*b[0]);
}

double dot( const vec& a, const vec& b ){
    
    double sum = 0;
    for(size_t i=0; i<a.size(); i++)
        sum += a[i]*b[i];
    
    return sum;
}
