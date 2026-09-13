#include <GL/glut.h>   
#include <iostream>
#include <string>
#include <cstdlib>   

const float colors[6][3] = {
    {1.0f, 0.0f, 0.0f}, // 1: Red
    {0.0f, 1.0f, 0.0f}, // 2: Green
    {0.0f, 0.0f, 1.0f}, // 3: Blue
    {1.0f, 1.0f, 0.0f}, // 4: Yellow
    {1.0f, 0.0f, 1.0f}, // 5: Magenta
    {0.0f, 1.0f, 1.0f}  // 6: Cyan
};

const std::string colorNames[6] = {
    "Red", "Green", "Blue", "Yellow", "Magenta", "Cyan"
};

int currentColorIndex = 0;

void display() {
    // Clear the screen with the currently selected color
    glClearColor(colors[currentColorIndex][0], 
                 colors[currentColorIndex][1], 
                 colors[currentColorIndex][2], 
                 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    
    glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y) {
    if (key == 27) {
        std::cout << "Exiting program..." << std::endl;
        exit(0);
    }
    
    if (key >= '1' && key <= '6') {
        currentColorIndex = key - '1';
        
        std::cout << "Selected Color: " << colorNames[currentColorIndex] << std::endl;
        
        glutPostRedisplay();
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Keyboard Color Picker");

    std::cout << "Press keys 1-6 to change background colors. Press ESC to quit." << std::endl;
    std::cout << "Current Color: " << colorNames[currentColorIndex] << std::endl;

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);

    glutMainLoop();
    return 0;
}

