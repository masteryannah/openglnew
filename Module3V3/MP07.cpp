#define GL_SILENCE_DEPRECATION

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#include <GL/freeglut_ext.h>
#endif

#include <iostream>
using namespace std;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.2f, 0.9f, 1.0f);

    glLineWidth(3.0f);

    glPushMatrix();

    glTranslatef(-0.5f, -0.2f, 0.0f);

    glScalef(0.003f, 0.003f, 1.0f);

    const char* text = "HI";

    for (const char* c = text; *c != '\0'; c++)
    {
        glutStrokeCharacter(GLUT_STROKE_ROMAN, *c);
    }

    glPopMatrix();

    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(600, 400);
    glutCreateWindow("Q07 - Stroke Font");

    glutDisplayFunc(display);

    glutMainLoop();

    return 0;
}