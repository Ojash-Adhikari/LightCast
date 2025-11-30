#include "Ray.h"
#include "Square.h"
#include <GL/glut.h>
#include <cmath>
#include <limits>
#include "Glass.h"

Ray::Ray(const Points &o, float a, float m)
    : origin(o), angle(a), length(m), maxLength(m) {}

void Ray::cast(const Square &sqr, const Glass &glass)
{
    const float EPSILON = 1e-4f;

    // Saving initial state after reflection
    Points initialOrigin = origin;
    float initialAngle = angle;

    Points rayStart = origin;
    float remainingLength = maxLength;
    float currentAngle = angle;
    float currentMedium = 1.0f; // start in air

    rayStart.x += EPSILON * cos(currentAngle);
    rayStart.y += EPSILON * sin(currentAngle);

    while (remainingLength > 0.0f)
    {
        float dx = cos(currentAngle);
        float dy = sin(currentAngle);

        // --- find closest intersection ---
        float closestDist = remainingLength;
        Points hitPoint;
        bool hitGlassEdge = false;
        bool hitSquareEdge = false;
        int edgeIndex = -1;

        // check square
        for (int i = 0; i < 4; ++i)
        {
            Points temp;
            if (intersectSegment(sqr.pts[i], sqr.pts[(i + 1) % 4], rayStart, temp))
            {
                float dist = std::hypot(temp.x - rayStart.x, temp.y - rayStart.y);
                if (dist < 1e-6f)
                    continue;
                else if (dist < closestDist)
                {
                    closestDist = dist;
                    hitPoint = temp;
                    hitSquareEdge = true;
                    hitGlassEdge = false;
                }
            }
        }

        // check glass
        for (int i = 0; i < 4; ++i)
        {
            Points temp;
            if (intersectSegment(glass.pts[i], glass.pts[(i + 1) % 4], rayStart, temp))
            {
                float dist = std::hypot(temp.x - rayStart.x, temp.y - rayStart.y);
                if (dist < closestDist)
                {
                    closestDist = dist;
                    hitPoint = temp;
                    hitGlassEdge = true;
                    hitSquareEdge = false;
                    edgeIndex = i;
                }
            }
        }

        length = maxLength - remainingLength + closestDist;

        if (hitSquareEdge || closestDist >= remainingLength)
        {
            // hit square or nothing within remaining length → stop
            break;
        }

        if (hitGlassEdge)
        {
            // --- compute normal for axis-aligned edge ---
            Points p1 = glass.pts[edgeIndex];
            Points p2 = glass.pts[(edgeIndex + 1) % 4];
            Points edgeVec = Points(p2.x - p1.x, p2.y - p1.y);
            Points normal = (fabs(edgeVec.x) > fabs(edgeVec.y)) ? Points(0, (edgeVec.y > 0 ? -1 : 1)) : Points((edgeVec.x > 0 ? -1 : 1), 0);

            // determine entering/exiting
            float n1 = currentMedium;
            float n2 = (currentMedium == 1.0f) ? glass.refractiveIndex : 1.0f;

            // incoming vector
            Points I = Points(dx, dy);
            float dot = I.x * normal.x + I.y * normal.y;

            // Snell's law
            float cosTheta1 = -dot;
            float sinTheta2 = n1 / n2 * sqrtf(std::max(0.0f, 1.0f - cosTheta1 * cosTheta1));

            if (sinTheta2 > 1.0f)
            {
                // total internal reflection
                currentAngle = atan2(I.y - 2 * dot * normal.y, I.x - 2 * dot * normal.x);
            }
            else
            {
                float theta2 = asinf(sinTheta2);
                float sign = (dot < 0) ? -1.0f : 1.0f;
                currentAngle = atan2(normal.y, normal.x) + sign * theta2;
                currentMedium = n2;
            }

            rayStart = hitPoint;
            remainingLength -= closestDist + EPSILON;
            continue;
        }
    }

    origin = initialOrigin;
    angle = initialAngle;
}

void Ray::draw() const
{
    float ex = origin.x + length * cos(angle);
    float ey = origin.y + length * sin(angle);

    glColor3f(1.0f, 1.0f, 0.0f);
    glBegin(GL_LINES);
    glVertex2f(origin.x, origin.y);
    glVertex2f(ex, ey);
    glEnd();
}

// intersection between segment p1->p2 and ray origin + t*(dx,dy) with t >= 0
bool Ray::intersectSegment(const Points &p1, const Points &p2, const Points &rayOrigin, Points &hit) const
{
    float dx = cos(angle);
    float dy = sin(angle);

    float x1 = p1.x, y1 = p1.y;
    float x2 = p2.x, y2 = p2.y;
    float x3 = rayOrigin.x, y3 = rayOrigin.y;
    float x4 = rayOrigin.x + dx, y4 = rayOrigin.y + dy; // second point along the ray (unit away)

    float denom = (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4);
    if (fabs(denom) < 1e-9f)
        return false; // parallel / nearly parallel

    float t = ((x1 - x3) * (y3 - y4) - (y1 - y3) * (x3 - x4)) / denom;
    float u = -((x1 - x2) * (y1 - y3) - (y1 - y2) * (x1 - x3)) / denom;

    // t in [0,1] => intersection on segment; u >= 0 => in front of origin (ray direction)
    if (t >= 0.0f && t <= 1.0f && u >= 0.0f)
    {
        hit.x = x1 + t * (x2 - x1);
        hit.y = y1 + t * (y2 - y1);
        return true;
    }
    return false;
}
