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

    glColor3ub(255, 140, 0);

    glBegin(GL_TRIANGLES);

    glVertex2f(0.0f, 0.7f);
    glVertex2f(-0.7f, -0.5f);
    glVertex2f(0.7f, -0.5f);

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
    glutCreateWindow("Q06 - Orange Triangle");

    init();

    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}