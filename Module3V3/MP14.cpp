#define GL_SILENCE_DEPRECATION

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#include <GL/freeglut_ext.h>
#endif

#include <iostream>
using namespace std;

float shapeX = 0.0f;
float shapeY = 0.0f;

const float speed = 0.05f;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.2f, 0.7f, 1.0f);

    glBegin(GL_QUADS);

    glVertex2f(shapeX - 0.15f, shapeY - 0.15f);
    glVertex2f(shapeX + 0.15f, shapeY - 0.15f);
    glVertex2f(shapeX + 0.15f, shapeY + 0.15f);
    glVertex2f(shapeX - 0.15f, shapeY + 0.15f);

    glEnd();

    glFlush();
}

void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'w':
    case 'W':
        shapeY += speed;
        break;

    case 's':
    case 'S':
        shapeY -= speed;
        break;

    case 27:
        exit(0);
    }

    glutPostRedisplay();
}

void mouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON &&
        state == GLUT_DOWN)
    {
        shapeX = 0.0f;
        shapeY = 0.0f;

        glutPostRedisplay();
    }
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(600, 500);
    glutCreateWindow("Q14 - Keyboard and Mouse Combo");

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);

    glutMainLoop();

    return 0;
}