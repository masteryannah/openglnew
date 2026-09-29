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

int counter = 0;

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
        "Counter: %d",
        counter
    );

    glColor3f(1.0f, 1.0f, 1.0f);

    glRasterPos2f(-0.3f, 0.0f);

    drawBitmapString(
        GLUT_BITMAP_HELVETICA_18,
        buffer
    );

    glFlush();
}

void timer(int value)
{
    counter++;

    glutPostRedisplay();

    glutTimerFunc(1000, timer, 0);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(600, 300);
    glutCreateWindow("Q13 - Timer Driven Counter");

    glutDisplayFunc(display);

    glutTimerFunc(1000, timer, 0);

    glutMainLoop();

    return 0;
}