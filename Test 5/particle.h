#ifndef PARTICLE_H
#define PARTICLE_H

#include "point.h"

struct SMovingObject 
{
    int          x, z;             // Coordinates in tile map
    SVector2D    PositionDeltas;   // The position inside the tile
    float        Direction;        // rotation angle in radians
    float        Speed;            // cells/second
};

#endif