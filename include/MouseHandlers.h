#ifndef MOUSE_HANDLERS_H
#define MOUSE_HANDLERS_H

#include <GL/glut.h>
#include "Square.h"
#include "LightSource.h"
#include "Glass.h"

// Shared state
extern Square *sqr;
extern Glass *glass;
extern LightSource *light;

enum DragMode
{
    NONE,
    DRAG_SQUARE,
    DRAG_GLASS,
    DRAG_LIGHT,
};
extern DragMode dragMode;

// Mouse callbacks
void mouseDown(int button, int state, int x, int y);
void mouseMotion(int x, int y);

#endif
