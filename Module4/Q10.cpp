#define GL_SILENCE_DEPRECATION

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <iostream>
using namespace std;

GLfloat vertices[] = {
    -0.8f, -0.3f, 0.0f,
    -0.4f, -0.3f, 0.0f,
     0.0f, -0.3f, 0.0f,
     0.4f, -0.3f, 0.0f,
     0.8f, -0.3f, 0.0f,

    -0.8f,  0.3f, 0.0f,
    -0.4f,  0.3f, 0.0f,
     0.0f,  0.3f, 0.0f,
     0.4f,  0.3f, 0.0f,
     0.8f,  0.3f, 0.0f
};

GLubyte quad1[] = { 0, 1, 6, 5 };
GLubyte quad2[] = { 1, 2, 7, 6 };
GLubyte quad3[] = { 2, 3, 8, 7 };
GLubyte quad4[] = { 3, 4, 9, 8 };

void drawCheckerboard()
{
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, vertices);

    glColor3f(0.0f, 0.0f, 0.0f);
    glDrawElements(GL_QUADS, 4, GL_UNSIGNED_BYTE, quad1);

    glColor3f(1.0f, 1.0f, 1.0f);
    glDrawElements(GL_QUADS, 4, GL_UNSIGNED_BYTE, quad2);

    glColor3f(0.0f, 0.0f, 0.0f);
    glDrawElements(GL_QUADS, 4, GL_UNSIGNED_BYTE, quad3);

    glColor3f(1.0f, 1.0f, 1.0f);
    glDrawElements(GL_QUADS, 4, GL_UNSIGNED_BYTE, quad4);

    glDisableClientState(GL_VERTEX_ARRAY);
}

void display()
{
    glClearColor(0.3f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    drawCheckerboard();

    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(800, 500);
    glutCreateWindow("Q10 - Checkerboard Row");

    glutDisplayFunc(display);

    glutMainLoop();
    return 0;
}