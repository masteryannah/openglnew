#define GL_SILENCE_DEPRECATION

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <iostream>
using namespace std;

void drawTriangle()
{
    GLint vertices[] = {
         0, 80, 0,
        -80, -60, 0,
         80, -60, 0
    };

    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_INT, 0, vertices);

    glDrawArrays(GL_TRIANGLES, 0, 3);

    glDisableClientState(GL_VERTEX_ARRAY);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0f, 0.4f, 0.2f);

    glPushMatrix();

    glScalef(0.01f, 0.01f, 1.0f);

    drawTriangle();

    glPopMatrix();

    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(600, 500);
    glutCreateWindow("Q05 - GLint Vertex Array");

    glutDisplayFunc(display);

    glutMainLoop();
    return 0;
}