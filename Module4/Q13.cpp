#define GL_SILENCE_DEPRECATION

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <iostream>
using namespace std;

GLfloat vertices[] = {
     0.0f,  0.0f, 0.0f,

    -0.5f,  0.0f, 0.0f,
    -0.5f, -0.2f, 0.0f,

     0.5f,  0.0f, 0.0f,
     0.5f,  0.2f, 0.0f,

     0.0f,  0.5f, 0.0f,
    -0.2f,  0.5f, 0.0f,

     0.0f, -0.5f, 0.0f,
     0.2f, -0.5f, 0.0f
};

GLfloat colors[] = {
    1.0f, 1.0f, 1.0f,

    1.0f, 0.0f, 0.0f,
    0.0f, 1.0f, 0.0f,

    0.0f, 1.0f, 0.0f,
    0.0f, 0.0f, 1.0f,

    0.0f, 0.0f, 1.0f,
    1.0f, 0.0f, 1.0f,

    1.0f, 1.0f, 0.0f,
    1.0f, 0.5f, 0.0f
};

GLubyte indices[] = {
    0, 1, 2,
    0, 3, 4,
    0, 5, 6,
    0, 7, 8
};

void drawPinwheel()
{
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);

    glVertexPointer(3, GL_FLOAT, 0, vertices);
    glColorPointer(3, GL_FLOAT, 0, colors);

    glDrawElements(
        GL_TRIANGLES,
        12,
        GL_UNSIGNED_BYTE,
        indices
    );

    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    drawPinwheel();

    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Q13 - Pinwheel via glDrawElements");

    glutDisplayFunc(display);

    glutMainLoop();
    return 0;
}
