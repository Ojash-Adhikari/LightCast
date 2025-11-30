#include "Glass.h"
#include <GL/glut.h>

Glass::Glass() : refractiveIndex(1.5f) {
    pts[0] = Points(0.3f, 0.3f);
    pts[1] = Points(0.5f, 0.3f);
    pts[2] = Points(0.5f, 0.5f);
    pts[3] = Points(0.3f, 0.5f);
}

Glass::Glass(float x0, float y0, float x1, float y1, float n)
    : refractiveIndex(n) {
    pts[0] = Points(x0, y0);
    pts[1] = Points(x1, y0);
    pts[2] = Points(x1, y1);
    pts[3] = Points(x0, y1);
}

void Glass::draw() const {
    glColor4f(0.5f, 0.8f, 1.0f, 0.3f); // semi-transparent light blue
    glBegin(GL_QUADS);
    for (int i = 0; i < 4; ++i)
        glVertex2f(pts[i].x, pts[i].y);
    glEnd();
}

bool Glass::isInside(const Points& p) const {
    // Simple AABB check (works for axis-aligned rectangle)
    float minX = pts[0].x, maxX = pts[2].x;
    float minY = pts[0].y, maxY = pts[2].y;
    return p.x >= minX && p.x <= maxX && p.y >= minY && p.y <= maxY;
}

Glass* Glass::drag_glass(Glass* glass, Points* mouse) {
    glass->pts[0].x = mouse->x - 0.1f;
    glass->pts[0].y = mouse->y - 0.1f;
    glass->pts[1].x = mouse->x + 0.1f;
    glass->pts[1].y = mouse->y - 0.1f;
    glass->pts[3].x = mouse->x - 0.1f;
    glass->pts[3].y = mouse->y + 0.1f;
    glass->pts[2].x = mouse->x + 0.1f;
    glass->pts[2].y = mouse->y + 0.1f;
    return glass;
}