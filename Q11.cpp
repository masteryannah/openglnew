#define GL_SILENCE_DEPRECATION
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <iostream>
#include <cmath>
using namespace std;

void drawCircleOutline(float radius, float r, float g, float b) {
    const int segments = 60;
    const float PI = 3.14159265f;

    glColor3f(r, g, b);

    glBegin(GL_LINE_LOOP);

    for (int i = 0; i < segments; i++) {
        float angle = (float)i / segments * 2.0f * PI;

        float x = radius * cosf(angle);
        float y = radius * sinf(angle);

        glVertex2f(x, y);
    }

    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    drawCircleOutline(0.7f, 1.0f, 0.0f, 0.0f); // red
    drawCircleOutline(0.5f, 0.0f, 1.0f, 0.0f); // green
    drawCircleOutline(0.3f, 0.0f, 0.0f, 1.0f); // blue

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Q11 - Concentric Circles");
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
