#define GL_SILENCE_DEPRECATION 

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#include <GL/freeglut_ext.h>
#endif

#include <iostream>
using namespace std;

float bgR = 0.0f;
float bgG = 0.0f;
float bgB = 0.0f;

void display() {
    glClearColor(bgR, bgG, bgB, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
    case 'r':
    case 'R':
        bgR = 1.0f; bgG = 0.0f; bgB = 0.0f;
        break;
    case 'g':
    case 'G':
        bgR = 0.0f; bgG = 1.0f; bgB = 0.0f;
        break;
    case 'b':
    case 'B':
        bgR = 0.0f; bgG = 0.0f; bgB = 1.0f;
        break;
    case 27:
        exit(0);
    }
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(600, 400);
    glutCreateWindow("Q04 - Keyboard Background Color");
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
