#include "GameOver.h"
#include "../../../Globals.h"
#include <string>
#include <GL/glut.h>

GameOver::GameOver() : Scene() {}

void GameOver::onSceneStart() {
    audioManager.stopMusic();
    audioManager.playMusic("background-loss");
}

void GameOver::draw() {
    std::string message = flagCollected ? "You Win!" : "Game Over!";

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
    glLoadIdentity();
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    gluOrtho2D(0, 800, 0, 600);  // Set the 2D orthographic view
    glMatrixMode(GL_MODELVIEW);

    glColor3f(1.0f, 1.0f, 1.0f);  // White text color
    glRasterPos2i(windowWidth / 2, windowHeight / 2);  // Position the text
    char timeText[50];
    sprintf_s(timeText, "%s", message.c_str());
    for (int i = 0; timeText[i] != '\0'; i++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, timeText[i]);
    }

    glPopMatrix();
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);

    glutSwapBuffers();
}

void GameOver::update(float deltaTime) { }


void GameOver::keyPress(unsigned char key, int x, int y) { };
void GameOver::keyRelease(unsigned char key, int x, int y) { };

void GameOver::keySpecial(int key, int x, int y) { }


void GameOver::keySpecialUp(int key, int x, int y) { }


void GameOver::handleMouseClick(int button, int state, int x, int y) {}