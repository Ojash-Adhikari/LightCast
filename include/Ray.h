#ifndef RAY_H
#define RAY_H

#include "Points.h"
class Square;
class Glass;

class Ray
{
public:
    Points origin;
    float angle;     // direction in radians
    float length;    // current drawn length
    float maxLength; // maximum allowed length

    Ray(const Points &origin, float angle, float maxLength = 1.0f);

    void cast(const Square &sqr, const Glass &glass); // computes `length` (<= maxLength)
    void draw() const;

private:
    // checks intersection of this infinite ray with segment p1-p2.
    // returns true and writes hit if intersection is in front of origin (u>=0).
    bool intersectSegment(const Points &p1, const Points &p2, const Points &rayOrigin, Points &hit) const;
};

#endif
