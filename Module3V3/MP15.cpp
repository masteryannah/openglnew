#define GL_SILENCE_DEPRECATION

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#include <GL/freeglut_ext.h>
#endif

#include <cstdio>
#include <iostream>
using namespace std;

int secondsLeft = 30;
bool timeUp = false;

void drawBitmapString(void* font, const char* str)
{
    for (const char* c = str; *c != '\0'; c++)
    {
        glutBitmapCharacter(font, *c);
    }
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0f, 1.0f, 1.0f);

    if (timeUp)
    {
        glRasterPos2f(-0.3f, 0.0f);

        drawBitmapString(
            GLUT_BITMAP_HELVETICA_18,
            "Time's up!"
        );
    }
    else
    {
        char buffer[64];

        snprintf(
            buffer,
            sizeof(buffer),
            "Time left: %d",
            secondsLeft
        );

        glRasterPos2f(-0.3f, 0.0f);

        drawBitmapString(
            GLUT_BITMAP_HELVETICA_18,
            buffer
        );
    }

    glFlush();
}

void timer(int value)
{
    if (secondsLeft > 0)
    {
        secondsLeft--;

        if (secondsLeft == 0)
        {
            timeUp = true;
        }

        glutPostRedisplay();

        if (secondsLeft > 0)
        {
            glutTimerFunc(1000, timer, 0);
        }
    }
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(600, 300);
    glutCreateWindow("Q15 - 30 Second Countdown");

    glutDisplayFunc(display);

    glutTimerFunc(1000, timer, 0);

    glutMainLoop();

    return 0;
}