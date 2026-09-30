#define GL_SILENCE_DEPRECATION

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <iostream>
#include <cmath>
using namespace std;

const int SEGMENTS = 40;
const float PI = 3.14159265359f;

GLfloat vertices[(SEGMENTS + 2) * 3];
GLfloat colors[(SEGMENTS + 2) * 3];

void generateCircle()
{
    // Center vertex
    vertices[0] = 0.0f;
    vertices[1] = 0.0f;
    vertices[2] = 0.0f;

    colors[0] = 1.0f;
    colors[1] = 1.0f;
    colors[2] = 1.0f;

    for (int i = 0; i <= SEGMENTS; i++)
    {
        float angle = 2.0f * PI * i / SEGMENTS;

        float x = 0.65f * cos(angle);
        float y = 0.65f * sin(angle);

        int v = (i + 1) * 3;

        vertices[v] = x;
        vertices[v + 1] = y;
        vertices[v + 2] = 0.0f;

        float t = (float)i / SEGMENTS;

        colors[v] = 1.0f - t;
        colors[v + 1] = t;
        colors[v + 2] = 0.5f + 0.5f * sin(PI * t);
    }
}

void drawCircle()
{
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);

    glVertexPointer(3, GL_FLOAT, 0, vertices);
    glColorPointer(3, GL_FLOAT, 0, colors);

    glDrawArrays(GL_TRIANGLE_FAN, 0, SEGMENTS + 2);

    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    drawCircle();

    glFlush();
}

int main(int argc, char** argv)
{
    generateCircle();

    glutInit(&argc, argv);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Q11 - Procedural Shaded Circle");

    glutDisplayFunc(display);

    glutMainLoop();
    return 0;
}