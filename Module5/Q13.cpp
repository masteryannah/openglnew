#include <GL/glew.h>
#include <GL/glut.h>
#include <cstdlib>

GLuint triangleVBO, squareVBO;

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glEnableClientState(GL_VERTEX_ARRAY);

    glColor3f(1.0f, 0.2f, 0.2f);
    glBindBuffer(GL_ARRAY_BUFFER, triangleVBO);
    glVertexPointer(3, GL_FLOAT, 0, 0);
    glDrawArrays(GL_TRIANGLES, 0, 3);

    glColor3f(0.2f, 0.7f, 1.0f);
    glBindBuffer(GL_ARRAY_BUFFER, squareVBO);
    glVertexPointer(3, GL_FLOAT, 0, 0);
    glDrawArrays(GL_QUADS, 0, 4);

    glDisableClientState(GL_VERTEX_ARRAY);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glFlush();
}

void monitorKeyboard(unsigned char key, int, int) {
    if (key == 27) {
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glDeleteBuffers(1, &triangleVBO);
        glDeleteBuffers(1, &squareVBO);
        exit(0);
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(700, 500);
    glutCreateWindow("Q13 - ESC Cleanup Releasing Two VBOs");

    if (glewInit() != GLEW_OK) return 1;

    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);

    GLfloat triangle[] = {
        -0.8f, -0.5f, 0.0f,
        -0.2f, -0.5f, 0.0f,
        -0.5f,  0.3f, 0.0f
    };

    GLfloat square[] = {
         0.2f, -0.4f, 0.0f,
         0.8f, -0.4f, 0.0f,
         0.8f,  0.3f, 0.0f,
         0.2f,  0.3f, 0.0f
    };

    glGenBuffers(1, &triangleVBO);
    glBindBuffer(GL_ARRAY_BUFFER, triangleVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(triangle),
        triangle, GL_STATIC_DRAW);

    glGenBuffers(1, &squareVBO);
    glBindBuffer(GL_ARRAY_BUFFER, squareVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(square),
        square, GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glutDisplayFunc(display);
    glutKeyboardFunc(monitorKeyboard);
    glutMainLoop();
    return 0;
}