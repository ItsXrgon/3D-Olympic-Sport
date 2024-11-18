#include "../Globals.h"
#include "../player/Player.h"
#include "HUD.h"
#include <string>
#include <GL/glut.h>

void displayNumber(std::string text, float x, float y)
{
    glColor3f(1.0f, 0.0f, 0.0f);
    glRasterPos2f(x, y);
    for (int i = 0; i < text.size(); ++i)
    {
        char c = text[i];
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
    }
}

void drawHUD() {
    glPushMatrix();
    glLoadIdentity();
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    gluOrtho2D(0, 800, 0, 600);  // Set the 2D orthographic view
    glMatrixMode(GL_MODELVIEW);

    glColor3f(1.0f, 1.0f, 1.0f);  // White text color
    glRasterPos2i(10, 580);  // Position the text
    char timeText[50];
    sprintf_s(timeText, "time: %d", int(gameTime));
    for (int i = 0; timeText[i] != '\0'; i++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, timeText[i]);
    }

    glPopMatrix();
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
}