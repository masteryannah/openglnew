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

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0f, 0.6f, 0.0f);

    glBegin(GL_TRIANGLE_FAN);

    // Center
    glVertex2f(0.0f, 0.0f);

    // Half-circle
    for (int i = 0; i <= 8; i++)
    {
        float angle = PI * i / 8.0f;

        float x = 0.7f * cos(angle);
        float y = 0.7f * sin(angle);

        glVertex2f(x, y);
    }

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
    glutCreateWindow("Q10 - Half Circle");

    init();

    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}