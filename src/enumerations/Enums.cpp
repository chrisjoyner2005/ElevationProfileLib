/* 
 * File:   Enums.cpp
 * Author: ms6401
 * 
 * Created on March 14, 2012, 9:16 AM
 */

#include "Enums.h"

bool ProfileTupleFilenameSort::operator()(const ProfileTuple& a, const ProfileTuple& b){
    return (a.snd() < b.snd());
}

bool ProfileTupleDistanceSort::operator()(const ProfileTuple& a, const ProfileTuple& b){
    return (a.trd() < b.trd());
}