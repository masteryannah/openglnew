#define GL_SILENCE_DEPRECATION

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glew.h>
#include <GL/glut.h>
#endif

#include <cstdlib>

GLuint VBOid;

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    GLfloat vertices[] = {
         0.0f,  0.6f, 0.0f,
        -0.5f, -0.4f, 0.0f,
         0.5f, -0.4f, 0.0f
    };

    glGenBuffers(1, &VBOid);
    glBindBuffer(GL_ARRAY_BUFFER, VBOid);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices),
        vertices, GL_STATIC_DRAW);

    glColor3f(0.0f, 1.0f, 0.0f);

    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, (void*)0);
    glDrawArrays(GL_TRIANGLES, 0, 3);

    glDisableClientState(GL_VERTEX_ARRAY);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glDeleteBuffers(1, &VBOid);

    glFlush();
}

void monitorKeyboard(unsigned char key, int x, int y) {
    if (key == 27) {
        // Disable the vertex array before ending the program.
        glDisableClientState(GL_VERTEX_ARRAY);

        // Unbind the array buffer.
        glBindBuffer(GL_ARRAY_BUFFER, 0);

        // Delete the VBO to release its GPU memory.
        glDeleteBuffers(1, &VBOid);

        exit(0);
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Q04 - Full Cleanup Checklist");

#ifndef __APPLE__
    if (glewInit() != GLEW_OK)
        return 1;
#endif

    glutDisplayFunc(display);
    glutKeyboardFunc(monitorKeyboard);
    glutMainLoop();

    return 0;
}