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

// GAME VARIABLES

float playerX = 0.0f;
float playerY = -0.70f;

int score = 0;
int lives = 3;

bool gameOver = false;

// ASTEROID VARIABLES

float asteroid1X = -0.55f;
float asteroid1Y = 0.85f;
float asteroid1Speed = 0.015f;

float asteroid2X = 0.45f;
float asteroid2Y = 1.10f;
float asteroid2Speed = 0.025f;


// DRAW BITMAP TEXT

void drawText(float x, float y, const char* text)
{
    glRasterPos2f(x, y);

    for (const char* c = text; *c != '\0'; c++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, *c);
    }
}


// DRAW SHIP

void drawShip()
{
    // Main body - triangle
    glColor3ub(197, 235, 178);

    glBegin(GL_TRIANGLES);

    glVertex2f(playerX, playerY + 0.12f);
    glVertex2f(playerX - 0.10f, playerY - 0.10f);
    glVertex2f(playerX + 0.10f, playerY - 0.10f);

    glEnd();


    // Ship wings - quad
    glColor3ub(107, 155, 191);

    glBegin(GL_QUADS);

    glVertex2f(playerX - 0.10f, playerY - 0.02f);
    glVertex2f(playerX - 0.22f, playerY - 0.10f);
    glVertex2f(playerX - 0.10f, playerY - 0.10f);
    glVertex2f(playerX, playerY - 0.02f);

    glEnd();


    // Right wing
    glBegin(GL_QUADS);

    glVertex2f(playerX, playerY - 0.02f);
    glVertex2f(playerX + 0.10f, playerY - 0.10f);
    glVertex2f(playerX + 0.22f, playerY - 0.10f);
    glVertex2f(playerX + 0.10f, playerY - 0.02f);

    glEnd();


    // Engine flame
    glColor3ub(235, 101, 21);

    glBegin(GL_TRIANGLES);

    glVertex2f(playerX - 0.05f, playerY - 0.09f);
    glVertex2f(playerX + 0.05f, playerY - 0.09f);
    glVertex2f(playerX, playerY - 0.20f);

    glEnd();
}


// ASTEROID

void drawAsteroid(float x, float y, float size)
{
    glColor3f(0.45f, 0.45f, 0.45f);

    glBegin(GL_POLYGON);

    glVertex2f(x - size, y);
    glVertex2f(x - size * 0.6f, y + size);
    glVertex2f(x + size * 0.5f, y + size * 0.8f);
    glVertex2f(x + size, y + size * 0.2f);
    glVertex2f(x + size * 0.7f, y - size * 0.8f);
    glVertex2f(x - size * 0.4f, y - size);

    glEnd();
}


// DRAW HUD

void drawHUD()
{
    char buffer[100];

    glColor3f(1.0f, 1.0f, 1.0f);

    sprintf(buffer, "Score: %d", score);
    drawText(-0.95f, 0.90f, buffer);

    sprintf(buffer, "Lives: %d", lives);
    drawText(0.65f, 0.90f, buffer);

    drawText(
        -0.95f,
        0.82f,
        "W/A/S/D - Move"
    );

    drawText(
        -0.95f,
        0.75f,
        "R - Restart"
    );

    drawText(
        -0.95f,
        0.68f,
        "ESC - Exit"
    );
}


// COLLISION DETECTION

bool checkCollision(
    float asteroidX,
    float asteroidY
)
{
    float dx = playerX - asteroidX;
    float dy = playerY - asteroidY;

    if (dx < 0)
        dx = -dx;

    if (dy < 0)
        dy = -dy;

    return dx < 0.18f && dy < 0.18f;
}


// RESET ASTEROID

void resetAsteroid(
    int asteroidNumber
)
{
    if (asteroidNumber == 1)
    {
        asteroid1X =
            -0.75f +
            static_cast<float>(rand() % 150) / 100.0f;

        asteroid1Y = 1.10f;
    }
    else
    {
        asteroid2X =
            -0.75f +
            static_cast<float>(rand() % 150) / 100.0f;

        asteroid2Y = 1.30f;
    }
}


// RESET GAME

void resetGame()
{
    playerX = 0.0f;
    playerY = -0.70f;

    score = 0;
    lives = 3;

    gameOver = false;

    asteroid1X = -0.55f;
    asteroid1Y = 0.85f;

    asteroid2X = 0.45f;
    asteroid2Y = 1.10f;

    asteroid1Speed = 0.015f;
    asteroid2Speed = 0.025f;

    cout << "Game restarted." << endl;

    glutPostRedisplay();
}


// UPDATE GAME

void updateGame(int value)
{
    if (!gameOver)
    {
        // asteroids downward movement
        asteroid1Y -= asteroid1Speed;
        asteroid2Y -= asteroid2Speed;


        // Reset asteroid when it leaves screen
        if (asteroid1Y < -1.20f)
        {
            asteroid1Y = 1.10f;

            asteroid1X =
                -0.75f +
                static_cast<float>(rand() % 150) / 100.0f;

            score++;
        }


        if (asteroid2Y < -1.20f)
        {
            asteroid2Y = 1.30f;

            asteroid2X =
                -0.75f +
                static_cast<float>(rand() % 150) / 100.0f;

            score++;
        }


        // Collision with asteroid 1
        if (checkCollision(asteroid1X, asteroid1Y))
        {
            lives--;

            cout << "Collision with Asteroid 1! "
                << "Lives remaining: "
                << lives << endl;

            resetAsteroid(1);

            if (lives <= 0)
            {
                lives = 0;
                gameOver = true;

                cout << "GAME OVER!" << endl;
            }
        }


        // Collision with asteroid 2
        if (!gameOver &&
            checkCollision(asteroid2X, asteroid2Y))
        {
            lives--;

            cout << "Collision with Asteroid 2! "
                << "Lives remaining: "
                << lives << endl;

            resetAsteroid(2);

            if (lives <= 0)
            {
                lives = 0;
                gameOver = true;

                cout << "GAME OVER!" << endl;
            }
        }
    }


    glutPostRedisplay();


    // Repeat timer
    glutTimerFunc(
        16,
        updateGame,
        0
    );
}


// DISPLAY

void display()
{
    glClearColor(
        0.03f,
        0.03f,
        0.10f,
        1.0f
    );

    glClear(GL_COLOR_BUFFER_BIT);


    // HUD
    drawHUD();


    if (!gameOver)
    {
        // Draw player
        drawShip();

        // Draw asteroids
        drawAsteroid(
            asteroid1X,
            asteroid1Y,
            0.08f
        );

        drawAsteroid(
            asteroid2X,
            asteroid2Y,
            0.11f
        );
    }
    else
    {
        glColor3f(
            1.0f,
            0.3f,
            0.3f
        );

        drawText(
            -0.25f,
            0.10f,
            "GAME OVER"
        );

        glColor3f(
            1.0f,
            1.0f,
            1.0f
        );

        drawText(
            -0.38f,
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


    // Restart
    if (key == 'r' || key == 'R')
    {
        resetGame();
        return;
    }


    if (gameOver)
        return;


    // Move left
    if (key == 'a' || key == 'A')
    {
        playerX -= 0.07f;
    }


    // Move right
    if (key == 'd' || key == 'D')
    {
        playerX += 0.07f;
    }


    // Move up
    if (key == 'w' || key == 'W')
    {
        playerY += 0.07f;
    }


    // Move down
    if (key == 's' || key == 'S')
    {
        playerY -= 0.07f;
    }


    // Boundary checking
    if (playerX < -0.80f)
        playerX = -0.80f;

    if (playerX > 0.80f)
        playerX = 0.80f;

    if (playerY < -0.85f)
        playerY = -0.85f;

    if (playerY > 0.70f)
        playerY = 0.70f;


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
        "MP01 - The Cosmic Dodger"
    );


    glutDisplayFunc(display);

    glutKeyboardFunc(keyboard);


    glutTimerFunc(
        16,
        updateGame,
        0
    );


    glutMainLoop();


    return 0;
}