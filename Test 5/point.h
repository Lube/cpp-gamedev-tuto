#ifndef POINT_H
#define POINT_H

#include <math.h> 

struct SPoint2D 
{ 
    float x, y;
};

struct SVector2D
{ 
    float x, y;

    SVector2D operator + ( const SVector2D& other ) const
    {   
        SVector2D result;
        result.x = x + other.x;
        result.y = y + other.y;
        return result;
    }

    void Scale( float _scalar ) 
    {   
        x *= _scalar; 
        y *= _scalar;
    };

    double angleWith (SVector2D destiny) {
        return atan2(destiny.y, destiny.x) - atan2(y, x);
    };

    SVector2D getVector (double direction) {
        return SVector2D(cos(direction), sin(direction));
    };

    SVector2D(){ /* do nothing */ };
    SVector2D( float _x, float _y ){ x = _x; y = _y; };
};

#endif