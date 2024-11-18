#include "ScoreBoard.h"
#include "../../Globals.h"
#include <vector>
#include <string>
#include <cstdlib>
#include <GL/glut.h>

ScoreBoard::ScoreBoard() {
    isAnimating = false;
    rotateAng = 0.0f;
}


void ScoreBoard::draw(float x, float y, float z) {
    glPushMatrix();
    glTranslatef(x, y, z); // Position the scoreboard

    glPushMatrix();
    glRotatef(rotateAng, 0.0f, 1.0f, 0.0f);
    // 1. Frame
    glPushMatrix();
    glColor3f(0.2f, 0.2f, 0.2f); // Dark grey color for the frame
    glScalef(4.0f, 2.0f, 0.2f);  // Scale to make a thin rectangle
    glutSolidCube(1.0f);         // Frame body
    glPopMatrix();

    // 2. Screen
    glPushMatrix();
    glColor3f(0.0f, 0.0f, 0.0f); // Black color for the screen
    glTranslatef(0.0f, 0.2f, 0.11f); // Slightly in front of the frame
    glScalef(3.5f, 1.5f, 0.01f);     // Thin flat rectangle
    glutSolidCube(1.0f);             // Screen
    glPopMatrix();

    // 3. Buttons
    float buttonYOffset = -0.7f;
    for (int i = 0; i < 3; ++i) {
        glPushMatrix();
        glColor3f(0.8f, 0.2f, 0.2f); // Red color for the buttons
        glTranslatef(-1.0f + (i * 1.0f), buttonYOffset, 0.11f); // Position buttons
        glScalef(0.3f, 0.3f, 0.1f);  // Small cube buttons
        glutSolidCube(1.0f);         // Button
        glPopMatrix();
    }
    glPopMatrix();

    // 4. Pole
    glPushMatrix();
    glColor3f(0.6f, 0.3f, 0.0f); // Brown for the wooden pole
    glTranslatef(0.0f, -2.0f, 0.0f); // Below the frame
    glScalef(0.1f, 4.0f, 0.1f);     // Tall, narrow rectangle
    glutSolidCube(1.0f);             // Pole
    glPopMatrix();

    // 5. Base
    glPushMatrix();
    glColor3f(0.2f, 0.2f, 0.2f); // Dark grey for the base
    glTranslatef(0.0f, -4.0f, 0.0f); // Below the pole
    glScalef(3.0f, 0.2f, 2.0f);     // Wide, flat rectangle
    glutSolidCube(1.0f);             // Base
    glPopMatrix();

    glPopMatrix();
}

void ScoreBoard::update(float deltaTime) {
    if (isAnimating) {
		rotateAng += 90.0f * deltaTime;
    }
}


void ScoreBoard::startAnimation() {
    isAnimating = true;
}

void ScoreBoard::stopAnimation() {
    isAnimating = false;
	rotateAng = 0.0f;
}