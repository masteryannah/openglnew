#define GL_SILENCE_DEPRECATION
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <iostream>
#include <cmath>
using namespace std;

void drawSun() {
    const int segments = 60;
    const float PI = 3.14159265f;

    glColor3f(1.0f, 0.8f, 0.0f); // yellow

    glBegin(GL_TRIANGLE_FAN);

    glVertex2f(0.6f, 0.5f);

    for (int i = 0; i <= segments; i++) {
        float angle = (float)i / segments * 2.0f * PI;

        float x = 0.6f + 0.18f * cosf(angle);
        float y = 0.5f + 0.18f * sinf(angle);

        glVertex2f(x, y);
    }

    glEnd();
}

void drawGround() {
    glColor3f(0.2f, 0.7f, 0.2f); // green

    glBegin(GL_POLYGON);
    glVertex2f(-1.0f, -1.0f);
    glVertex2f(1.0f, -1.0f);
    glVertex2f(1.0f, -0.3f);
    glVertex2f(-1.0f, -0.3f);
    glEnd();
}

void display() {
    glClearColor(0.5f, 0.8f, 1.0f, 1.0f); // light blue sky
    glClear(GL_COLOR_BUFFER_BIT);

    drawGround();
    drawSun();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);

    glutInitWindowSize(800, 400);
    glutInitWindowPosition(100, 100);

    glutCreateWindow("Q14 - Simple Landscape");
    glutDisplayFunc(display);

    glutMainLoop();

    return 0;
}
