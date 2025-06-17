#include <GL/glut.h>  // GLUT, includes glu.h and gl.h
#include "FD.h"
// Display callback function
void display() {
    glClear(GL_COLOR_BUFFER_BIT);  // Clear the color buffer (background)
    
    glBegin(GL_TRIANGLES);         // Draw a triangle
        glColor3f(1.0f, 0.0f, 0.0f); // Red
        glVertex2f(-0.5f, -0.5f);

        glColor3f(0.0f, 1.0f, 0.0f); // Green
        glVertex2f(0.5f, -0.5f);

        glColor3f(0.0f, 0.0f, 1.0f); // Blue
        glVertex2f(0.0f, 0.5f);
    glEnd();

    glFlush();  // Render now
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);                        // Initialize GLUT
    glutCreateWindow("Simple OpenGL in C");       // Create a window
    glutInitWindowSize(640, 480);                 // Set window size
    glutInitWindowPosition(50, 50);               // Set window position
    glutDisplayFunc(display);                     // Register display callback
    glutMainLoop();                               // Enter the event loop
    return 0;
}

