#ifndef GLASS_H
#define GLASS_H

#include "Points.h"
#include "Square.h" // reuse structure or polygon if you want

class Glass
{
public:
    Points pts[4]; // rectangle corners
    float refractiveIndex;

    Glass();
    Glass(float x0, float y0, float x1, float y1, float n = 1.5f);

    void draw() const;
    bool isInside(const Points &p) const;
    Glass* drag_glass(Glass* glass, Points* mouse);
};

#endif
