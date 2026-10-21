#define GL_SILENCE_DEPRECATION

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glew.h>
#include <GL/glut.h>
#endif

GLuint leftVBO;
GLuint rightVBO;

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    GLfloat leftTriangle[] = {
        -0.65f,  0.5f, 0.0f,
        -0.9f,  -0.4f, 0.0f,
        -0.4f,  -0.4f, 0.0f
    };

    GLfloat rightTriangle[] = {
         0.65f,  0.5f, 0.0f,
         0.4f,  -0.4f, 0.0f,
         0.9f,  -0.4f, 0.0f
    };

    // Create and upload the left triangle's VBO.
    glGenBuffers(1, &leftVBO);
    glBindBuffer(GL_ARRAY_BUFFER, leftVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(leftTriangle),
        leftTriangle, GL_STATIC_DRAW);

    glColor3f(1.0f, 0.0f, 0.0f);

    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, (void*)0);
    glDrawArrays(GL_TRIANGLES, 0, 3);

    // Create and upload the right triangle's VBO.
    glGenBuffers(1, &rightVBO);
    glBindBuffer(GL_ARRAY_BUFFER, rightVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(rightTriangle),
        rightTriangle, GL_STATIC_DRAW);

    glColor3f(0.0f, 0.0f, 1.0f);

    // Bind the right VBO before specifying its vertex pointer.
    glVertexPointer(3, GL_FLOAT, 0, (void*)0);
    glDrawArrays(GL_TRIANGLES, 0, 3);

    glDisableClientState(GL_VERTEX_ARRAY);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glDeleteBuffers(1, &leftVBO);
    glDeleteBuffers(1, &rightVBO);

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Q05 - Two Separate VBOs Side by Side");

#ifndef __APPLE__
    if (glewInit() != GLEW_OK)
        return 1;
#endif

    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}