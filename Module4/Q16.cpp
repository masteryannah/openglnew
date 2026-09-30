#define GL_SILENCE_DEPRECATION

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/gl.h>
#include <GL/freeglut.h>
#endif

#include <iostream>
using namespace std;

GLfloat arraysQuad[] = {
    -0.9f, -0.5f, 0.0f,
    -0.3f, -0.5f, 0.0f,
    -0.3f,  0.5f, 0.0f,

    -0.9f, -0.5f, 0.0f,
    -0.3f,  0.5f, 0.0f,
    -0.9f,  0.5f, 0.0f
};

GLfloat elementsVertices[] = {
     0.3f, -0.5f, 0.0f,
     0.9f, -0.5f, 0.0f,
     0.9f,  0.5f, 0.0f,
     0.3f,  0.5f, 0.0f
};

GLubyte elementsIndices[] = {
    0, 1, 2,
    0, 2, 3
};

void drawArraysQuad()
{
    glColor3f(0.2f, 0.7f, 1.0f);

    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, arraysQuad);

    glDrawArrays(GL_TRIANGLES, 0, 6);

    glDisableClientState(GL_VERTEX_ARRAY);
}

void drawElementsQuad()
{
    glColor3f(1.0f, 0.5f, 0.2f);

    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, elementsVertices);

    glDrawElements(
        GL_TRIANGLES,
        6,
        GL_UNSIGNED_BYTE,
        elementsIndices
    );

    glDisableClientState(GL_VERTEX_ARRAY);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    drawArraysQuad();
    drawElementsQuad();

    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(900, 500);
    glutCreateWindow("Q16 - glDrawArrays vs glDrawElements");

    glutDisplayFunc(display);

    glutMainLoop();
    return 0;
}