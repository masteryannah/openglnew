#define GL_SILENCE_DEPRECATION

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <iostream>
using namespace std;

void drawQuad()
{

    GLfloat data[] = {
        -0.6f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f,
         0.6f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,
         0.6f,  0.5f, 0.0f, 0.0f, 0.0f, 1.0f,
        -0.6f,  0.5f, 0.0f, 1.0f, 1.0f, 0.0f
    };

    GLsizei stride = 6 * sizeof(GLfloat);

    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);

    glVertexPointer(
        3,
        GL_FLOAT,
        stride,
        data
    );

    glColorPointer(
        3,
        GL_FLOAT,
        stride,
        data + 3
    );

    glDrawArrays(GL_QUADS, 0, 4);

    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    drawQuad();

    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(600, 500);
    glutCreateWindow("Q12 - Interleaved Array Quad");

    glutDisplayFunc(display);

    glutMainLoop();
    return 0;
}