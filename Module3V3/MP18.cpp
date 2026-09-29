#define GL_SILENCE_DEPRECATION

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#include <GL/freeglut_ext.h>
#endif

#include <iostream>
#include <cmath>
using namespace std;

float angle = 0.0f;

bool inside = false;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    float x = 0.5f * cos(angle);
    float y = 0.5f * sin(angle);

    glColor3f(1.0f, 0.5f, 0.2f);

    glBegin(GL_QUADS);

    glVertex2f(x - 0.1f, y - 0.1f);
    glVertex2f(x + 0.1f, y - 0.1f);
    glVertex2f(x + 0.1f, y + 0.1f);
    glVertex2f(x - 0.1f, y + 0.1f);

    glEnd();

    glFlush();
}

void entry(int state)
{
    if (state == GLUT_ENTERED)
    {
        inside = true;
    }
    else if (state == GLUT_LEFT)
    {
        inside = false;
    }
}

void animate()
{
    if (inside)
    {
        angle += 0.01f;

        if (angle > 6.28318f)
        {
            angle -= 6.28318f;
        }

        glutPostRedisplay();
    }
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(600, 500);
    glutCreateWindow("Q18 - Entry and Idle Freeze");

    glutDisplayFunc(display);
    glutEntryFunc(entry);
    glutIdleFunc(animate);

    glutMainLoop();

    return 0;
}