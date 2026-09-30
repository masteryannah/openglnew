#define GL_SILENCE_DEPRECATION

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <iostream>
using namespace std;

void drawHexagon()
{
    GLfloat vertices[] = {
         0.0f,  0.7f, 0.0f,
         0.6f,  0.35f, 0.0f,
         0.6f, -0.35f, 0.0f,
         0.0f, -0.7f, 0.0f,
        -0.6f, -0.35f, 0.0f,
        -0.6f,  0.35f, 0.0f
    };

    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, vertices);

    glDrawArrays(GL_POLYGON, 0, 6);

    glDisableClientState(GL_VERTEX_ARRAY);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.2f, 0.7f, 1.0f);

    drawHexagon();

    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(600, 500);
    glutCreateWindow("Q02 - Filled Hexagon via Vertex Array");

    glutDisplayFunc(display);

    glutMainLoop();
    return 0;
}