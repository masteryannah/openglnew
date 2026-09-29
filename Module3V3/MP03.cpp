#define GL_SILENCE_DEPRECATION

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#include <GL/freeglut_ext.h>
#endif

#include <iostream>
using namespace std;

void drawBitmapString(void* font, const char* str)
{
    for (const char* c = str; *c != '\0'; c++)
    {
        glutBitmapCharacter(font, *c);
    }
}

void display()
{
    glClearColor(0.1f, 0.1f, 0.15f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0f, 1.0f, 1.0f);

    glRasterPos2f(-0.35f, 0.0f);
    drawBitmapString(GLUT_BITMAP_HELVETICA_18, "My Custom Window");

    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);

    glutInitWindowSize(800, 500);
    glutInitWindowPosition(150, 150);

    glutCreateWindow("Q03 - My Custom Window");

    glutDisplayFunc(display);

    glutMainLoop();

    return 0;
}