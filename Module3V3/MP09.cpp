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

float mouseGLX = 0.0f;
float mouseGLY = 0.0f;

bool hasPosition = false;

void drawBitmapString(void* font, const char* str)
{
    for (const char* c = str; *c != '\0'; c++)
    {
        glutBitmapCharacter(font, *c);
    }
}

void toOpenGLCoords(int x, int y, float& outX, float& outY)
{
    int width = glutGet(GLUT_WINDOW_WIDTH);
    int height = glutGet(GLUT_WINDOW_HEIGHT);

    outX = (2.0f * x / width) - 1.0f;
    outY = 1.0f - (2.0f * y / height);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    if (hasPosition)
    {
        char buffer[64];

        snprintf(
            buffer,
            sizeof(buffer),
            "OpenGL: (%.2f, %.2f)",
            mouseGLX,
            mouseGLY
        );

        glColor3f(1.0f, 1.0f, 1.0f);

        glRasterPos2f(-0.4f, 0.0f);

        drawBitmapString(
            GLUT_BITMAP_HELVETICA_18,
            buffer
        );
    }

    glFlush();
}

void detectMotion(int x, int y)
{
    toOpenGLCoords(x, y, mouseGLX, mouseGLY);

    hasPosition = true;

    glutPostRedisplay();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(600, 500);
    glutCreateWindow("Q09 - Active Motion Coordinates");

    glutDisplayFunc(display);
    glutMotionFunc(detectMotion);

    glutMainLoop();

    return 0;
}