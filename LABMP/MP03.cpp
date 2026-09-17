#define GL_SILENCE_DEPRECATION
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <iostream>
using namespace std;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glEnable(GL_BLEND);

    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    // red
    glColor4f(1.0f, 0.0f, 0.0f, 0.5f);

    glBegin(GL_QUADS);

    glVertex2f(-0.75f, -0.50f);
    glVertex2f(0.10f, -0.50f);
    glVertex2f(0.10f, 0.55f);
    glVertex2f(-0.75f, 0.55f);

    glEnd();

    // green
    glColor4f(0.0f, 1.0f, 0.0f, 0.5f);

    glBegin(GL_QUADS);

    glVertex2f(-0.10f, -0.70f);
    glVertex2f(0.75f, -0.70f);
    glVertex2f(0.75f, 0.35f);
    glVertex2f(-0.10f, 0.35f);

    glEnd();

    // blue
    glColor4f(0.0f, 0.0f, 1.0f, 0.5f);

    glBegin(GL_QUADS);

    glVertex2f(-0.45f, -0.20f);
    glVertex2f(0.45f, -0.20f);
    glVertex2f(0.45f, 0.75f);
    glVertex2f(-0.45f, 0.75f);

    glEnd();

    glDisable(GL_BLEND);

    glFlush();
}

void init()
{
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);

    glutInitWindowSize(600, 600);

    glutCreateWindow("MP03 - Stained Glass Panels");

    init();

    glutDisplayFunc(display);

    glutMainLoop();

    return 0;
}