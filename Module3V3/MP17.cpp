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

int elapsedSeconds = 0;

bool running = false;

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

    char buffer[64];

    snprintf(
        buffer,
        sizeof(buffer),
        "Stopwatch: %d seconds",
        elapsedSeconds
    );

    glColor3f(1.0f, 1.0f, 1.0f);

    glRasterPos2f(-0.45f, 0.0f);

    drawBitmapString(
        GLUT_BITMAP_HELVETICA_18,
        buffer
    );

    // Status
    glRasterPos2f(-0.25f, -0.25f);

    if (running)
    {
        drawBitmapString(
            GLUT_BITMAP_HELVETICA_18,
            "RUNNING"
        );
    }
    else
    {
        drawBitmapString(
            GLUT_BITMAP_HELVETICA_18,
            "PAUSED"
        );
    }

    glFlush();
}

void timer(int value)
{
    if (running)
    {
        elapsedSeconds++;
        glutPostRedisplay();
    }

    // Always reschedule
    glutTimerFunc(1000, timer, 0);
}

void mouse(int button, int state, int x, int y)
{
    if (state == GLUT_DOWN)
    {
        if (button == GLUT_LEFT_BUTTON)
        {
            running = true;
        }
        else if (button == GLUT_RIGHT_BUTTON)
        {
            running = false;
        }

        glutPostRedisplay();
    }
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(600, 400);
    glutCreateWindow("Q17 - Mouse Controlled Stopwatch");

    glutDisplayFunc(display);
    glutMouseFunc(mouse);

    glutTimerFunc(1000, timer, 0);

    glutMainLoop();

    return 0;
}