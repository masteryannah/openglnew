#define GL_SILENCE_DEPRECATION
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <iostream>
#include <cmath>
using namespace std;

float ballX = 0.0f;
float ballY = 0.0f;

float speedX = 0.01f;
float speedY = 0.01f;

const float radius = 0.1f;

void drawBall() {
    const int segments = 60;
    const float PI = 3.14159265f;

    glColor3f(1.0f, 0.0f, 0.0f);

    glBegin(GL_TRIANGLE_FAN);

    // Center of the circle
    glVertex2f(ballX, ballY);

    // Points around the circle
    for (int i = 0; i <= segments; i++) {
        float angle = (float)i / segments * 2.0f * PI;

        float x = ballX + radius * cosf(angle);
        float y = ballY + radius * sinf(angle);

        glVertex2f(x, y);
    }

    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    drawBall();

    glFlush();
}

void update() {
    ballX += speedX;
    ballY += speedY;

    // Bounce from left and right edges
    if (ballX + radius >= 1.0f ||
        ballX - radius <= -1.0f) {
        speedX = -speedX;
    }

    // Bounce from top and bottom edges
    if (ballY + radius >= 1.0f ||
        ballY - radius <= -1.0f) {
        speedY = -speedY;
    }

    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);

    glutInitWindowSize(600, 600);
    glutCreateWindow("Q16 - Bouncing Ball");

    glutDisplayFunc(display);
    glutIdleFunc(update);

    glutMainLoop();

    return 0;
}
