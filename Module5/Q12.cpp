#include <GL/glew.h>
#include <GL/glut.h>
#include <cstdlib>

GLuint vbo;

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(12.0f);
    glColor3f(1.0f, 0.8f, 0.1f);

    glEnableClientState(GL_VERTEX_ARRAY);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glVertexPointer(3, GL_FLOAT, 0, 0);
    glDrawArrays(GL_POINTS, 0, 1);

    glDisableClientState(GL_VERTEX_ARRAY);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glFlush();
}

void movePoint(int) {
    glBindBuffer(GL_ARRAY_BUFFER, vbo);

    GLfloat* mapped = (GLfloat*)glMapBuffer(
        GL_ARRAY_BUFFER, GL_READ_WRITE);

    if (mapped != nullptr) {
        mapped[0] += 0.1f;
        if (mapped[0] > 0.9f)
            mapped[0] = -0.9f;

        glUnmapBuffer(GL_ARRAY_BUFFER);
    }

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glutPostRedisplay();
    glutTimerFunc(1000, movePoint, 0);
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
    glutCreateWindow("Q12 - Timer + glMapBuffer Moving Point");

    if (glewInit() != GLEW_OK) return 1;

    glClearColor(0.05f, 0.05f, 0.12f, 1.0f);

    GLfloat point[] = { -0.8f, 0.0f, 0.0f };

    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(point),
        point, GL_DYNAMIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutTimerFunc(1000, movePoint, 0);
    glutMainLoop();
    return 0;
}