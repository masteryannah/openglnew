#define GL_SILENCE_DEPRECATION

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <iostream>
#include <cmath>
using namespace std;

const int TEETH = 12;
const float PI = 3.14159265359f;

GLfloat vertices[TEETH * 2 * 3];

GLubyte evenIndices[TEETH * 3];
GLubyte oddIndices[TEETH * 3];

void generateGear()
{

    for (int i = 0; i < TEETH * 2; i++)
    {
        float angle = 2.0f * PI * i / (TEETH * 2);

        float radius;

        if (i % 2 == 0)
            radius = 0.75f;
        else
            radius = 0.50f;

        vertices[i * 3] = radius * cos(angle);
        vertices[i * 3 + 1] = radius * sin(angle);
        vertices[i * 3 + 2] = 0.0f;
    }

    int evenCount = 0;
    int oddCount = 0;

    for (int i = 0; i < TEETH; i++)
    {
        int a = (2 * i) % (TEETH * 2);
        int b = (2 * i + 1) % (TEETH * 2);
        int c = (2 * i + 2) % (TEETH * 2);

        if (i % 2 == 0)
        {
            evenIndices[evenCount++] = a;
            evenIndices[evenCount++] = b;
            evenIndices[evenCount++] = c;
        }
        else
        {
            oddIndices[oddCount++] = a;
            oddIndices[oddCount++] = b;
            oddIndices[oddCount++] = c;
        }
    }
}

void drawGear()
{
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, vertices);

    glColor3f(1.0f, 0.3f, 0.2f);

    glDrawElements(
        GL_TRIANGLES,
        TEETH / 2 * 3,
        GL_UNSIGNED_BYTE,
        evenIndices
    );

    glColor3f(0.2f, 0.5f, 1.0f);

    glDrawElements(
        GL_TRIANGLES,
        TEETH / 2 * 3,
        GL_UNSIGNED_BYTE,
        oddIndices
    );

    glDisableClientState(GL_VERTEX_ARRAY);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    drawGear();

    glFlush();
}

int main(int argc, char** argv)
{
    generateGear();

    glutInit(&argc, argv);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Q17 - Procedural Gear Shape");

    glutDisplayFunc(display);

    glutMainLoop();
    return 0;
}