#include "Square.h"

Square::Square() {
    pts[0] = Points(0.2f, 0.2f);
    pts[1] = Points(0.4f, 0.2f);
    pts[2] = Points(0.4f, 0.4f);
    pts[3] = Points(0.2f, 0.4f);
}

void Square::draw(Square* sqr) {
    glColor3f(0.2f, 0.2f, 0.2f);
    glBegin(GL_QUADS);
    for (int i = 0; i < 4; ++i)
        glVertex2f(sqr->pts[i].x, sqr->pts[i].y);
    glEnd();

    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_POINTS);
    for (int i = 0; i < 4; ++i)
        glVertex2f(sqr->pts[i].x, sqr->pts[i].y);
    glEnd();
}

Points Square::mouse(int x, int y) {
    int windowWidth = 400, windowHeight = 400;
    return Points(float(x) / windowWidth, 1.0f - float(y) / windowHeight);
}

Square* Square::drag(Square* sqr, Points* mouse) {
    sqr->pts[0].x = mouse->x - 0.1f;
    sqr->pts[0].y = mouse->y - 0.1f;
    sqr->pts[1].x = mouse->x + 0.1f;
    sqr->pts[1].y = mouse->y - 0.1f;
    sqr->pts[3].x = mouse->x - 0.1f;
    sqr->pts[3].y = mouse->y + 0.1f;
    sqr->pts[2].x = mouse->x + 0.1f;
    sqr->pts[2].y = mouse->y + 0.1f;
    return sqr;
}
