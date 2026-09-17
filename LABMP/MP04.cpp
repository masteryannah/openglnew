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

    glBegin(GL_QUAD_STRIP);

    // Pair 1
    glColor3f(0.75f, 0.75f, 0.75f);
    glVertex2f(-0.80f, -0.55f);
    glVertex2f(-0.80f, 0.05f);

    // Pair 2
    glColor3f(0.65f, 0.65f, 0.65f);
    glVertex2f(-0.40f, -0.75f);
    glVertex2f(-0.40f, -0.20f);

    // Pair 3
    glColor3f(0.80f, 0.80f, 0.80f);
    glVertex2f(0.00f, -0.40f);
    glVertex2f(0.00f, 0.35f);

    // Pair 4
    glColor3f(0.65f, 0.65f, 0.65f);
    glVertex2f(0.40f, -0.65f);
    glVertex2f(0.40f, -0.10f);

    // Pair 5
    glColor3f(0.80f, 0.80f, 0.80f);
    glVertex2f(0.80f, -0.30f);
    glVertex2f(0.80f, 0.55f);

    glEnd();

    glFlush();
}

void init()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowSize(700, 600);

    glutCreateWindow("MP04 - Winding Terrain Ribbon");

    init();

    glutDisplayFunc(display);

    glutMainLoop();

    return 0;
}