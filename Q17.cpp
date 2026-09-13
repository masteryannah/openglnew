#define GL_SILENCE_DEPRECATION
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <iostream>
#include <cmath>
using namespace std;

int currentLight = 0;

// 0 = Red
// 1 = Yellow
// 2 = Green

void drawCircle(float centerX, float centerY,
                float radius, float r, float g, float b) {

    const int segments = 60;
    const float PI = 3.14159265f;

    glColor3f(r, g, b);

    glBegin(GL_TRIANGLE_FAN);

    glVertex2f(centerX, centerY);

    for (int i = 0; i <= segments; i++) {
        float angle = (float)i / segments * 2.0f * PI;

        float x = centerX + radius * cosf(angle);
        float y = centerY + radius * sinf(angle);

        glVertex2f(x, y);
    }

    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Traffic light housing
    glColor3f(0.15f, 0.15f, 0.15f);

    glBegin(GL_POLYGON);
    glVertex2f(-0.35f, -0.85f);
    glVertex2f(0.35f, -0.85f);
    glVertex2f(0.35f, 0.85f);
    glVertex2f(-0.35f, 0.85f);
    glEnd();

    // Red light
    if (currentLight == 0)
        drawCircle(0.0f, 0.5f, 0.2f, 1.0f, 0.0f, 0.0f);
    else
        drawCircle(0.0f, 0.5f, 0.2f, 0.3f, 0.0f, 0.0f);

    // Yellow light
    if (currentLight == 1)
        drawCircle(0.0f, 0.0f, 0.2f, 1.0f, 1.0f, 0.0f);
    else
        drawCircle(0.0f, 0.0f, 0.2f, 0.3f, 0.3f, 0.0f);

    // Green light
    if (currentLight == 2)
        drawCircle(0.0f, -0.5f, 0.2f, 0.0f, 1.0f, 0.0f);
    else
        drawCircle(0.0f, -0.5f, 0.2f, 0.0f, 0.3f, 0.0f);

    glFlush();
}

void keyboard(unsigned char key, int x, int y) {

    if (key == 'n' || key == 'N') {
        currentLight = (currentLight + 1) % 3;

        glutPostRedisplay();
    }

    if (key == 27) {
        exit(0);
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);

    glutInitWindowSize(500, 700);
    glutCreateWindow("Q17 - Traffic Light Simulator");

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);

    glutMainLoop();

    return 0;
}
