#include "MouseHandlers.h"

DragMode dragMode = NONE;
Glass *glass = nullptr;
Square *sqr = nullptr;
LightSource *light = nullptr;

// repo check
void mouseDown(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        Points mousePt = sqr->mouse(x, y);

        // Check if inside square first
        if (mousePt.x > sqr->pts[0].x && mousePt.y > sqr->pts[0].y &&
            mousePt.x < sqr->pts[2].x && mousePt.y < sqr->pts[2].y)
        {
            dragMode = DRAG_SQUARE;
        }

        else if (mousePt.x > glass->pts[0].x && mousePt.y > glass->pts[0].y &&
                 mousePt.x < glass->pts[2].x && mousePt.y < glass->pts[2].y)
        {
            dragMode = DRAG_GLASS;
        }

        // Check if close to light source
        else
        {
            float dx = mousePt.x - light->position.x;
            float dy = mousePt.y - light->position.y;
            if ((dx * dx + dy * dy) < 0.03f * 0.03f)
                dragMode = DRAG_LIGHT;
            else
                dragMode = DRAG_LIGHT; // default to light if empty space
        }
    }
    else if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
    {
        dragMode = NONE;
    }
}

void mouseMotion(int x, int y)
{
    if (dragMode == NONE)
        return;

    Points mousePt = sqr->mouse(x, y);
    if (dragMode == DRAG_SQUARE)
    {
        sqr->drag(sqr, &mousePt);
    }
    else if (dragMode == DRAG_LIGHT)
    {
        light->setPosition(mousePt.x, mousePt.y);
    }
    else if (dragMode == DRAG_GLASS)
    {
        glass->drag_glass(glass, &mousePt);
    }
    glutPostRedisplay();
}
