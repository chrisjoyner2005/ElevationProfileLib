/* 
 * File:   Tuple.h
 * Author: marvin_smith1
 *
 * Created on March 19, 2012, 4:25 PM
 */

#ifndef TUPLE_H
#define	TUPLE_H


template<typename TP1, typename TP2>
class Pair{
    
    public:
        
        
    private:
            
    
    
};

template<typename TP1, typename TP2, typename TP3>
class Triple{
    
    public:
    
        Triple(){};
        Triple(TP1 const& va):val01(va){}
        Triple(TP1 const& va, TP2 const& vb):val01(va), val02(vb){}
        Triple(TP1 const& va, TP2 const& vb, TP3 const& vc):val01(va), val02(vb), val03(vc){}
        
        TP1  fst()const{  return val01; }
        TP1& fst(){       return val01; }
        
        TP2  snd()const{  return val02; }
        TP2& snd(){       return val02; }
        
        TP3  trd()const{  return val03; }
        TP3& trd(){       return val03; }
        
    private:
        TP1 val01;
        TP2 val02;
        TP3 val03;
        
};



template<typename TP1, typename TP2, typename TP3, typename TP4>
class Quad{
    
    public:
    
        Quad(){};
        Quad(TP1 const& va)
                        :val01(va){}
        Quad(TP1 const& va, TP2 const& vb)
                        :val01(va), val02(vb){}
        Quad(TP1 const& va, TP2 const& vb, TP3 const& vc)
                        :val01(va), val02(vb), val03(vc){}
        Quad(TP1 const& va, TP2 const& vb, TP3 const& vc, TP4 const& vd)
                        :val01(va), val02(vb), val03(vc), val04(vd){}
        
        
        TP1  fst()const{  return val01; }
        TP1& fst(){       return val01; }
        
        TP2  snd()const{  return val02; }
        TP2& snd(){       return val02; }
        
        TP3  trd()const{  return val03; }
        TP3& trd(){       return val03; }
        
        TP4  fth()const{  return val04; }
        TP4& fth(){       return val04; }
        
    private:
        TP1 val01;
        TP2 val02;
        TP3 val03;
        TP4 val04;
    
    
};





#endif	/* TUPLE_H */

