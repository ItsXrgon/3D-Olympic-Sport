#include "Arrow.h"
#include "../../Globals.h"
#include <vector>
#include <string>
#include <cstdlib>
#include <GL/glut.h>

Arrow::Arrow() {
    isAnimating = false;
	timeFactor = 0.0f;
}


void Arrow::draw(float x, float y, float z) {
    float red = (sin(timeFactor) + 1.0f) / 2.0f;   // Red component
    float green = (sin(timeFactor + 2.0f) + 1.0f) / 2.0f; // Green component
    float blue = (sin(timeFactor + 4.0f) + 1.0f) / 2.0f;  // Blue component

    glColor3f(red, green, blue);

    // Draw the arrow shaft (a vertical pole, scaled cube)
    glPushMatrix();
    glTranslatef(x, y, z);  // Position the arrow

    glPushMatrix();
    glScalef(0.05f, 1.0f, 0.05f);  // Scale to make the pole (shaft)
    glutSolidCube(1.0f);  // Draw shaft using a scaled cube
    glPopMatrix();

    // Draw the arrow tip (cone at the top)
    glPushMatrix();
    glTranslatef(0, 0.5f, 0);  // Position the tip at the top of the shaft
    glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
    glColor3f(0.8f, 0.8f, 0.8f);  // Gray color for the tip (metallic)
    glutSolidCone(0.1f, 0.3f, 10, 10);  // Cone as the sharp arrowhead
    glPopMatrix();

    // Draw the arrow feathers (2 rotated triangles at the bottom)
    glPushMatrix();
    glColor3f(1.0f, 1.0f, 1.0f);  // White color for the feathers

    // Feather 1
    glPushMatrix();
    glTranslatef(0, -0.5f, 0);  // Position the feathers at the bottom of the shaft
    glBegin(GL_TRIANGLES);
    glVertex3f(0.0f, 0.2f, 0.0f);  // Center of the feather
    glVertex3f(0.2f, 0.0f, 0.0f);  // Feather left side
    glVertex3f(-0.2f, 0.0f, 0.0f);  // Feather right side
    glEnd();
    glPopMatrix();

    // Feather 2 (rotated 90 degrees)
    glPushMatrix();
    glTranslatef(0, -0.5f, 0);  // Position the feathers at the bottom of the shaft
    glRotatef(90, 0.0f, 1.0f, 0.0f);  // Rotate 90 degrees around the y-axis
    glBegin(GL_TRIANGLES);
    glVertex3f(0.0f, 0.2f, 0.0f);  // Center of the feather
    glVertex3f(0.2f, 0.0f, 0.0f);  // Feather left side
    glVertex3f(-0.2f, 0.0f, 0.0f);  // Feather right side
    glEnd();
    glPopMatrix();

    glPopMatrix();  // End transformations for the feathers
    glPopMatrix();  // End transformations for the arrow
}

void Arrow::update(float deltaTime) {
    if (isAnimating) {
        timeFactor = deltaTime * 100.0f;
    }
}


void Arrow::startAnimation() {
    isAnimating = true;
}

void Arrow::stopAnimation() {
    isAnimating = false;
    timeFactor = 0.0f;
}

