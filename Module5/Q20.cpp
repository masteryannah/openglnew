#include <GL/glew.h>
#include <GL/glut.h>
#include <cstdlib>

GLuint shipPositionVBO, shipColorVBO;
GLuint groundVBO, groundEBO;

float shipX = -0.7f;

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw indexed ground
    glColor3f(0.2f, 0.7f, 0.25f);
    glEnableClientState(GL_VERTEX_ARRAY);

    glBindBuffer(GL_ARRAY_BUFFER, groundVBO);
    glVertexPointer(3, GL_FLOAT, 0, 0);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, groundEBO);
    glDrawElements(GL_QUADS, 4, GL_UNSIGNED_INT, 0);

    // Draw ship using position and color VBOs
    glEnableClientState(GL_COLOR_ARRAY);

    glBindBuffer(GL_ARRAY_BUFFER, shipPositionVBO);
    glVertexPointer(3, GL_FLOAT, 0, 0);

    glBindBuffer(GL_ARRAY_BUFFER, shipColorVBO);
    glColorPointer(3, GL_FLOAT, 0, 0);

    glDrawArrays(GL_TRIANGLES, 0, 3);

    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    glFlush();
}

void animateShip(int) {
    shipX += 0.1f;
    if (shipX > 0.8f)
        shipX = -0.8f;

    glBindBuffer(GL_ARRAY_BUFFER, shipPositionVBO);

    GLfloat* mapped = (GLfloat*)glMapBuffer(
        GL_ARRAY_BUFFER, GL_READ_WRITE);

    if (mapped != nullptr) {
        mapped[0] = shipX - 0.15f;
        mapped[3] = shipX + 0.15f;
        mapped[6] = shipX;
        glUnmapBuffer(GL_ARRAY_BUFFER);
    }

    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glutPostRedisplay();
    glutTimerFunc(1000, animateShip, 0);
}

void keyboard(unsigned char key, int, int) {
    if (key == 27) {
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

        glDeleteBuffers(1, &shipPositionVBO);
        glDeleteBuffers(1, &shipColorVBO);
        glDeleteBuffers(1, &groundVBO);
        glDeleteBuffers(1, &groundEBO);

        exit(0);
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Q20 - Capstone: Animated Ship Over Indexed Ground");

    if (glewInit() != GLEW_OK) return 1;

    glClearColor(0.45f, 0.75f, 0.95f, 1.0f);

    GLfloat shipPositions[] = {
        shipX - 0.15f, 0.0f, 0.0f,
        shipX + 0.15f, 0.0f, 0.0f,
        shipX,         0.35f, 0.0f
    };

    GLfloat shipColors[] = {
        1.0f, 0.2f, 0.2f,
        1.0f, 0.8f, 0.1f,
        1.0f, 0.4f, 0.1f
    };

    GLfloat ground[] = {
        -1.0f, -1.0f, 0.0f,
         1.0f, -1.0f, 0.0f,
         1.0f, -0.3f, 0.0f,
        -1.0f, -0.3f, 0.0f
    };

    GLuint groundIndices[] = { 0, 1, 2, 3 };

    glGenBuffers(1, &shipPositionVBO);
    glBindBuffer(GL_ARRAY_BUFFER, shipPositionVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(shipPositions),
        shipPositions, GL_DYNAMIC_DRAW);

    glGenBuffers(1, &shipColorVBO);
    glBindBuffer(GL_ARRAY_BUFFER, shipColorVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(shipColors),
        shipColors, GL_STATIC_DRAW);

    glGenBuffers(1, &groundVBO);
    glBindBuffer(GL_ARRAY_BUFFER, groundVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(ground),
        ground, GL_STATIC_DRAW);

    glGenBuffers(1, &groundEBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, groundEBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(groundIndices),
        groundIndices, GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutTimerFunc(1000, animateShip, 0);
    glutMainLoop();
    return 0;
}