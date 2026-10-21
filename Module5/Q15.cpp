#include <GL/glew.h>
#include <GL/glut.h>
#include <cstdlib>

GLuint vbo;
float offsetY = 0.0f;
float direction = 0.02f;

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.2f, 0.7f, 1.0f);

    glEnableClientState(GL_VERTEX_ARRAY);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glVertexPointer(3, GL_FLOAT, 0, 0);
    glDrawArrays(GL_QUADS, 0, 4);

    glDisableClientState(GL_VERTEX_ARRAY);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glFlush();
}

void animate(int) {
    offsetY += direction;

    if (offsetY >= 0.5f || offsetY <= -0.5f)
        direction = -direction;

    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    GLfloat* mapped = (GLfloat*)glMapBuffer(
        GL_ARRAY_BUFFER, GL_READ_WRITE);

    if (mapped != nullptr) {
        mapped[1] = -0.3f + offsetY;
        mapped[4] = -0.3f + offsetY;
        mapped[7] = 0.3f + offsetY;
        mapped[10] = 0.3f + offsetY;
        glUnmapBuffer(GL_ARRAY_BUFFER);
    }

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glutPostRedisplay();
    glutTimerFunc(30, animate, 0);
}

void keyboard(unsigned char key, int, int) {
    if (key == 27) {
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glDeleteBuffers(1, &vbo);
        exit(0);
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Q15 - Continuous Bouncing glMapBuffer Animation");

    if (glewInit() != GLEW_OK) return 1;

    glClearColor(0.08f, 0.08f, 0.12f, 1.0f);

    GLfloat vertices[] = {
        -0.4f, -0.3f, 0.0f,
         0.4f, -0.3f, 0.0f,
         0.4f,  0.3f, 0.0f,
        -0.4f,  0.3f, 0.0f
    };

    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices),
        vertices, GL_DYNAMIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutTimerFunc(30, animate, 0);
    glutMainLoop();
    return 0;
}