
#include <GL/glew.h>
#include <GL/glut.h>
#include <cstdlib>

GLuint positionVBO, indexVBO;

void init()
{
    GLfloat vertices[] = {
        -0.5f, -0.5f, 0.0f,  // 0
         0.5f, -0.5f, 0.0f,  // 1
         0.5f,  0.5f, 0.0f,  // 2
        -0.5f,  0.5f, 0.0f   // 3
    };

    GLubyte indices[] = {
        0, 1, 2,
        0, 2, 3
    };

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
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.2f, 0.6f, 1.0f);

    glEnableClientState(GL_VERTEX_ARRAY);

    glBindBuffer(GL_ARRAY_BUFFER, positionVBO);
    glVertexPointer(3, GL_FLOAT, 0, (void*)0);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexVBO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_BYTE, (void*)0);

    glDisableClientState(GL_VERTEX_ARRAY);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

    glFlush();
}

void keyboard(unsigned char key, int x, int y)
{
    if (key == 27) {
        glDisableClientState(GL_VERTEX_ARRAY);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
        glDeleteBuffers(1, &positionVBO);
        glDeleteBuffers(1, &indexVBO);
        exit(0);
    }
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 500);
    glutCreateWindow("Q08 - Indexed Quad: Position VBO + Separate Index VBO");

    glewInit();
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
