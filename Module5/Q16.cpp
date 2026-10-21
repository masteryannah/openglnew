#include <GL/glew.h>
#include <GL/glut.h>
#include <cstdlib>
#include <cmath>

GLuint sunVBO, groundVBO, groundEBO, treeVBO;

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glEnableClientState(GL_VERTEX_ARRAY);

    // Sun
    glColor3f(1.0f, 0.85f, 0.1f);
    glBindBuffer(GL_ARRAY_BUFFER, sunVBO);
    glVertexPointer(3, GL_FLOAT, 0, 0);
    glDrawArrays(GL_TRIANGLE_FAN, 0, 22);

    // Indexed ground
    glColor3f(0.2f, 0.65f, 0.25f);
    glBindBuffer(GL_ARRAY_BUFFER, groundVBO);
    glVertexPointer(3, GL_FLOAT, 0, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, groundEBO);
    glDrawElements(GL_QUADS, 4, GL_UNSIGNED_INT, 0);

    // Tree trunk and foliage are both stored in the tree VBO
    glColor3f(0.45f, 0.22f, 0.08f);
    glBindBuffer(GL_ARRAY_BUFFER, treeVBO);
    glVertexPointer(3, GL_FLOAT, 0, 0);
    glDrawArrays(GL_QUADS, 0, 4);

    glColor3f(0.05f, 0.5f, 0.15f);
    glDrawArrays(GL_TRIANGLES, 4, 3);

    glDisableClientState(GL_VERTEX_ARRAY);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    glFlush();
}

void keyboard(unsigned char key, int, int) {
    if (key == 27) {
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
        glDeleteBuffers(1, &sunVBO);
        glDeleteBuffers(1, &groundVBO);
        glDeleteBuffers(1, &groundEBO);
        glDeleteBuffers(1, &treeVBO);
        exit(0);
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Q16 - Three-Shape VBO Scene: Sun, Indexed Ground, Tree");

    if (glewInit() != GLEW_OK) return 1;

    glClearColor(0.5f, 0.8f, 1.0f, 1.0f);

    GLfloat sun[22 * 3] = {};
    sun[0] = -0.65f;
    sun[1] = 0.65f;
    sun[2] = 0.0f;

    for (int i = 0; i <= 20; i++) {
        float angle = 2.0f * 3.1415926f * i / 20.0f;
        sun[(i + 1) * 3] = -0.65f + 0.15f * cosf(angle);
        sun[(i + 1) * 3 + 1] = 0.65f + 0.15f * sinf(angle);
        sun[(i + 1) * 3 + 2] = 0.0f;
    }

    GLfloat ground[] = {
        -1.0f, -1.0f, 0.0f,
         1.0f, -1.0f, 0.0f,
         1.0f, -0.55f, 0.0f,
        -1.0f, -0.55f, 0.0f
    };

    GLuint groundIndices[] = { 0, 1, 2, 3 };

    GLfloat tree[] = {
        -0.12f, -0.55f, 0.0f,
         0.12f, -0.55f, 0.0f,
         0.12f,  0.05f, 0.0f,
        -0.12f,  0.05f, 0.0f,

        -0.35f, 0.0f, 0.0f,
         0.35f, 0.0f, 0.0f,
         0.0f,   0.65f, 0.0f
    };

    glGenBuffers(1, &sunVBO);
    glBindBuffer(GL_ARRAY_BUFFER, sunVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(sun), sun, GL_STATIC_DRAW);

    glGenBuffers(1, &groundVBO);
    glBindBuffer(GL_ARRAY_BUFFER, groundVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(ground), ground, GL_STATIC_DRAW);

    glGenBuffers(1, &groundEBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, groundEBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(groundIndices),
        groundIndices, GL_STATIC_DRAW);

    glGenBuffers(1, &treeVBO);
    glBindBuffer(GL_ARRAY_BUFFER, treeVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(tree), tree, GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}