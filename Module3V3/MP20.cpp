#define GL_SILENCE_DEPRECATION

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#include <GL/freeglut_ext.h>
#endif

#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

float shapeX = 0.0f;
float shapeY = 0.0f;

int mouseX = 0;
int mouseY = 0;

float pulseAngle = 0.0f;

float baseSize = 0.12f;
float amplitude = 0.03f;

void drawBitmapString(void* font, const char* str)
{
    for (const char* c = str; *c != '\0'; c++)
    {
        glutBitmapCharacter(font, *c);
    }
}

void toGL(int x, int y, float& outX, float& outY)
{
    int width = glutGet(GLUT_WINDOW_WIDTH);
    int height = glutGet(GLUT_WINDOW_HEIGHT);

    outX = (2.0f * x / width) - 1.0f;

    outY = 1.0f - (2.0f * y / height);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    float size =
        baseSize +
        amplitude * sin(pulseAngle);

    glColor3f(1.0f, 0.75f, 0.1f);

    glBegin(GL_QUADS);

    glVertex2f(shapeX - size, shapeY - size);
    glVertex2f(shapeX + size, shapeY - size);
    glVertex2f(shapeX + size, shapeY + size);
    glVertex2f(shapeX - size, shapeY + size);

    glEnd();

    glColor3f(1.0f, 1.0f, 1.0f);

    glRasterPos2f(
        shapeX - 0.12f,
        shapeY + size + 0.05f
    );

    drawBitmapString(
        GLUT_BITMAP_HELVETICA_12,
        "Marker"
    );

    char buffer[64];

    snprintf(
        buffer,
        sizeof(buffer),
        "Mouse: (%d, %d)",
        mouseX,
        mouseY
    );

    glRasterPos2f(-0.9f, -0.9f);

    drawBitmapString(
        GLUT_BITMAP_HELVETICA_12,
        buffer
    );

    glFlush();
}

void mouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON &&
        state == GLUT_DOWN)
    {
        toGL(x, y, shapeX, shapeY);

        glutPostRedisplay();
    }
}

void passiveMotion(int x, int y)
{
    mouseX = x;
    mouseY = y;

    float tempX;
    float tempY;

    toGL(x, y, tempX, tempY);

    glutPostRedisplay();
}

void animate()
{
    pulseAngle += 0.03f;

    if (pulseAngle > 6.28318f)
    {
        pulseAngle -= 6.28318f;
    }

    glutPostRedisplay();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);

    glutInitWindowSize(700, 500);

    glutCreateWindow(
        "Q20 - Interactive Text Placer"
    );

    glutDisplayFunc(display);

    glutMouseFunc(mouse);

    glutPassiveMotionFunc(passiveMotion);

    glutIdleFunc(animate);

    glutMainLoop();

    return 0;
}