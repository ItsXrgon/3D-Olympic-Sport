#include "Benches.h"
#include "../../Globals.h"
#include <vector>
#include <string>
#include <cstdlib>
#include <GL/glut.h>

float yOffset = 0.0f;

Benches::Benches() {
	isAnimating = false;
}


void Benches::draw(float x, float y, float z) {
	float yPosition = y + yOffset;

    for (int i = 0; i < 5; ++i) {
        float xPosition = x + i * 5; // Calculate x position for each bench
        glPushMatrix();
        glPushMatrix();
        glTranslatef(xPosition, yPosition, z); // Position the bench

        // 1. Base supports
        glRotatef(180.0f, 0.0f, 1.0f, 0.0f);
        glPushMatrix();
        glColor3f(0.6f, 0.3f, 0.0f); // Brown for wooden base supports
        glTranslatef(-1.5f, 0.0f, 0.0f); // Left support
        glScalef(0.2f, 1.0f, 0.2f); // Scale for vertical wooden supports
        glutSolidCube(1.0f);
        glPopMatrix();

        glPushMatrix();
        glColor3f(0.6f, 0.3f, 0.0f); // Brown for wooden base supports
        glTranslatef(1.5f, 0.0f, 0.0f); // Right support
        glScalef(0.2f, 1.0f, 0.2f); // Scale for vertical wooden supports
        glutSolidCube(1.0f);
        glPopMatrix();

        // 2. Seat plank
        glPushMatrix();
        glColor3f(0.7f, 0.4f, 0.2f); // Light brown for the seat
        glTranslatef(0.0f, 0.6f, 0.0f); // Position above the base supports
        glScalef(3.5f, 0.2f, 0.8f); // Long, flat seat plank
        glutSolidCube(1.0f);
        glPopMatrix();

        // 3. Backrest
        glPushMatrix();
        glColor3f(0.6f, 0.3f, 0.0f); // Brown for the backrest
        glTranslatef(0.0f, 1.2f, -0.4f); // Positioned slightly back and above the seat
        glScalef(3.5f, 0.5f, 0.2f); // Thin, wide backrest
        glutSolidCube(1.0f);
        glPopMatrix();

        glPopMatrix();
        glPopMatrix();
    }
    glPushMatrix();
    glTranslatef(x, y, z);
}

void Benches::update(float deltaTime) {
    if (isAnimating) {
        yOffset = 0.1f * sin(glutGet(GLUT_ELAPSED_TIME) * 0.005f);
    }
}


void Benches::startAnimation() {
	isAnimating = true;
}

void Benches::stopAnimation() {
	isAnimating = false;
	yOffset = 0.0f;
}

