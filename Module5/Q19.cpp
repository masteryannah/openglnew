#include <GL/glew.h>
#include <GL/glut.h>
#include <cstdlib>

GLuint positionVBO, colorVBO;
int colorScheme = 0;

const GLfloat colors[][9] = {
    { 1,0,0, 0,1,0, 0,0,1 },
    { 1,1,0, 1,0,1, 0,1,1 },
    { 1,0.5f,0, 0.5f,0,1, 0,1,0.5f }
};

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);

    glBindBuffer(GL_ARRAY_BUFFER, positionVBO);
    glVertexPointer(3, GL_FLOAT, 0, 0);

    glBindBuffer(GL_ARRAY_BUFFER, colorVBO);
    glColorPointer(3, GL_FLOAT, 0, 0);

    glDrawArrays(GL_TRIANGLES, 0, 3);

    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glFlush();
}

void keyboard(unsigned char key, int, int) {
    if (key == 27) {
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glDeleteBuffers(1, &positionVBO);
        glDeleteBuffers(1, &colorVBO);
        exit(0);
    }

    if (key == 'c' || key == 'C') {
        colorScheme = (colorScheme + 1) % 3;

        glBindBuffer(GL_ARRAY_BUFFER, colorVBO);
        GLfloat* mapped = (GLfloat*)glMapBuffer(
            GL_ARRAY_BUFFER, GL_WRITE_ONLY);

        if (mapped != nullptr) {
            for (int i = 0; i < 9; i++)
                mapped[i] = colors[colorScheme][i];

            glUnmapBuffer(GL_ARRAY_BUFFER);
        }

        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glutPostRedisplay();
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Q19 - Keyboard-Triggered Color Change via glMapBuffer");

    if (glewInit() != GLEW_OK) return 1;

    glClearColor(0.08f, 0.08f, 0.12f, 1.0f);

    GLfloat positions[] = {
        -0.6f, -0.5f, 0.0f,
         0.6f, -0.5f, 0.0f,
         0.0f,  0.6f, 0.0f
    };

    glGenBuffers(1, &positionVBO);
    glBindBuffer(GL_ARRAY_BUFFER, positionVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(positions),
        positions, GL_STATIC_DRAW);

    glGenBuffers(1, &colorVBO);
    glBindBuffer(GL_ARRAY_BUFFER, colorVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(colors[0]),
        colors[0], GL_DYNAMIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}