#include <GL/glew.h>
#include <GL/glut.h>
#include <cmath>
#include <cstdlib>

GLuint vbo;
const int DASH_COUNT = 30;

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.2f, 0.9f, 1.0f);
    glLineWidth(4.0f);

    glEnableClientState(GL_VERTEX_ARRAY);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glVertexPointer(3, GL_FLOAT, 0, 0);
    glDrawArrays(GL_LINES, 0, DASH_COUNT * 2);

    glDisableClientState(GL_VERTEX_ARRAY);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glFlush();
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
    glutCreateWindow("Q17 - Procedural 30-Dash Ring in One VBO");

    if (glewInit() != GLEW_OK) return 1;

    glClearColor(0.05f, 0.05f, 0.12f, 1.0f);

    GLfloat vertices[DASH_COUNT * 2 * 3];

    for (int i = 0; i < DASH_COUNT; i++) {
        float angle = 2.0f * 3.1415926f * i / DASH_COUNT;
        float innerRadius = 0.55f;
        float outerRadius = 0.75f;

        int start = i * 6;

        vertices[start] = innerRadius * cosf(angle);
        vertices[start + 1] = innerRadius * sinf(angle);
        vertices[start + 2] = 0.0f;

        vertices[start + 3] = outerRadius * cosf(angle);
        vertices[start + 4] = outerRadius * sinf(angle);
        vertices[start + 5] = 0.0f;
    }

    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices),
        vertices, GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}