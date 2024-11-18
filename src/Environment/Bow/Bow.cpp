#include "Bow.h"
#include "../../Globals.h"
#include <vector>
#include <string>
#include <cstdlib>
#include <GL/glut.h>


Bow::Bow() {
    isAnimating = false;
    rotateAng = 0.0f;
}


void Bow::draw(float x, float y, float z) {
    float radius = 1.0f;
    float thickness = 0.1f;
    glPushMatrix();
    glTranslatef(x, y, z); // Position the scoreboard
    glRotatef(rotateAng, 0.0f, 1.0f, 0.0f);

    int numSegments = 100;         // Number of segments for the half-circle
    float thetaStep = M_PI / numSegments;  // Angle step for the half-circle

    // Draw the bow frame as a thick half-circle
    glBegin(GL_QUAD_STRIP);
    for (int i = 0; i <= numSegments; ++i) {
        float theta = i * thetaStep;

        // Outer edge of the bow
        float outerX = x + (radius + thickness / 2.0f) * cos(theta);
        float outerY = y + (radius + thickness / 2.0f) * sin(theta);
        float outerZ = z;

        // Inner edge of the bow
        float innerX = x + (radius - thickness / 2.0f) * cos(theta);
        float innerY = y + (radius - thickness / 2.0f) * sin(theta);
        float innerZ = z;

        // Add both vertices to create a thick frame
        glVertex3f(outerX, outerY, outerZ);
        glVertex3f(innerX, innerY, innerZ);
    }
    glEnd();

    // Draw the bowstring (slightly in front of the bow frame)
    float stringOffset = 0.01f;  // Small offset to avoid z-fighting
    glBegin(GL_LINES);
    glVertex3f(x + radius, y, z + stringOffset);  // Top of the bowstring
    glVertex3f(x - radius, y, z + stringOffset);  // Bottom of the bowstring
    glEnd();

    GLUquadric* quad = gluNewQuadric();  // Create a quadric object
    glPushMatrix();
    glTranslatef(x, y, z);              // Position the cylinder in the middle of the bow
    glRotatef(90.0f, 0.0f, 1.0f, 0.0f); // Rotate to align with the x-axis
    glColor3f(0.2f, 0.2f, 0.2f);        // Set the grip color (dark gray)
    gluCylinder(quad, thickness / 2.0f, thickness / 2.0f, thickness, 36, 1);  // Grip
    glPopMatrix();
    gluDeleteQuadric(quad);  // Clean up the quadric object

    glPopMatrix();
}

void Bow::update(float deltaTime) {
    if (isAnimating) {
        rotateAng += 90.0f * deltaTime;
    }
}


void Bow::startAnimation() {
    isAnimating = true;
}

void Bow::stopAnimation() {
    isAnimating = false;
    rotateAng = 0.0f;
}