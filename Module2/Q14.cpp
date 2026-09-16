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

    glLineWidth(5.0f);

    // First pattern
    glEnable(GL_LINE_STIPPLE);
    glLineStipple(1, 0x00FF);

    glColor3f(1.0f, 0.0f, 0.0f);

    glBegin(GL_LINES);
    glVertex2f(-0.8f, 0.4f);
    glVertex2f(0.8f, 0.4f);
    glEnd();

    glDisable(GL_LINE_STIPPLE);

    // Second pattern
    glEnable(GL_LINE_STIPPLE);
    glLineStipple(2, 0xAAAA);

    glColor3f(0.0f, 0.0f, 1.0f);

    glBegin(GL_LINES);
    glVertex2f(-0.8f, -0.4f);
    glVertex2f(0.8f, -0.4f);
    glEnd();

    glDisable(GL_LINE_STIPPLE);

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
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Q14 - Stipple Patterns");

    init();

    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}