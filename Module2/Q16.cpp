#define GL_SILENCE_DEPRECATION
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <iostream>
#include <cmath>
using namespace std;

const float PI = 3.14159265f;

void drawIceCream()
{
    glColor3f(1.0f, 0.4f, 0.6f);

    glBegin(GL_TRIANGLE_FAN);

    glVertex2f(0.0f, 0.55f);

    for (int i = 0; i <= 30; i++)
    {
        float angle = 2.0f * PI * i / 30.0f;

        float x = 0.4f * cos(angle);
        float y = 0.4f * sin(angle) + 0.55f;

        glVertex2f(x, y);
    }

    glEnd();
}

void drawCone()
{
    glColor3f(0.9f, 0.6f, 0.2f);

    glBegin(GL_QUADS);

    glVertex2f(-0.4f, 0.55f);
    glVertex2f(0.4f, 0.55f);
    glVertex2f(0.2f, -0.6f);
    glVertex2f(-0.2f, -0.6f);

    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    drawIceCream();
    drawCone();

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
    glutCreateWindow("Q16 - Ice Cream Cone");

    init();

    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}