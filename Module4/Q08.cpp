#define GL_SILENCE_DEPRECATION

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <iostream>
using namespace std;

void drawTriangles()
{
    GLfloat vertices[] = {
        -0.9f, -0.5f, 0.0f,
        -0.7f,  0.2f, 0.0f,
        -0.5f, -0.5f, 0.0f,

        -0.2f, -0.5f, 0.0f,
         0.0f,  0.2f, 0.0f,
         0.2f, -0.5f, 0.0f,

          0.5f, -0.5f, 0.0f,
          0.7f,  0.2f, 0.0f,
          0.9f, -0.5f, 0.0f
    };

    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, vertices);

    glColor3f(0.2f, 0.8f, 1.0f);

    glDrawArrays(GL_TRIANGLES, 0, 9);

    glDisableClientState(GL_VERTEX_ARRAY);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    drawTriangles();

    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(800, 500);
    glutCreateWindow("Q08 - Three Triangles One Array");

    glutDisplayFunc(display);

    glutMainLoop();
    return 0;
}