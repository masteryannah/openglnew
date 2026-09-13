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

    // Arrow shaft
    glColor3f(0.0f, 1.0f, 0.0f);
    glLineWidth(5.0f);

    glBegin(GL_LINES);
    glVertex2f(-0.7f, 0.0f);
    glVertex2f(0.5f, 0.0f);
    glEnd();

    // Arrowhead
    glBegin(GL_TRIANGLES);
    glVertex2f(0.8f, 0.0f);
    glVertex2f(0.4f, 0.25f);
    glVertex2f(0.4f, -0.25f);
    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Q12 - Right Pointing Arrow");
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
