#include <GL/glew.h>
#include <GL/glut.h>
#include <cmath>
#include <cstdlib>

GLuint vbo, ebo;

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);

    glBindBuffer(GL_ARRAY_BUFFER, vbo);

    GLsizei stride = 6 * sizeof(GLfloat);
    glVertexPointer(3, GL_FLOAT, stride, (void*)0);
    glColorPointer(3, GL_FLOAT, stride,
        (void*)(3 * sizeof(GLfloat)));

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    glDrawElements(GL_TRIANGLE_FAN, 6, GL_UNSIGNED_INT, 0);

    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    glFlush();
}

void keyboard(unsigned char key, int, int) {
    if (key == 27) {
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
        glDeleteBuffers(1, &vbo);
        glDeleteBuffers(1, &ebo);
        exit(0);
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Q18 - Interleaved + Indexed Hexagon");

    if (glewInit() != GLEW_OK) return 1;

    glClearColor(0.08f, 0.08f, 0.12f, 1.0f);

    GLfloat data[] = {
        // x, y, z,       r, g, b
         0.0f,  0.75f, 0.0f, 1.0f, 0.2f, 0.2f,
         0.65f, 0.375f, 0.0f, 1.0f, 0.8f, 0.1f,
         0.65f,-0.375f, 0.0f, 0.2f, 1.0f, 0.3f,
         0.0f, -0.75f, 0.0f, 0.1f, 0.8f, 1.0f,
        -0.65f,-0.375f, 0.0f, 0.4f, 0.3f, 1.0f,
        -0.65f, 0.375f, 0.0f, 1.0f, 0.2f, 0.8f
    };

    GLuint indices[] = { 0, 1, 2, 3, 4, 5 };

    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(data),
        data, GL_STATIC_DRAW);

    glGenBuffers(1, &ebo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices),
        indices, GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}