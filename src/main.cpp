#include <GL/glut.h>
#include "Square.h"
#include "Glass.h"
#include "LightSource.h"
#include "MouseHandlers.h"

Glass *glassInstance = new Glass(0.3f, 0.3f, 0.5f, 0.5f, 1.5f);
Square *sqrInstance = new Square;
LightSource *lightInstance = new LightSource;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    lightInstance->updateRays(*sqrInstance,*glassInstance);
    lightInstance->draw();
    glassInstance->draw();
    sqrInstance->draw(sqrInstance);
    glFlush();
}

void Initialize()
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutInitWindowPosition(200, 200);
    glutCreateWindow("Light Rays & Square");

    // assign global externs for mouse handlers
    glass = glassInstance;
    sqr = sqrInstance;
    light = lightInstance;

    glutDisplayFunc(display);
    glutMouseFunc(mouseDown);
    glutMotionFunc(mouseMotion);

    Initialize();
    glutMainLoop();
    return 0;
}
