#define GL_SILENCE_DEPRECATION
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <iostream>
#include <cmath>
using namespace std;

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0f, 1.0f, 0.0f); // yellow
    glLineWidth(2.0f);

    const float PI = 3.14159265f;
    const float outerRadius = 0.7f;
    const float innerRadius = 0.3f;

    glBegin(GL_LINE_LOOP);

    for (int i = 0; i < 10; i++) {

        float angle = PI / 2.0f + i * PI / 5.0f;

        float radius;

        if (i % 2 == 0) {
            radius = outerRadius;
        } else {
            radius = innerRadius;
        }

        float x = radius * cosf(angle);
        float y = radius * sinf(angle);

        glVertex2f(x, y);
    }

    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Q10 - Five Pointed Star Outline");
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
