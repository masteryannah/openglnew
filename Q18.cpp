#define GL_SILENCE_DEPRECATION
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <iostream>
#include <cmath>
using namespace std;

float handAngle = 0.0f;

const float PI = 3.14159265f;

void drawClockFace() {

    const int segments = 60;

    glColor3f(0.0f, 0.0f, 0.0f);
    glLineWidth(2.0f);

    // Clock circle
    glBegin(GL_LINE_LOOP);

    for (int i = 0; i < segments; i++) {
        float angle = (float)i / segments * 2.0f * PI;

        float x = 0.75f * cosf(angle);
        float y = 0.75f * sinf(angle);

        glVertex2f(x, y);
    }

    glEnd();
}

void drawTicks() {

    glColor3f(0.0f, 0.0f, 0.0f);
    glLineWidth(3.0f);

    for (int i = 0; i < 12; i++) {

        float angle = PI / 2.0f - i * (2.0f * PI / 12.0f);

        float outerRadius = 0.70f;
        float innerRadius = 0.60f;

        float x1 = outerRadius * cosf(angle);
        float y1 = outerRadius * sinf(angle);

        float x2 = innerRadius * cosf(angle);
        float y2 = innerRadius * sinf(angle);

        glBegin(GL_LINES);

        glVertex2f(x1, y1);
        glVertex2f(x2, y2);

        glEnd();
    }
}

void drawHand() {

    float x = 0.55f * cosf(handAngle);
    float y = 0.55f * sinf(handAngle);

    glColor3f(1.0f, 0.0f, 0.0f);
    glLineWidth(5.0f);

    glBegin(GL_LINES);

    glVertex2f(0.0f, 0.0f);
    glVertex2f(x, y);

    glEnd();
}

void display() {

    glClear(GL_COLOR_BUFFER_BIT);

    drawClockFace();
    drawTicks();
    drawHand();

    glFlush();
}

void update() {

    handAngle -= 0.01f;

    if (handAngle < -2.0f * PI) {
        handAngle += 2.0f * PI;
    }

    glutPostRedisplay();
}

int main(int argc, char** argv) {

    glutInit(&argc, argv);

    glutInitWindowSize(600, 600);
    glutCreateWindow("Q18 - Rotating Clock Hand");

    glutDisplayFunc(display);
    glutIdleFunc(update);

    glutMainLoop();

    return 0;
}
