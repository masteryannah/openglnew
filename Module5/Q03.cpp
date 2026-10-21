#define GL_SILENCE_DEPRECATION

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glew.h>
#include <GL/glut.h>
#endif

GLuint VBOid;

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    GLfloat vertices[] = {
         0.0f,  0.6f, 0.0f,
         0.52f, 0.3f, 0.0f,
         0.52f, -0.3f, 0.0f,
         0.0f, -0.6f, 0.0f,
        -0.52f, -0.3f, 0.0f,
        -0.52f,  0.3f, 0.0f
    };

    glGenBuffers(1, &VBOid);
    glBindBuffer(GL_ARRAY_BUFFER, VBOid);

    // GL_STATIC_DRAW is suitable because the data is uploaded
    // once and used for drawing without being modified.
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices),
        vertices, GL_STATIC_DRAW);

    glColor3f(0.0f, 0.6f, 1.0f);

    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, (void*)0);
    glDrawArrays(GL_POLYGON, 0, 6);
    glDisableClientState(GL_VERTEX_ARRAY);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glDeleteBuffers(1, &VBOid);

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Q03 - Static Hexagon With the Correct Usage Hint");

#ifndef __APPLE__
    if (glewInit() != GLEW_OK)
        return 1;
#endif

    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}