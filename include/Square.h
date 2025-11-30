#ifndef SQUARE_H
#define SQUARE_H

#include <GL/glut.h>
#include "Points.h"

class Square {
public:
    Points pts[4];

    Square();
    void draw(Square* sqr);
    Points mouse(int x, int y);
    Square* drag(Square* sqr, Points* mouse);
};

#endif
