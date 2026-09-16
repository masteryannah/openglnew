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

    // First quad - red
    glColor4f(1.0f, 0.0f, 0.0f, 0.5f);

    glBegin(GL_QUADS);

    glVertex2f(-0.7f, -0.5f);
    glVertex2f(0.2f, -0.5f);
    glVertex2f(0.2f, 0.5f);
    glVertex2f(-0.7f, 0.5f);

    glEnd();

    // Second quad - blue
    glColor4f(0.0f, 0.0f, 1.0f, 0.5f);

    glBegin(GL_QUADS);

    glVertex2f(-0.2f, -0.5f);
    glVertex2f(0.7f, -0.5f);
    glVertex2f(0.7f, 0.5f);
    glVertex2f(-0.2f, 0.5f);

    glEnd();

    glDisable(GL_BLEND);

    glFlush();
}

void init()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Q19 - Transparent Quads");

    init();

    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}