#define GL_SILENCE_DEPRECATION

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <iostream>
using namespace std;

GLfloat sunVertices[] = {
     0.0f,  0.0f, 0.0f,
     0.0f,  0.3f, 0.0f,
     0.21f, 0.21f, 0.0f,
     0.3f,  0.0f, 0.0f,
     0.21f, -0.21f, 0.0f,
     0.0f, -0.3f, 0.0f,
    -0.21f, -0.21f, 0.0f,
    -0.3f,  0.0f, 0.0f,
    -0.21f,  0.21f, 0.0f
};

GLubyte sunIndices[] = {
    0, 1, 2,
    0, 2, 3,
    0, 3, 4,
    0, 4, 5,
    0, 5, 6,
    0, 6, 7,
    0, 7, 8,
    0, 8, 1
};

GLfloat mountainVertices[] = {
    -0.9f, -0.4f, 0.0f,
    -0.5f,  0.4f, 0.0f,
     0.0f, -0.4f, 0.0f,

     0.0f, -0.4f, 0.0f,
     0.45f,  0.5f, 0.0f,
     0.9f,  -0.4f, 0.0f
};

// ---------------- GROUND ----------------
GLfloat groundVertices[] = {
    -1.0f, -0.4f, 0.0f,
     1.0f, -0.4f, 0.0f,
     1.0f, -0.9f, 0.0f,
    -1.0f, -0.9f, 0.0f
};

void drawSun()
{
    glColor3f(1.0f, 0.8f, 0.0f);

    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, sunVertices);

    glDrawElements(
        GL_TRIANGLES,
        24,
        GL_UNSIGNED_BYTE,
        sunIndices
    );

    glDisableClientState(GL_VERTEX_ARRAY);
}

void drawMountains()
{
    glColor3f(0.3f, 0.5f, 0.3f);

    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, mountainVertices);

    glDrawArrays(GL_TRIANGLES, 0, 6);

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

    drawSun();
    drawMountains();
    drawGround();

    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Q15 - Fully Array Based Scene");

    glutDisplayFunc(display);

    glutMainLoop();
    return 0;
}