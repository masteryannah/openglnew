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
const int SEGMENT_COUNT = 20;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_TRIANGLE_FAN);

    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(0.0f, 0.0f);

    for (int i = 0; i <= SEGMENT_COUNT; i++)
    {
        float angle = 2.0f * PI * i / SEGMENT_COUNT;

        float x = 0.75f * cos(angle);
        float y = 0.75f * sin(angle);

        if (i % 2 == 0)
        {
            glColor3f(1.0f, 0.0f, 1.0f);
        }
        else
        {
            glColor3f(1.0f, 1.0f, 0.0f);
        }

        glVertex2f(x, y);
    }

    glEnd();

    glFlush();
}

void init()
{
    glClearColor(0.08f, 0.08f, 0.08f, 1.0f);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowSize(600, 600);

    glutCreateWindow("MP02 - Retro Sunburst Fan");

    init();

    glutDisplayFunc(display);

    glutMainLoop();

    return 0;
}