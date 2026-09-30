#define GL_SILENCE_DEPRECATION

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <iostream>
using namespace std;

void drawStaircase()
{
    GLfloat vertices[] = {
        -0.8f, -0.7f, 0.0f,
        -0.8f, -0.3f, 0.0f,

        -0.4f, -0.7f, 0.0f,
        -0.4f, -0.1f, 0.0f,

         0.0f, -0.7f, 0.0f,
         0.0f,  0.1f, 0.0f,

         0.4f, -0.7f, 0.0f,
         0.4f,  0.3f, 0.0f,

         0.8f, -0.7f, 0.0f,
         0.8f,  0.5f, 0.0f
    };

    GLfloat colors[] = {
        1.0f, 0.2f, 0.2f,
        1.0f, 0.2f, 0.2f,

        0.2f, 1.0f, 0.2f,
        0.2f, 1.0f, 0.2f,

        0.2f, 0.5f, 1.0f,
        0.2f, 0.5f, 1.0f,

        1.0f, 0.7f, 0.1f,
        1.0f, 0.7f, 0.1f,

        0.8f, 0.2f, 1.0f,
        0.8f, 0.2f, 1.0f
    };

    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);

    glVertexPointer(3, GL_FLOAT, 0, vertices);
    glColorPointer(3, GL_FLOAT, 0, colors);

    glDrawArrays(GL_QUAD_STRIP, 0, 10);

    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    drawStaircase();

    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Q14 - Colored Quad Strip Staircase");

    glutDisplayFunc(display);

    glutMainLoop();
    return 0;
}