
#include <GL/glew.h>
#include <GL/glut.h>
#include <cstdlib>

GLuint interleavedVBO;

void init()
{
    // Each vertex contains x, y, z, r, g, b.
    GLfloat data[] = {
        -0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f,
         0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,
         0.5f,  0.5f, 0.0f, 0.0f, 0.0f, 1.0f,
        -0.5f,  0.5f, 0.0f, 1.0f, 1.0f, 0.0f
    };

    glGenBuffers(1, &interleavedVBO);
    glBindBuffer(GL_ARRAY_BUFFER, interleavedVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(data),
        data, GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glBindBuffer(GL_ARRAY_BUFFER, interleavedVBO);

    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);

    // Six floats per vertex: x, y, z, r, g, b.
    GLsizei stride = 6 * sizeof(GLfloat);

    glVertexPointer(3, GL_FLOAT, stride, (void*)0);

    // Skip the first three floats to reach the color values.
    glColorPointer(3, GL_FLOAT, stride,
        (void*)(3 * sizeof(GLfloat)));

    glDrawArrays(GL_QUADS, 0, 4);

    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glFlush();
}

void keyboard(unsigned char key, int x, int y)
{
    if (key == 27) {
        glDisableClientState(GL_VERTEX_ARRAY);
        glDisableClientState(GL_COLOR_ARRAY);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glDeleteBuffers(1, &interleavedVBO);
        exit(0);
    }
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 500);
    glutCreateWindow("Q10 - Interleaved VBO Quad");

    glewInit();
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
