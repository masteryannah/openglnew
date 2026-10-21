#include <GL/glew.h>
#include <GL/glut.h>
#include <cstdlib>

GLuint zigzagVBO;

void init()
{
    GLfloat vertices[] = {
        -0.8f, -0.4f, 0.0f,
        -0.4f,  0.4f, 0.0f,
         0.0f, -0.4f, 0.0f,
         0.4f,  0.4f, 0.0f,
         0.8f, -0.4f, 0.0f
    };

    glGenBuffers(1, &zigzagVBO);
    glBindBuffer(GL_ARRAY_BUFFER, zigzagVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices),
        vertices, GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f, 1.0f, 0.0f);
    glLineWidth(4.0f);

    glBindBuffer(GL_ARRAY_BUFFER, zigzagVBO);
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, (void*)0);
    glDrawArrays(GL_LINE_STRIP, 0, 5);

    glDisableClientState(GL_VERTEX_ARRAY);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glFlush();
}

void keyboard(unsigned char key, int x, int y)
{
    if (key == 27) {
        glDisableClientState(GL_VERTEX_ARRAY);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glDeleteBuffers(1, &zigzagVBO);
        exit(0);
    }
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(700, 500);
    glutCreateWindow("Q07 - VBO Line-Strip Zigzag");

    glewInit();
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
