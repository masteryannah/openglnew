#define GL_SILENCE_DEPRECATION

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#include <GL/freeglut_ext.h>
#endif

#include <iostream>
using namespace std;

float squareX = 0.0f;

const float halfSize = 0.15f;
const float speed = 0.05f;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.2f, 0.7f, 1.0f);

    glBegin(GL_QUADS);

    glVertex2f(squareX - halfSize, -halfSize);
    glVertex2f(squareX + halfSize, -halfSize);
    glVertex2f(squareX + halfSize, halfSize);
    glVertex2f(squareX - halfSize, halfSize);

    glEnd();

    glFlush();
}

void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'a':
    case 'A':
        squareX -= speed;
        break;

    case 'd':
    case 'D':
        squareX += speed;
        break;

    case 27:
        exit(0);
    }

    // Clamp using the square's edge
    if (squareX - halfSize < -0.9f)
        squareX = -0.9f + halfSize;

    if (squareX + halfSize > 0.9f)
        squareX = 0.9f - halfSize;

    glutPostRedisplay();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(600, 500);
    glutCreateWindow("Q08 - Clamped Keyboard Movement");

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);

    glutMainLoop();

    return 0;
}