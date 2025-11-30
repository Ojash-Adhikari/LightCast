#include "LightSource.h"
#include <cmath>

LightSource::LightSource(int numRays, float rayLen)
    : position(0.5f, 0.5f), rayLength(rayLen)
{
    rays.reserve(numRays);
    for (int i = 0; i < numRays; ++i)
    {
        float angle = (i * M_PI) / 180.0f; // 360 rays, 1-degree steps
        rays.emplace_back(position, angle, rayLength);
    }
}

void LightSource::setPosition(float x, float y)
{
    position.x = x;
    position.y = y;
    for (auto &ray : rays)
    {
        ray.origin = position;
        ray.length = ray.maxLength; // reset length until cast()
    }
}

void LightSource::setRayLength(float len)
{
    rayLength = len;
    for (auto &ray : rays)
    {
        ray.maxLength = len;
        ray.length = len;
    }
}

void LightSource::updateRays(const Square &sqr,  const Glass &glass)
{
    for (auto &ray : rays)
        ray.cast(sqr, glass);
}

void LightSource::draw() const
{
    for (const auto &ray : rays)
        ray.draw();
}
