#define GL_SILENCE_DEPRECATION
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <iostream>
using namespace std;

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glShadeModel(GL_SMOOTH);

    glBegin(GL_POLYGON);

    // Top - Red
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(0.0f, 0.7f);

    // Right - Green
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex2f(0.7f, 0.0f);

    // Bottom - Blue
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex2f(0.0f, -0.7f);

    // Left - Yellow
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(-0.7f, 0.0f);

    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Q08 - Smooth Shaded Diamond");
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
