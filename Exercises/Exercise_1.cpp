#define GL_SILENCE_DEPRECATION

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <iostream>
#include <string>

using namespace std;

// --------------------------------------------------
// Window size
// --------------------------------------------------

const int WINDOW_WIDTH = 1000;
const int WINDOW_HEIGHT = 500;

// --------------------------------------------------
// Course structure
// --------------------------------------------------

struct Course
{
    string code;
    string title;
    string section;
    string units;
    string days;
    string time;
    string room;
};

// --------------------------------------------------
// Course data
// --------------------------------------------------

Course courses[] =
{
    {
        "CS0011",
        "MOBILE PROGRAMMING",
        "TN33",
        "3",
        "M / W",
        "15:00:00-16:50:00 / 15:00:00-16:50:00",
        "F608 / F1209"
    },

    {
        "CS0019",
        "MODELING AND SIMULATION",
        "TS31",
        "3",
        "F / T",
        "11:00:00-12:50:00 / 11:00:00-12:50:00",
        "ONLINE / ONLINE"
    },

    {
        "CS0037",
        "SOCIAL ISSUES AND PROFESSIONAL PRACTICE",
        "TN45",
        "3",
        "S / W",
        "13:00:00-14:50:00 / 13:00:00-14:50:00",
        "E603 / E603"
    },

    {
        "CS0039",
        "CS PROJECT 2",
        "TN49",
        "3",
        "T / TH",
        "15:00:00-16:50:00 / 15:00:00-16:50:00",
        "ONLINE / FTIC Project Room (CCS)"
    },

    {
        "CS0045",
        "CS ELECTIVE - COMPUTER GRAPHICS AND VISUAL COMPUTING",
        "TN35",
        "3",
        "M / TH",
        "13:00:00-14:50:00 / 13:00:00-14:50:00",
        "E601 / E610"
    },

    {
        "CS0053",
        "CS SPECIALIZATION 2 - PROGRAMMING TOOLS AND TECHNIQUES",
        "TN37",
        "3",
        "M / W",
        "17:00:00-18:50:00 / 17:00:00-18:50:00",
        "F702 / F608"
    },

    {
        "GED0075",
        "LINEAR ALGEBRA",
        "TN23",
        "3",
        "F / T",
        "13:00:00-14:50:00 / 13:00:00-14:50:00",
        "ONLINE / ONLINE"
    }
};

const int COURSE_COUNT = sizeof(courses) / sizeof(courses[0]);

// --------------------------------------------------
// Draw text
// --------------------------------------------------

void drawText(float x, float y, string text, void* font = GLUT_BITMAP_HELVETICA_10)
{
    glRasterPos2f(x, y);

    for (char c : text)
    {
        glutBitmapCharacter(font, c);
    }
}

// --------------------------------------------------
// Draw filled rectangle
// --------------------------------------------------

void drawRectangle(
    float left,
    float bottom,
    float right,
    float top
)
{
    glBegin(GL_QUADS);

    glVertex2f(left, bottom);
    glVertex2f(right, bottom);
    glVertex2f(right, top);
    glVertex2f(left, top);

    glEnd();
}

// --------------------------------------------------
// Draw rectangle border
// --------------------------------------------------

void drawBorder(
    float left,
    float bottom,
    float right,
    float top
)
{
    glBegin(GL_LINE_LOOP);

    glVertex2f(left, bottom);
    glVertex2f(right, bottom);
    glVertex2f(right, top);
    glVertex2f(left, top);

    glEnd();
}

// --------------------------------------------------
// Display
// --------------------------------------------------

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    // --------------------------------------------------
    // Table position
    // --------------------------------------------------

    float tableLeft = 30.0f;
    float tableRight = 970.0f;

    float tableTop = 460.0f;

    float headerHeight = 35.0f;
    float rowHeight = 43.0f;

    float headerBottom = tableTop - headerHeight;

    // --------------------------------------------------
    // Background
    // --------------------------------------------------

    glColor3f(0.96f, 0.93f, 0.89f);

    drawRectangle(
        0,
        0,
        WINDOW_WIDTH,
        WINDOW_HEIGHT
    );

    // --------------------------------------------------
    // Text Color
    // --------------------------------------------------

    glColor3f(0.25f, 0.20f, 0.17f);

    // --------------------------------------------------
    // Student info
    // --------------------------------------------------
    drawText(
        30.0f,
        555.0f,
        "Enrollment Status : ENROLLED"
    );

    // Student Number
    drawText(
        30.0f,
        535.0f,
        "Student # : 202311851"
    );


    // Name
    drawText(
        30.0f,
        515.0f,
        "Name : LOSITO, JULIANA ROSANN CALAMAYA"
    );


    // Phone
    drawText(
        30.0f,
        495.0f,
        "Phone : 09159223113"
    );


    // Zip Code
    drawText(
        180.0f,
        495.0f,
        "Zip Code : 1403"
    );


    // Classification
    drawText(
        30.0f,
        475.0f,
        "Classification :"
    );


    // --------------------------------------------------
    // RIGHT SIDE INFORMATION
    // --------------------------------------------------

    // College and Program
    drawText(
        500.0f,
        535.0f,
        "College : COMPUTER STUDIES"
    );

    drawText(
        720.0f,
        535.0f,
        "Program : BSCSSE"
    );


    // Year Level
    drawText(
        500.0f,
        515.0f,
        "Year Level : 3"
    );


    // Term
    drawText(
        600.0f,
        515.0f,
        "1st term, SY 26-27"
    );


    // Address
    drawText(
        500.0f,
        495.0f,
        "Address : 114 3rd street 6th avenue caloocan city"
    );

    // --------------------------------------------------
    // Column positions
    // --------------------------------------------------

    float colCourse = 45.0f;
    float colTitle = 100.0f;
    float colSection = 450.0f;
    float colUnits = 510.0f;
    float colDays = 550.0f;
    float colTime = 590.0f;
    float colRoom = 795.0f;

    // --------------------------------------------------
    // Header background
    // --------------------------------------------------

    glColor3f(
        0.89f,
        0.84f,
        0.78f
    );

    drawRectangle(
        tableLeft,
        headerBottom,
        tableRight,
        tableTop
    );

    // --------------------------------------------------
    // Header text
    // --------------------------------------------------

    glColor3f(0.25f, 0.20f, 0.17f);

    drawText(
        colCourse,
        headerBottom + 13,
        "Course"
    );

    drawText(
        colTitle,
        headerBottom + 13,
        "Title"
    );

    drawText(
        colSection,
        headerBottom + 13,
        "Section"
    );

    drawText(
        colUnits,
        headerBottom + 13,
        "Units"
    );

    drawText(
        colDays,
        headerBottom + 13,
        "Days"
    );

    drawText(
        colTime,
        headerBottom + 13,
        "Time"
    );

    drawText(
        colRoom,
        headerBottom + 13,
        "Room"
    );

    // --------------------------------------------------
    // Course rows
    // --------------------------------------------------

    float currentTop = headerBottom;

    for (int i = 0; i < 7; i++)
    {
        float rowTop = currentTop;
        float rowBottom = rowTop - rowHeight;

        // Alternating row colors
        if (i % 2 == 0)
        {
            glColor3f(
                0.99f,
                0.97f,
                0.94f
            );
        }
        else
        {
            glColor3f(
                0.94f,
                0.90f,
                0.85f
            );
        }

        drawRectangle(
            tableLeft,
            rowBottom,
            tableRight,
            rowTop
        );

        // --------------------------------------------------
        // Course code
        // --------------------------------------------------

        glColor3f(
            0.48f,
            0.34f,
            0.27f
        );

        drawText(
            colCourse,
            rowBottom + 17,
            courses[i].code
        );

        // --------------------------------------------------
        // Course title
        // --------------------------------------------------

        glColor3f(
            0.25f,
            0.20f,
            0.17f
        );

        drawText(
            colTitle,
            rowBottom + 17,
            courses[i].title
        );

        // --------------------------------------------------
        // Section
        // --------------------------------------------------

        drawText(
            colSection,
            rowBottom + 17,
            courses[i].section
        );

        // --------------------------------------------------
        // Units
        // --------------------------------------------------

        drawText(
            colUnits,
            rowBottom + 17,
            courses[i].units
        );

        // --------------------------------------------------
        // Days
        // --------------------------------------------------

        drawText(
            colDays,
            rowBottom + 17,
            courses[i].days
        );

        // --------------------------------------------------
        // Time
        // --------------------------------------------------

        drawText(
            colTime,
            rowBottom + 17,
            courses[i].time
        );

        // --------------------------------------------------
        // Room
        // --------------------------------------------------

        drawText(
            colRoom,
            rowBottom + 17,
            courses[i].room
        );

        // Row separator
        glColor3f(
            0.84f,
            0.79f,
            0.73f
        );

        glBegin(GL_LINES);

        glVertex2f(tableLeft, rowBottom);
        glVertex2f(tableRight, rowBottom);

        glEnd();

        currentTop = rowBottom;
    }

    // --------------------------------------------------
    // Total Units Row
    // --------------------------------------------------

    float totalBottom = currentTop - 35.0f;

    glColor3f(
        0.88f,
        0.82f,
        0.75f
    );

    drawRectangle(
        tableLeft,
        totalBottom,
        tableRight,
        currentTop
    );

    glColor3f(
        0.25f,
        0.19f,
        0.15f
    );

    drawText(
        colCourse,
        totalBottom + 13,
        "TOTAL UNITS 21"
    );

    // --------------------------------------------------
    // Outer table border
    // --------------------------------------------------

    glColor3f(
        0.55f,
        0.48f,
        0.41f
    );

    drawBorder(
        tableLeft,
        totalBottom,
        tableRight,
        tableTop
    );

    glFlush();
}

// --------------------------------------------------
// Initialization
// --------------------------------------------------

void init()
{
    glClearColor(
        0.96f,
        0.93f,
        0.89f,
        1.0f
    );

    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();

    gluOrtho2D(
        0.0,
        WINDOW_WIDTH,
        0.0,
        WINDOW_HEIGHT
    );

    glMatrixMode(GL_MODELVIEW);

    glLoadIdentity();
}

// --------------------------------------------------
// Main
// --------------------------------------------------

int main(int argc, char** argv)
{
    glutInit(&argc, argv);

    glutInitDisplayMode(
        GLUT_SINGLE |
        GLUT_RGB
    );

    glutInitWindowSize(
        WINDOW_WIDTH,
        WINDOW_HEIGHT
    );

    glutInitWindowPosition(
        100,
        100
    );

    glutCreateWindow(
        "Student Course Schedule"
    );

    init();

    glutDisplayFunc(display);

    glutMainLoop();

    return 0;
}