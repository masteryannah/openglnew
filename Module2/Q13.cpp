#define GL_SILENCE_DEPRECATION
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <iostream>
using namespace std;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glLineWidth(10.0f);

    glBegin(GL_LINES);

    // Yellow
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(-0.8f, 0.0f);

    // Purple
    glColor3f(0.5f, 0.0f, 0.5f);
    glVertex2f(0.8f, 0.0f);

    glEnd();

    glFlush();
}

void init()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Q13 - Fading Line");

    init();

    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}