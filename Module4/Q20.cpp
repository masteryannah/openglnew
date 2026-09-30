#define GL_SILENCE_DEPRECATION

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <iostream>
#include <cmath>
using namespace std;

const int PETAL_COUNT = 12;
const int CENTER_SEGMENTS = 24;
const float PI = 3.14159265359f;

GLfloat petalVertices[PETAL_COUNT * 3 * 3];
GLfloat petalColors[PETAL_COUNT * 3 * 3];

GLfloat centerVertices[(CENTER_SEGMENTS + 2) * 3];
GLubyte centerIndices[CENTER_SEGMENTS + 2];

GLfloat groundVertices[] = {
    -1.0f, -0.8f, 0.0f,
     1.0f, -0.8f, 0.0f,
     1.0f, -1.0f, 0.0f,
    -1.0f, -1.0f, 0.0f
};

void generatePetals()
{
    float radius = 0.75f;
    float petalWidthFactor = 0.6f;

    for (int i = 0; i < PETAL_COUNT; i++)
    {
        float midAngle = 2.0f * PI * i / PETAL_COUNT;

        float angle1 = midAngle - (PI / PETAL_COUNT) * petalWidthFactor;
        float angle2 = midAngle + (PI / PETAL_COUNT) * petalWidthFactor;

        int v = i * 9;

        petalVertices[v] = 0.0f;
        petalVertices[v + 1] = 0.0f;
        petalVertices[v + 2] = 0.0f;

        petalVertices[v + 3] = radius * cos(angle1);
        petalVertices[v + 4] = radius * sin(angle1);
        petalVertices[v + 5] = 0.0f;

        petalVertices[v + 6] = radius * cos(angle2);
        petalVertices[v + 7] = radius * sin(angle2);
        petalVertices[v + 8] = 0.0f;

        float t = (float)i / PETAL_COUNT;

        petalColors[v] = 1.0f;
        petalColors[v + 1] = 0.2f + 0.6f * t;
        petalColors[v + 2] = 0.7f;

        petalColors[v + 3] = 1.0f;
        petalColors[v + 4] = 0.3f + 0.5f * t;
        petalColors[v + 5] = 0.8f;

        petalColors[v + 6] = 0.9f;
        petalColors[v + 7] = 0.2f + 0.7f * t;
        petalColors[v + 8] = 1.0f;
    }
}

void generateCenter()
{
    centerVertices[0] = 0.0f;
    centerVertices[1] = 0.0f;
    centerVertices[2] = 0.0f;
    centerIndices[0] = 0;

    for (int i = 0; i <= CENTER_SEGMENTS; i++)
    {
        float angle = 2.0f * PI * i / CENTER_SEGMENTS;
        float radius = 0.28f;

        int v = (i + 1) * 3;
        centerVertices[v] = radius * cos(angle);
        centerVertices[v + 1] = radius * sin(angle);
        centerVertices[v + 2] = 0.0f;

        centerIndices[i + 1] = i + 1;
    }
}

void drawPetals()
{
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);

    glVertexPointer(3, GL_FLOAT, 0, petalVertices);
    glColorPointer(3, GL_FLOAT, 0, petalColors);

    glDrawArrays(GL_TRIANGLES, 0, PETAL_COUNT * 3);

    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);
}

void drawCenter()
{
    glColor3f(1.0f, 0.75f, 0.0f);
    glEnableClientState(GL_VERTEX_ARRAY);

    glVertexPointer(3, GL_FLOAT, 0, centerVertices);
    glDrawElements(GL_TRIANGLE_FAN, CENTER_SEGMENTS + 2, GL_UNSIGNED_BYTE, centerIndices);

    glDisableClientState(GL_VERTEX_ARRAY);
}

void drawGround()
{
    glColor3f(0.2f, 0.7f, 0.2f);
    glEnableClientState(GL_VERTEX_ARRAY);

    glVertexPointer(3, GL_FLOAT, 0, groundVertices);
    glDrawArrays(GL_QUADS, 0, 4);

    glDisableClientState(GL_VERTEX_ARRAY);
}

void display()
{
    glClearColor(0.5f, 0.8f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    drawGround();
    drawPetals();
    drawCenter();

    glFlush();
}

int main(int argc, char** argv)
{
    generatePetals();
    generateCenter();

    glutInit(&argc, argv);
    glutInitWindowSize(800, 700);
    glutCreateWindow("Q20 - Procedural Flower Scene");

    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
