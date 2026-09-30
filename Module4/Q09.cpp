#define GL_SILENCE_DEPRECATION

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <iostream>
using namespace std;

void drawPentagon()
{

    GLfloat vertices[] = {
         0.0f,  0.0f, 0.0f,

         0.0f,  0.7f, 0.0f,
         0.67f, 0.22f, 0.0f,
         0.41f, -0.57f, 0.0f,
        -0.41f, -0.57f, 0.0f,
        -0.67f, 0.22f, 0.0f
    };

    GLubyte indices[] = {
        0, 1, 2, 3, 4, 5, 1
    };

    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, vertices);

    glColor3f(1.0f, 0.5f, 0.1f);

    glDrawElements(
        GL_TRIANGLE_FAN,
        7,
        GL_UNSIGNED_BYTE,
        indices
    );

    glDisableClientState(GL_VERTEX_ARRAY);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    drawPentagon();

    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(600, 500);
    glutCreateWindow("Q09 - Indexed Triangle Fan Pentagon");

    glutDisplayFunc(display);

    glutMainLoop();
    return 0;
}