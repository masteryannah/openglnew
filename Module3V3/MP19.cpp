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

int score = 0;

float shapeR = 0.2f;
float shapeG = 0.7f;
float shapeB = 1.0f;

void drawBitmapString(void* font, const char* str)
{
    for (const char* c = str; *c != '\0'; c++)
    {
        glutBitmapCharacter(font, *c);
    }
}

void updateColor()
{
    int stage = (score / 5) % 4;

    switch (stage)
    {
    case 0:
        shapeR = 0.2f;
        shapeG = 0.7f;
        shapeB = 1.0f;
        break;

    case 1:
        shapeR = 0.2f;
        shapeG = 1.0f;
        shapeB = 0.3f;
        break;

    case 2:
        shapeR = 1.0f;
        shapeG = 0.5f;
        shapeB = 0.1f;
        break;

    case 3:
        shapeR = 0.8f;
        shapeG = 0.2f;
        shapeB = 1.0f;
        break;
    }
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    // Shape
    glColor3f(shapeR, shapeG, shapeB);

    glBegin(GL_QUADS);

    glVertex2f(-0.3f, -0.3f);
    glVertex2f(0.3f, -0.3f);
    glVertex2f(0.3f, 0.3f);
    glVertex2f(-0.3f, 0.3f);

    glEnd();

    // HUD
    char buffer[64];

    snprintf(
        buffer,
        sizeof(buffer),
        "Score: %d",
        score
    );

    glColor3f(1.0f, 1.0f, 1.0f);

    glRasterPos2f(-0.9f, 0.85f);

    drawBitmapString(
        GLUT_BITMAP_HELVETICA_18,
        buffer
    );

    glFlush();
}

void mouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON &&
        state == GLUT_DOWN)
    {
        score++;

        updateColor();

        glutPostRedisplay();
    }
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Q19 - HUD Score with Color Milestones");

    glutDisplayFunc(display);
    glutMouseFunc(mouse);

    glutMainLoop();

    return 0;
}