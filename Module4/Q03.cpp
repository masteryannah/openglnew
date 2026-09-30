#define GL_SILENCE_DEPRECATION

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <iostream>
using namespace std;

void drawLines()
{
    GLfloat vertices[] = {
        -0.8f,  0.5f, 0.0f,
         0.8f,  0.5f, 0.0f,

        -0.8f, -0.5f, 0.0f,
         0.8f, -0.5f, 0.0f
    };

    glLineWidth(5.0f);

    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, vertices);

    glDrawArrays(GL_LINES, 0, 4);

    glDisableClientState(GL_VERTEX_ARRAY);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0f, 1.0f, 0.0f);

    drawLines();

    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(600, 500);
    glutCreateWindow("Q03 - Two Lines One Array");

    glutDisplayFunc(display);

    glutMainLoop();
    return 0;
}