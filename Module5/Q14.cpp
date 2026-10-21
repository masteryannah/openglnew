#include <GL/glew.h>
#include <GL/glut.h>
#include <cstdlib>

GLuint positionVBO, indexVBO;

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.2f, 0.8f, 0.5f);

    glEnableClientState(GL_VERTEX_ARRAY);
    glBindBuffer(GL_ARRAY_BUFFER, positionVBO);
    glVertexPointer(3, GL_FLOAT, 0, 0);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexVBO);
    glDrawElements(GL_TRIANGLE_FAN, 7, GL_UNSIGNED_INT, 0);

    glDisableClientState(GL_VERTEX_ARRAY);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    glFlush();
}

void keyboard(unsigned char key, int, int) {
    if (key == 27) {
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
        glDeleteBuffers(1, &positionVBO);
        glDeleteBuffers(1, &indexVBO);
        exit(0);
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Q14 - Indexed GL_TRIANGLE_FAN Pentagon");

    if (glewInit() != GLEW_OK) return 1;

    glClearColor(0.08f, 0.08f, 0.12f, 1.0f);

    // Center vertex, then five outer vertices
    GLfloat vertices[] = {
         0.0f,  0.0f, 0.0f,
         0.0f,  0.8f, 0.0f,
         0.76f, 0.25f, 0.0f,
         0.47f,-0.65f, 0.0f,
        -0.47f,-0.65f, 0.0f,
        -0.76f, 0.25f, 0.0f
    };

    GLuint indices[] = { 0, 1, 2, 3, 4, 5, 1 };

    glGenBuffers(1, &positionVBO);
    glBindBuffer(GL_ARRAY_BUFFER, positionVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices),
        vertices, GL_STATIC_DRAW);

    glGenBuffers(1, &indexVBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexVBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices),
        indices, GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}