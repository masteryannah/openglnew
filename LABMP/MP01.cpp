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

    // Set line thickness
    glLineWidth(3.0f);

    // Enable stipple pattern
    glEnable(GL_LINE_STIPPLE);
    glLineStipple(2, 0x0F0F);

    // Star color
    glColor3f(1.0f, 0.85f, 0.0f);

    glBegin(GL_LINE_LOOP);

    // Generate the 5-pointed star
    for (int i = 0; i < 10; i++)
    {
        float angle = PI / 2.0f + i * 2.0f * PI / 10.0f;

        float radius;

        // Alternate between outer and inner points
        if (i % 2 == 0)
        {
            radius = 0.8f;
        }
        else
        {
            radius = 0.35f;
        }

        float x = radius * cos(angle);
        float y = radius * sin(angle);

        glVertex2f(x, y);
    }

    glEnd();

    // Disable stipple after drawing
    glDisable(GL_LINE_STIPPLE);

    glFlush();
}

void init()
{
    glClearColor(0.05f, 0.05f, 0.05f, 1.0f);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowSize(600, 600);

    glutCreateWindow("MP01 - Stippled Star Frame");

    init();

    glutDisplayFunc(display);

    glutMainLoop();

    return 0;
}