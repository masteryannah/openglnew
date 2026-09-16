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
const int SEGMENT_COUNT = 60;

void getRainbowColor(float t, float& r, float& g, float& b)
{
    r = 0.5f + 0.5f * sin(2.0f * PI * t);
    g = 0.5f + 0.5f * sin(2.0f * PI * t + 2.0f * PI / 3.0f);
    b = 0.5f + 0.5f * sin(2.0f * PI * t + 4.0f * PI / 3.0f);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_TRIANGLE_FAN);

    // Center
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.0f, 0.0f);

    for (int i = 0; i <= SEGMENT_COUNT; i++)
    {
        float t = (float)i / SEGMENT_COUNT;
        float angle = 2.0f * PI * t;

        float r, g, b;
        getRainbowColor(t, r, g, b);

        glColor3f(r, g, b);

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

    glShadeModel(GL_SMOOTH);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Q20 - Rainbow Circle");

    init();

    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}