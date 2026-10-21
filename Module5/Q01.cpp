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

    GLfloat points[] = {
        -0.6f,  0.6f, 0.0f,
         0.6f, -0.6f, 0.0f,
        -0.6f, -0.6f, 0.0f,
         0.6f,  0.6f, 0.0f,
         0.0f,  0.0f, 0.0f
    };

    // 1. Generate a VBO
    glGenBuffers(1, &VBOid);

    // 2. Bind the VBO
    glBindBuffer(GL_ARRAY_BUFFER, VBOid);

    // 3. Upload the vertex data
    glBufferData(GL_ARRAY_BUFFER, sizeof(points),
        points, GL_STATIC_DRAW);

    glColor3f(1.0f, 1.0f, 1.0f);
    glPointSize(12.0f);

    // 4. Enable, specify, and draw the vertex array
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, (void*)0);
    glDrawArrays(GL_POINTS, 0, 5);
    glDisableClientState(GL_VERTEX_ARRAY);

    // 5. Unbind and delete the VBO
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glDeleteBuffers(1, &VBOid);

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Q01 - VBO X-Pattern Points");

#ifndef __APPLE__
    if (glewInit() != GLEW_OK)
        return 1;
#endif

    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}