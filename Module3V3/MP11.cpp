#define GL_SILENCE_DEPRECATION

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#include <GL/freeglut_ext.h>
#endif

#include <iostream>
using namespace std;

float bgR = 0.2f;
float bgG = 0.2f;
float bgB = 0.2f;

void display()
{
    glClearColor(bgR, bgG, bgB, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glutSwapBuffers();
}
void mouseEntry(int state)
{
    if (state == GLUT_ENTERED)
    {
        // Light gray
        bgR = 0.8f;
        bgG = 0.8f;
        bgB = 0.8f;
    }
    else if (state == GLUT_LEFT)
    {
        // Dark gray
        bgR = 0.15f;
        bgG = 0.15f;
        bgB = 0.15f;
    }

    glutPostRedisplay();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(600, 400);
    glutCreateWindow("Q11 - Entry Driven Background");

    glutDisplayFunc(display);
    glutEntryFunc(mouseEntry);

    glutMainLoop();

    return 0;
}
