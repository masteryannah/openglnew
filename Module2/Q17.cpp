#define GL_SILENCE_DEPRECATION
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <iostream>
using namespace std;

bool stippleOn = false;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glLineWidth(5.0f);

    if (stippleOn)
    {
        glEnable(GL_LINE_STIPPLE);
        glLineStipple(1, 0x00FF);
    }

    glColor3f(0.0f, 0.0f, 1.0f);

    glBegin(GL_LINE_LOOP);

    glVertex2f(-0.5f, -0.5f);
    glVertex2f(0.5f, -0.5f);
    glVertex2f(0.5f, 0.5f);
    glVertex2f(-0.5f, 0.5f);

    glEnd();

    if (stippleOn)
    {
        glDisable(GL_LINE_STIPPLE);
    }

    glFlush();
}

void keyboard(unsigned char key, int x, int y)
{
    if (key == 's' || key == 'S')
    {
        stippleOn = !stippleOn;

        glutPostRedisplay();
    }
}

void init()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Q17 - Stipple Toggle");

    init();

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);

    glutMainLoop();

    return 0;
}