#define GL_SILENCE_DEPRECATION
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <iostream>
using namespace std;

void drawGround()
{
    glColor3f(0.0f, 0.55f, 0.15f);

    glBegin(GL_POLYGON);

    glVertex2f(-1.0f, -1.0f);
    glVertex2f(1.0f, -1.0f);
    glVertex2f(1.0f, -0.40f);
    glVertex2f(-1.0f, -0.40f);

    glEnd();
}

void drawWalls()
{
    glColor3f(0.80f, 0.68f, 0.50f);

    glBegin(GL_QUADS);

    glVertex2f(-0.40f, -0.40f);
    glVertex2f(0.40f, -0.40f);
    glVertex2f(0.40f, 0.40f);
    glVertex2f(-0.40f, 0.40f);

    glEnd();
}

void drawRoof()
{
    glColor3f(0.80f, 0.05f, 0.10f);

    glBegin(GL_TRIANGLES);

    glVertex2f(-0.50f, 0.40f);
    glVertex2f(0.50f, 0.40f);
    glVertex2f(0.00f, 0.85f);

    glEnd();
}

void drawDoor()
{
    glColor3f(0.35f, 0.16f, 0.05f);

    glBegin(GL_QUADS);

    glVertex2f(-0.12f, -0.40f);
    glVertex2f(0.12f, -0.40f);
    glVertex2f(0.12f, 0.15f);
    glVertex2f(-0.12f, 0.15f);

    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    // Sky
    glColor3f(0.35f, 0.70f, 0.90f);

    glBegin(GL_QUADS);

    glVertex2f(-1.0f, -0.40f);
    glVertex2f(1.0f, -0.40f);
    glVertex2f(1.0f, 1.0f);
    glVertex2f(-1.0f, 1.0f);

    glEnd();

    // Ground
    drawGround();

    // House walls
    drawWalls();

    // Roof
    drawRoof();

    // Door
    drawDoor();

    glFlush();
}

void init()
{
    glClearColor(0.35f, 0.70f, 0.90f, 1.0f);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowSize(700, 600);

    glutCreateWindow("MP05 - Architectural House Scene");

    init();

    glutDisplayFunc(display);

    glutMainLoop();

    return 0;
}