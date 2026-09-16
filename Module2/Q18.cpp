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

    glBegin(GL_QUAD_STRIP);

    // Segment 1 - Red
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(-0.9f, -0.6f);
    glVertex2f(-0.9f, 0.0f);

    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(-0.5f, -0.6f);
    glVertex2f(-0.5f, 0.0f);

    // Segment 2 - Green
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex2f(-0.1f, -0.6f);
    glVertex2f(-0.1f, 0.1f);

    // Segment 3 - Blue
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex2f(0.3f, -0.6f);
    glVertex2f(0.3f, 0.2f);

    // Segment 4 - Yellow
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(0.6f, -0.6f);
    glVertex2f(0.6f, 0.3f);

    // Segment 5 - Purple
    glColor3f(0.6f, 0.0f, 0.8f);
    glVertex2f(0.9f, -0.6f);
    glVertex2f(0.9f, 0.4f);

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
    glutCreateWindow("Q18 - Colored Quad Strip");

    init();

    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}