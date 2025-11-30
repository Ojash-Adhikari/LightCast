#ifndef LIGHTSOURCE_H
#define LIGHTSOURCE_H

#include <vector>
#include "Points.h"
#include "Ray.h"
class Square;
class Glass;

class LightSource {
public:
    Points position;
    std::vector<Ray> rays;
    float rayLength; // controls every ray's max length

    LightSource(int numRays = 360, float rayLength = 1.0f);

    void setPosition(float x, float y);
    void setRayLength(float len); // change range at runtime
    void updateRays(const Square& sqr,  const Glass& glass);
    void draw() const;
};

#endif
