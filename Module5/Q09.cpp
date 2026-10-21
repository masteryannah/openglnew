
#include <GL/glew.h>
#include <GL/glut.h>
#include <cstdlib>

GLuint positionVBO, colorVBO;

void init()
{
    GLfloat vertices[] = {
         0.0f,  0.7f, 0.0f,
        -0.6f, -0.5f, 0.0f,
         0.6f, -0.5f, 0.0f
    };

    GLfloat colors[] = {
        1.0f, 0.0f, 0.0f,  // Red
        0.0f, 1.0f, 0.0f,  // Green
        0.0f, 0.0f, 1.0f   // Blue
    };

    glGenBuffers(1, &positionVBO);
    glBindBuffer(GL_ARRAY_BUFFER, positionVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices),
        vertices, GL_STATIC_DRAW);

    glGenBuffers(1, &colorVBO);
    glBindBuffer(GL_ARRAY_BUFFER, colorVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(colors),
        colors, GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);

    glBindBuffer(GL_ARRAY_BUFFER, positionVBO);
    glVertexPointer(3, GL_FLOAT, 0, (void*)0);

    glBindBuffer(GL_ARRAY_BUFFER, colorVBO);
    glColorPointer(3, GL_FLOAT, 0, (void*)0);

    glDrawArrays(GL_TRIANGLES, 0, 3);

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
        glDeleteBuffers(1, &positionVBO);
        glDeleteBuffers(1, &colorVBO);
        exit(0);
    }
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 500);
    glutCreateWindow("Q09 - Two-VBO Colored Triangle");

    glewInit();
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
