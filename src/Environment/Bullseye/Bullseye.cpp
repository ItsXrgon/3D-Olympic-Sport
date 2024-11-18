#include "Bullseye.h"
#include "../../Globals.h"
#include <vector>
#include <string>
#include <cstdlib>
#include <GL/glut.h>

float scale = 1.0f;

Bullseye::Bullseye() {
    isAnimating = false;
}


void Bullseye::draw(float x, float y, float z) {
    glPushMatrix();
    glTranslatef(x, y, z - 0.1f); // Position the stand at the desired location

    glColor3f(0.6f, 0.3f, 0.0f); // Set the color to brown for a wooden stand

    glPushMatrix();
    glTranslatef(-0.5f, -1.5f, 0.0f); // Position left leg
    glRotatef(-15.0f, 0.0f, 0.0f, 1.0f); // Slant left leg
    glScalef(0.1f, 3.0f, 0.1f); // Scale to create a long narrow leg
    glutSolidCube(1.0f); // Left leg
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.5f, -1.5f, 0.0f); // Position right leg
    glRotatef(15.0f, 0.0f, 0.0f, 1.0f); // Slant right leg
    glScalef(0.1f, 3.0f, 0.1f); // Scale to create a long narrow leg
    glutSolidCube(1.0f); // Right leg
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, -0.8f, 0.0f); // Position the bar between the legs
    glScalef(1.5f, 0.1f, 0.1f); // Scale to make it a horizontal bar
    glutSolidCube(1.0f); // Support bar
    glPopMatrix();

    glPopMatrix();

    glPushMatrix();
	glScaled(scale, scale, 1);
    glTranslatef(x, y, z);

    struct Ring {
        float outerRadius, innerRadius;
        float r, g, b; // RGB color values
    };

    Ring rings[] = {
        {0.8f, 0.6f, 0.0f, 0.0f, 0.0f},  // Outer ring - Black  (Hollow)
        {0.6f, 0.4f, 0.0f, 0.0f, 1.0f},  // Second ring - Blue (Hollow)
        {0.4f, 0.2f, 1.0f, 0.0f, 0.0f},  // Third ring - Red (Hollow)
        {0.2f, 0.0f, 1.0f, 1.0f, 0.0f},  // Fourth ring - Yellow (Hollow)
    };

    for (int i = 0; i < 4; ++i) {
        glColor3f(rings[i].r, rings[i].g, rings[i].b); // Set ring color

        if (rings[i].innerRadius > 0.0f) {
            glBegin(GL_TRIANGLE_STRIP);
            for (int angle = 0; angle <= 360; ++angle) {
                float theta = angle * 3.14159f / 180.0f; // Convert degrees to radians
                float outerX = rings[i].outerRadius * cos(theta);
                float outerY = rings[i].outerRadius * sin(theta);
                float innerX = rings[i].innerRadius * cos(theta);
                float innerY = rings[i].innerRadius * sin(theta);

                glVertex3f(outerX, outerY, 0.0f); // Outer edge point
                glVertex3f(innerX, innerY, 0.0f); // Inner edge point
            }
            glEnd();
        }
        else {
            glBegin(GL_TRIANGLE_FAN);
            glVertex3f(0.0f, 0.0f, 0.0f); // Center of the circle
            for (int angle = 0; angle <= 360; ++angle) {
                float theta = angle * 3.14159f / 180.0f; // Convert degrees to radians
                float px = rings[i].outerRadius * cos(theta);
                float py = rings[i].outerRadius * sin(theta);
                glVertex3f(px, py, 0.0f); // Points on the circle
            }
            glEnd();
        }
    }
    glPopMatrix();
}

void Bullseye::update(float deltaTime) {
    if (isAnimating) {
		scale = 0.1f * sin(glutGet(GLUT_ELAPSED_TIME) * 0.005f) + 1.0f;
    }
}


void Bullseye::startAnimation() {
    isAnimating = true;
}

void Bullseye::stopAnimation() {
    isAnimating = false;
    scale = 1.0f;
}

