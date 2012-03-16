/* 
 * File:   Vector.h
 * Author: marvin_smith1
 *
 * Created on March 15, 2012, 9:34 AM
 */

#ifndef VECTOR_H
#define	VECTOR_H

#include <iostream>
#include <vector>

using namespace std;

template<typename TP, int N>
class Vector {
public:
    
    /**
     * vector constructor
     */
    explicit Vector(){
        data.resize(N);
        for( size_t i=0; i<N; i++)
            data[i] = 0;
    }
    
    /** 
     * Parameterized Constructor
     */
    explicit Vector(vector<TP> list){
        if( list.size() > N )
            throw string("Error: Invalid input size");
        
        data.resize(N);
        for(size_t i=0; i<list.size(); i++)
            data[i] = list[i];
    }
    
    explicit Vector( const TP& a, const TP& b, const TP& c ){
        data.resize(N);
        data[0] = a;
        data[1] = b;
        data[2] = c;
    }
    
    /**
     * Compute the dot product
     */
    TP dot( const Vector<TP,N>& a)const{
        
        TP sum = 0;
        for(size_t i=0; i<N; i++)
            sum += (*this)[i]*a[i];
        return sum;
    }
    \
    TP mag() const{
        return sqrt(mag2());
    }
    
    TP mag2()const{
        TP val = 0;
        for(size_t i=0; i<N; i++)
            val += (*this)[i]*(*this)[i];
    }
    
    
    /**
     * Read Only Accessor Operator
     * @param idx index
     * @return copy of data
     */
    TP operator[](const size_t& idx)const{
        return data[idx];
    }
    
    /**
     * Read/Write Accessor Operator
     * @param[in] idx index
     * @return reference to data
     */
    TP& operator[](const size_t& idx){
        return data[idx];
    }
    
    
    size_t size()const{
        return N;
    }
    
private:
    vector<TP> data;
    
};

typedef Vector<double,3> vec;


template<typename TP, int N>
ostream& operator << (ostream& ostr, const Vector<TP,N>& vec){
    ostr << "vec( ";
    for(size_t i=0; i<N; i++){
        ostr << vec[i];
        if( i+1 < N)
            ostr << ", ";
    }
    ostr << " )";
    return ostr;
}


vec cross( const vec& a, const vec& b );

double dot( const vec& a, const vec& b );

template<typename TP, int N>
Vector<TP,N> operator + ( const Vector<TP,N>& vA, const Vector<TP,N>& vB ){
    
    Vector<TP,N> outVec;
    for(size_t i=0; i<N; i++)
        outVec[i] = vA[i]+vB[i];
    return outVec;
}

template<typename TP, int N>
Vector<TP,N> operator - ( const Vector<TP,N>& vA, const Vector<TP,N>& vB ){
    
    Vector<TP,N> outVec;
    for(size_t i=0; i<N; i++)
        outVec[i] = vA[i]-vB[i];
    return outVec;
}

template<typename TP, int N>
Vector<TP,N> operator* ( const Vector<TP,N>& vA, const TP& s ){
    
    Vector<TP,N> outVec;
    for(size_t i=0; i<N; i++)
        outVec[i] = vA[i]*s;
    return outVec;
}

template<typename TP, int N>
Vector<TP,N> operator* ( const TP& s, const Vector<TP,N>& vA ){
    
    Vector<TP,N> outVec;
    for(size_t i=0; i<N; i++)
        outVec[i] = vA[i]*s;
    return outVec;
}

template<typename TP, int N>
Vector<TP,N> operator/ ( const Vector<TP,N>& vA, const TP& s ){
    
    Vector<TP,N> outVec;
    for(size_t i=0; i<N; i++)
        outVec[i] = vA[i]/s;
    return outVec;
}

#endif	/* VECTOR_H */

