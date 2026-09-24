#define GL_SILENCE_DEPRECATION

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#include <GL/freeglut_ext.h>
#endif

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;


// CONSTANTS

const int MAX_BURSTS = 20;

const float PI = 3.14159265f;


// BURST STRUCTURE

struct Burst
{
    bool active;

    int type;

    float x;
    float y;

    float size;

    float brightness;

    float speed;
};


// BURST ARRAY

Burst bursts[MAX_BURSTS];


// CURRENT MODE

int currentMode = 1;


// DRAW TEXT

void drawText(
    float x,
    float y,
    const char* text
)
{
    glRasterPos2f(x, y);

    for (const char* c = text; *c != '\0'; c++)
    {
        glutBitmapCharacter(
            GLUT_BITMAP_HELVETICA_12,
            *c
        );
    }
}


// INITIALIZE BURSTS

void initializeBursts()
{
    for (int i = 0; i < MAX_BURSTS; i++)
    {
        bursts[i].active = false;
        bursts[i].type = 1;
        bursts[i].x = 0.0f;
        bursts[i].y = 0.0f;
        bursts[i].size = 0.0f;
        bursts[i].brightness = 1.0f;
        bursts[i].speed = 0.01f;
    }
}


// SPAWN BURST

void spawnBurst(
    int type,
    float x,
    float y
)
{
    for (int i = 0; i < MAX_BURSTS; i++)
    {
        if (!bursts[i].active)
        {
            bursts[i].active = true;

            bursts[i].type = type;

            bursts[i].x = x;
            bursts[i].y = y;

            bursts[i].size = 0.05f;

            bursts[i].brightness = 1.0f;

            bursts[i].speed = 0.015f;

            cout << "Burst created: Type "
                << type
                << endl;

            return;
        }
    }


    cout << "Maximum active bursts reached."
        << endl;
}


// DRAW CONCENTRIC SQUARES

void drawSquares(Burst& burst)
{
    glColor3f(
        burst.brightness,
        0.4f * burst.brightness,
        1.0f * burst.brightness
    );


    for (int i = 1; i <= 4; i++)
    {
        float size =
            burst.size * i * 0.35f;


        glBegin(GL_LINE_LOOP);

        glVertex2f(
            burst.x - size,
            burst.y - size
        );

        glVertex2f(
            burst.x + size,
            burst.y - size
        );

        glVertex2f(
            burst.x + size,
            burst.y + size
        );

        glVertex2f(
            burst.x - size,
            burst.y + size
        );

        glEnd();
    }
}


// DRAW DIAMOND LATTICE

void drawDiamonds(Burst& burst)
{
    glColor3f(
        0.4f * burst.brightness,
        1.0f * burst.brightness,
        0.6f * burst.brightness
    );


    float size = burst.size;


    glBegin(GL_LINES);

    // Diamond 1
    glVertex2f(
        burst.x,
        burst.y + size
    );

    glVertex2f(
        burst.x + size,
        burst.y
    );

    glVertex2f(
        burst.x + size,
        burst.y
    );

    glVertex2f(
        burst.x,
        burst.y - size
    );

    glVertex2f(
        burst.x,
        burst.y - size
    );

    glVertex2f(
        burst.x - size,
        burst.y
    );

    glVertex2f(
        burst.x - size,
        burst.y
    );

    glVertex2f(
        burst.x,
        burst.y + size
    );


    // Inner diamond
    size *= 0.5f;

    glVertex2f(
        burst.x,
        burst.y + size
    );

    glVertex2f(
        burst.x + size,
        burst.y
    );

    glVertex2f(
        burst.x + size,
        burst.y
    );

    glVertex2f(
        burst.x,
        burst.y - size
    );

    glVertex2f(
        burst.x,
        burst.y - size
    );

    glVertex2f(
        burst.x - size,
        burst.y
    );

    glVertex2f(
        burst.x - size,
        burst.y
    );

    glVertex2f(
        burst.x,
        burst.y + size
    );

    glEnd();
}


// DRAW STARBURST TRIANGLES

void drawStarburst(Burst& burst)
{
    glColor3f(
        1.0f * burst.brightness,
        0.5f * burst.brightness,
        0.1f * burst.brightness
    );

    float size = burst.size;

    // Create 8 visible triangular rays
    for (int i = 0; i < 8; i++)
    {
        float angle1 =
            (2.0f * PI * i) / 8.0f;

        float angle2 =
            (2.0f * PI * (i + 1)) / 8.0f;

        float x1 =
            burst.x +
            cos(angle1) * size;

        float y1 =
            burst.y +
            sin(angle1) * size;

        float x2 =
            burst.x +
            cos(angle2) * size;

        float y2 =
            burst.y +
            sin(angle2) * size;


        glBegin(GL_TRIANGLES);

        glVertex2f(
            burst.x,
            burst.y
        );

        glVertex2f(
            x1,
            y1
        );

        glVertex2f(
            x2,
            y2
        );

        glEnd();
    }
}


// DRAW BURST

void drawBurst(Burst& burst)
{
    if (!burst.active)
        return;


    if (burst.type == 1)
    {
        drawSquares(burst);
    }
    else if (burst.type == 2)
    {
        drawDiamonds(burst);
    }
    else if (burst.type == 3)
    {
        drawStarburst(burst);
    }
}


// UPDATE BURSTS

void updateBursts(int value)
{
    for (int i = 0; i < MAX_BURSTS; i++)
    {
        if (bursts[i].active)
        {
            // Expand
            bursts[i].size +=
                bursts[i].speed;


            // Fade
            bursts[i].brightness -=
                0.015f;


            // Remove expired burst
            if (bursts[i].brightness <= 0.0f)
            {
                bursts[i].active = false;

                bursts[i].brightness = 0.0f;
            }
        }
    }


    glutPostRedisplay();


    // Schedule timer again
    glutTimerFunc(
        16,
        updateBursts,
        0
    );
}


// COUNT ACTIVE BURSTS

int countActiveBursts()
{
    int count = 0;

    for (int i = 0; i < MAX_BURSTS; i++)
    {
        if (bursts[i].active)
        {
            count++;
        }
    }

    return count;
}


// DRAW SIDEBAR / HUD

void drawSidebar()
{
    char buffer[100];


    glColor3f(
        1.0f,
        1.0f,
        1.0f
    );


    drawText(
        -0.95f,
        0.90f,
        "=== FIREWORK BURST STUDIO ==="
    );


    drawText(
        -0.95f,
        0.82f,
        "1 - Concentric Squares"
    );


    drawText(
        -0.95f,
        0.75f,
        "2 - Diamond Lattice"
    );


    drawText(
        -0.95f,
        0.68f,
        "3 - Starburst Triangles"
    );


    drawText(
        -0.95f,
        0.61f,
        "SPACE - Random Burst"
    );


    drawText(
        -0.95f,
        0.54f,
        "ESC - Exit"
    );


    sprintf(
        buffer,
        "Active Bursts: %d",
        countActiveBursts()
    );


    drawText(
        0.45f,
        0.90f,
        buffer
    );


    sprintf(
        buffer,
        "Current Mode: %d",
        currentMode
    );


    drawText(
        0.45f,
        0.82f,
        buffer
    );
}


// DISPLAY

void display()
{
    glClearColor(
        0.02f,
        0.02f,
        0.05f,
        1.0f
    );


    glClear(
        GL_COLOR_BUFFER_BIT
    );


    // HUD
    drawSidebar();


    // Draw all active bursts
    for (int i = 0; i < MAX_BURSTS; i++)
    {
        drawBurst(
            bursts[i]
        );
    }


    glFlush();
}


// KEYBOARD

void keyboard(
    unsigned char key,
    int x,
    int y
)
{
    // Exit
    if (key == 27)
    {
        exit(0);
    }


    // Type 1
    if (key == '1')
    {
        currentMode = 1;

        spawnBurst(
            1,
            -0.20f,
            0.0f
        );
    }


    // Type 2
    else if (key == '2')
    {
        currentMode = 2;

        spawnBurst(
            2,
            0.0f,
            0.0f
        );
    }


    // Type 3
    else if (key == '3')
    {
        currentMode = 3;

        spawnBurst(
            3,
            0.20f,
            0.0f
        );
    }


    // Random burst
    else if (key == ' ')
    {
        int type =
            1 + rand() % 3;


        currentMode = type;


        float x =
            -0.75f +
            static_cast<float>(
                rand() % 150
                ) / 100.0f;


        float y =
            -0.60f +
            static_cast<float>(
                rand() % 120
                ) / 100.0f;


        spawnBurst(
            type,
            x,
            y
        );
    }


    glutPostRedisplay();
}


// MAIN

int main(
    int argc,
    char** argv
)
{
    srand(
        static_cast<unsigned int>(
            time(0)
            )
    );


    initializeBursts();


    glutInit(
        &argc,
        argv
    );


    glutInitDisplayMode(
        GLUT_SINGLE |
        GLUT_RGB
    );


    glutInitWindowSize(
        900,
        700
    );


    glutCreateWindow(
        "MP03 - Dynamic Fireworks & Shape Burst Studio"
    );


    glutDisplayFunc(display);

    glutKeyboardFunc(keyboard);


    // Start animation timer
    glutTimerFunc(
        16,
        updateBursts,
        0
    );


    glutMainLoop();


    return 0;
}