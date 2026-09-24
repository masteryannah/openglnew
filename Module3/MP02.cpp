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

using namespace std;

// PLAYER COLOR
// 0 = RED
// 1 = GREEN
// 2 = BLUE

int playerColor = 0;


// BARRIER COLOR

int barrierColor = 1;


// GAME VARIABLES

int score = 0;

bool gameOver = false;

float barrierX = -1.20f;

float barrierSpeed = 0.015f;


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


// SET COLOR

void setColor(int color)
{
    if (color == 0)
    {
        glColor3f(
            1.0f,
            0.0f,
            0.0f
        );
    }
    else if (color == 1)
    {
        glColor3f(
            0.0f,
            1.0f,
            0.0f
        );
    }
    else
    {
        glColor3f(
            0.0f,
            0.0f,
            1.0f
        );
    }
}


// COLOR NAME

const char* getColorName(int color)
{
    if (color == 0)
        return "RED";

    if (color == 1)
        return "GREEN";

    return "BLUE";
}


// DRAW PLAYER

void drawPlayer()
{
    setColor(playerColor);

    glBegin(GL_QUADS);

    glVertex2f(
        -0.12f,
        -0.12f
    );

    glVertex2f(
        0.12f,
        -0.12f
    );

    glVertex2f(
        0.12f,
        0.12f
    );

    glVertex2f(
        -0.12f,
        0.12f
    );

    glEnd();
}


// DRAW BARRIER

void drawBarrier()
{
    setColor(barrierColor);

    glBegin(GL_QUADS);

    glVertex2f(
        barrierX - 0.08f,
        -0.60f
    );

    glVertex2f(
        barrierX + 0.08f,
        -0.60f
    );

    glVertex2f(
        barrierX + 0.08f,
        0.60f
    );

    glVertex2f(
        barrierX - 0.08f,
        0.60f
    );

    glEnd();
}


// CHECK COLORS

bool colorsMatch()
{
    return playerColor == barrierColor;
}


// SPAWN NEXT BARRIER

void spawnNextBarrier()
{
    barrierX = -1.20f;

    barrierColor =
        rand() % 3;
}


// RESET GAME

void resetGame()
{
    score = 0;

    gameOver = false;

    playerColor = 0;

    barrierColor = 1;

    barrierX = -1.20f;

    barrierSpeed = 0.015f;

    cout << "Game restarted." << endl;

    glutPostRedisplay();
}


// CHECK BARRIER COLLISION

void checkGateCollision()
{
    if (barrierX > -0.15f &&
        barrierX < 0.15f)
    {
        if (colorsMatch())
        {
            score++;

            cout << "Correct color match! "
                << "Score: "
                << score
                << endl;

            // Increase speed gradually
            barrierSpeed += 0.001f;

            // Keep speed playable
            if (barrierSpeed > 0.030f)
            {
                barrierSpeed = 0.030f;
            }

            spawnNextBarrier();
        }
        else
        {
            cout << "Wrong color! GAME OVER."
                << endl;

            gameOver = true;
        }
    }
}


// UPDATE BARRIER

void updateBarrier(int value)
{
    if (!gameOver)
    {
        barrierX += barrierSpeed;

        checkGateCollision();


        // If barrier passes the player
        if (barrierX > 1.20f)
        {
            spawnNextBarrier();
        }
    }


    glutPostRedisplay();


    // Repeat timer
    glutTimerFunc(
        16,
        updateBarrier,
        0
    );
}


// DRAW DASHBOARD

void drawDashboard()
{
    char buffer[100];

    glColor3f(
        1.0f,
        1.0f,
        1.0f
    );


    sprintf(
        buffer,
        "Score: %d",
        score
    );

    drawText(
        -0.95f,
        0.90f,
        buffer
    );


    sprintf(
        buffer,
        "Player Color: %s",
        getColorName(playerColor)
    );

    drawText(
        0.45f,
        0.90f,
        buffer
    );


    drawText(
        -0.95f,
        0.80f,
        "R = Red"
    );

    drawText(
        -0.95f,
        0.73f,
        "G = Green"
    );

    drawText(
        -0.95f,
        0.66f,
        "B = Blue"
    );


    drawText(
        0.45f,
        0.80f,
        "Match the barrier color!"
    );


    drawText(
        0.45f,
        0.73f,
        "Wrong color = GAME OVER"
    );


    drawText(
        0.45f,
        0.66f,
        "R = Restart"
    );
}


// DISPLAY

void display()
{
    glClearColor(
        0.05f,
        0.05f,
        0.08f,
        1.0f
    );

    glClear(GL_COLOR_BUFFER_BIT);


    drawDashboard();


    if (!gameOver)
    {
        drawPlayer();

        drawBarrier();
    }
    else
    {
        glColor3f(
            1.0f,
            0.2f,
            0.2f
        );

        drawText(
            -0.28f,
            0.10f,
            "GAME OVER"
        );


        glColor3f(
            1.0f,
            1.0f,
            1.0f
        );

        drawText(
            -0.35f,
            -0.02f,
            "Press R to Restart"
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
    if (key == 27)
    {
        exit(0);
    }


    if (key == 'r' || key == 'R')
    {
        if (gameOver)
        {
            resetGame();
        }
        else
        {
            playerColor = 0;
        }
    }


    if (!gameOver)
    {
        if (key == 'g' || key == 'G')
        {
            playerColor = 1;

            cout << "Player color: GREEN"
                << endl;
        }


        if (key == 'b' || key == 'B')
        {
            playerColor = 2;

            cout << "Player color: BLUE"
                << endl;
        }


        if (key == 'r' || key == 'R')
        {
            playerColor = 0;

            cout << "Player color: RED"
                << endl;
        }
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


    glutInit(
        &argc,
        argv
    );


    glutInitDisplayMode(
        GLUT_SINGLE |
        GLUT_RGB
    );


    glutInitWindowSize(
        800,
        700
    );


    glutCreateWindow(
        "MP02 - Chroma-Shift"
    );


    glutDisplayFunc(display);

    glutKeyboardFunc(keyboard);


    glutTimerFunc(
        16,
        updateBarrier,
        0
    );


    glutMainLoop();


    return 0;
}