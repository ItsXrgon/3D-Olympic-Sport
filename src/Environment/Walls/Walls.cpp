#include "Walls.h"
#include "../../Globals.h"
#include <vector>
#include <string>
#include <cstdlib>
#include <GL/glut.h>


Walls::Walls() {
    isAnimating = true;
	timeFactor = 0.0f;
}


void Walls::draw(int floorSize) {
    float red = (sin(timeFactor) + 1.0f) / 2.0f;   // Red component
    float green = (sin(timeFactor + 2.0f) + 1.0f) / 2.0f; // Green component
    float blue = (sin(timeFactor + 4.0f) + 1.0f) / 2.0f;  // Blue component

    glColor3f(red, green, blue);

    glDisable(GL_LIGHTING);

    const float wallHeight = 5.0f;
    const float wallPeakHeight = 7.4f;
    const float panelWidth = 5.0f; // Width of each fence panel
    const int numPanels = 8; // Number of panels for each wall

    for (int i = 0; i < numPanels; ++i) {
        float startX = -floorSize + i * panelWidth;
        float endX = startX + panelWidth;

        glBegin(GL_QUADS); // Panel body
        glVertex3f(startX, 0.0f, -floorSize); // Bottom-left
        glVertex3f(endX, 0.0f, -floorSize);   // Bottom-right
        glVertex3f(endX, wallHeight, -floorSize); // Top-right
        glVertex3f(startX, wallHeight, -floorSize); // Top-left
        glEnd();

        glBegin(GL_TRIANGLES); // Panel peak
        glVertex3f(startX, wallHeight, -floorSize); // Left corner
        glVertex3f(endX, wallHeight, -floorSize);   // Right corner
        glVertex3f((startX + endX) / 2.0f, wallPeakHeight, -floorSize); // Top
        glEnd();
    }

    for (int i = 0; i < numPanels; ++i) {
        float startZ = -floorSize + i * panelWidth;
        float endZ = startZ + panelWidth;

        glBegin(GL_QUADS); // Panel body
        glVertex3f(-floorSize, 0.0f, startZ); // Bottom-front
        glVertex3f(-floorSize, 0.0f, endZ);   // Bottom-back
        glVertex3f(-floorSize, wallHeight, endZ); // Top-back
        glVertex3f(-floorSize, wallHeight, startZ); // Top-front
        glEnd();

        glBegin(GL_TRIANGLES); // Panel peak
        glVertex3f(-floorSize, wallHeight, startZ); // Front corner
        glVertex3f(-floorSize, wallHeight, endZ);   // Back corner
        glVertex3f(-floorSize, wallPeakHeight, (startZ + endZ) / 2.0f); // Top
        glEnd();
    }

    for (int i = 0; i < numPanels; ++i) {
        float startZ = -floorSize + i * panelWidth;
        float endZ = startZ + panelWidth;

        glBegin(GL_QUADS); // Panel body
        glVertex3f(floorSize, 0.0f, startZ); // Bottom-front
        glVertex3f(floorSize, 0.0f, endZ);   // Bottom-back
        glVertex3f(floorSize, wallHeight, endZ); // Top-back
        glVertex3f(floorSize, wallHeight, startZ); // Top-front
        glEnd();

        glBegin(GL_TRIANGLES); // Panel peak
        glVertex3f(floorSize, wallHeight, startZ); // Front corner
        glVertex3f(floorSize, wallHeight, endZ);   // Back corner
        glVertex3f(floorSize, wallPeakHeight, (startZ + endZ) / 2.0f); // Top
        glEnd();
    }

    glEnable(GL_LIGHTING);
}

void Walls::update(float deltaTime) {
    if (isAnimating) {
        timeFactor = deltaTime * 100.0f;
    }
}


void Walls::startAnimation() {
    isAnimating = true;
}

void Walls::stopAnimation() {
    isAnimating = false;
    timeFactor = 0.0f;
}