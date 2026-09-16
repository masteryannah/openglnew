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

    glColor3f(0.8f, 0.2f, 0.5f);

    glBegin(GL_QUAD_STRIP);

    // First pair
    glVertex2f(-0.8f, -0.7f);
    glVertex2f(-0.8f, -0.3f);

    // Second pair
    glVertex2f(-0.3f, -0.7f);
    glVertex2f(-0.3f, 0.0f);

    // Third pair
    glVertex2f(0.2f, -0.7f);
    glVertex2f(0.2f, 0.3f);

    // Fourth pair
    glVertex2f(0.7f, -0.7f);
    glVertex2f(0.7f, 0.6f);

    glEnd();

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
    glutCreateWindow("Q12 - Staircase Ribbon");

    init();

    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}