#include <GL/glut.h>
#include <iostream>
#include <cmath>
#include <cstdlib>

const int STRIPE_COUNT = 13; 

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;

const float PI = 3.1415926535f;

void drawFilledStar(float cx, float cy, float outerRadius, float innerRadius) {
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx, cy); 
    
    for (int i = 0; i <= 10; ++i) {
        float angle = i * (2.0f * PI / 10.0f);
        
        angle += PI / 2.0f; 

        float r = (i % 2 == 0) ? outerRadius : innerRadius;
        
        float x = cx + r * cos(angle);
        float y = cy + r * sin(angle);
        glVertex2f(x, y);
    }
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    float stripeHeight = static_cast<float>(WINDOW_HEIGHT) / STRIPE_COUNT;

    for (int i = 0; i < STRIPE_COUNT; ++i) {
        if (i % 2 == 0) {
            glColor3f(0.7f, 0.0f, 0.0f); // Dark Red
        } else {
            glColor3f(1.0f, 1.0f, 1.0f); // White
        }

        float yMin = i * stripeHeight;
        float yMax = (i + 1) * stripeHeight;

        glBegin(GL_QUADS);
            glVertex2f(0.0f, yMin);
            glVertex2f(static_cast<float>(WINDOW_WIDTH), yMin);
            glVertex2f(static_cast<float>(WINDOW_WIDTH), yMax);
            glVertex2f(0.0f, yMax);
        glEnd();
    }

   
    float cantonWidth = WINDOW_WIDTH * 0.40f;
    float cantonHeight = WINDOW_HEIGHT * 0.55f;
    float cantonYMin = WINDOW_HEIGHT - cantonHeight;

    glColor3f(0.0f, 0.0f, 0.4f); // Dark Blue
    glBegin(GL_QUADS);
        glVertex2f(0.0f, cantonYMin);
        glVertex2f(cantonWidth, cantonYMin);
        glVertex2f(cantonWidth, static_cast<float>(WINDOW_HEIGHT));
        glVertex2f(0.0f, static_cast<float>(WINDOW_HEIGHT));
    glEnd();

    
    float starCx = cantonWidth / 2.0f;
    float starCy = cantonYMin + (cantonHeight / 2.0f);
    float starOuterRadius = 45.0f;
    float starInnerRadius = 18.0f; 
    glColor3f(1.0f, 1.0f, 0.0f); // Gold/Yellow Star
    drawFilledStar(starCx, starCy, starOuterRadius, starInnerRadius);

    glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y) {
    if (key == 27) { // ESC key
        std::cout << "Exiting program..." << std::endl;
        exit(0);
    }
}

void init() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Black canvas backup
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, WINDOW_WIDTH, 0.0, WINDOW_HEIGHT);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    glutCreateWindow("Dynamic Flag with Star Generator");

    init();

    std::cout << "Rendering flag with " << STRIPE_COUNT << " configurable stripes." << std::endl;
    std::cout << "Press ESC to quit." << std::endl;

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);

    glutMainLoop();
    return 0;
}

