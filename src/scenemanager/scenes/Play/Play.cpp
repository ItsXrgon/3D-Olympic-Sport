#include "Play.h"
#include "../../../player/Player.h"
#include "../../../Environment/Benches/Benches.h"
#include "../../../Environment/Bullseye/Bullseye.h"
#include "../../../Environment/ScoreBoard/ScoreBoard.h"
#include "../../../Environment/Arrow/Arrow.h"
#include "../../../Environment/Walls/Walls.h"
#include "../../../Environment/Ground/Ground.h"
#include "../../../Environment/Bow/Bow.h"
#include "../../../HUD/HUD.h"
#include "../../../Globals.h"
#include "../../../scenemanager/scenes/GameOver/GameOver.h"
#include "../../../camera/Camera.h"
#include <vector>
#include <string>
#include <cstdlib>
#include <GL/glut.h>

Player player = Player(0.0f, 0.6f, 0.0f);
Benches benches = Benches();
Bullseye bullseye1 = Bullseye();
Bullseye bullseye2 = Bullseye();
Bullseye bullseye3 = Bullseye();
Bullseye bullseye4 = Bullseye();
ScoreBoard scoreboard = ScoreBoard();
Arrow arrow1 = Arrow();
Arrow arrow2 = Arrow();
Arrow arrow3 = Arrow();
Arrow arrow4 = Arrow();
Walls walls = Walls();
Ground ground = Ground();
Bow bow = Bow();

Play::Play() : Scene() {
  
}

void Play::update(float deltaTime) {
    gameTime = glutGet(GLUT_ELAPSED_TIME) / 1000.0f - 16;
    gameTime += 16.0;
    speed += 0.001;
	player.update(deltaTime);
	benches.update(deltaTime);
	bullseye1.update(deltaTime);
    bullseye2.update(deltaTime);
    bullseye3.update(deltaTime);
    bullseye4.update(deltaTime);
    scoreboard.update(deltaTime);
    arrow1.update(deltaTime);
    arrow2.update(deltaTime);
    arrow3.update(deltaTime);
    arrow4.update(deltaTime);
	walls.update(deltaTime);
    bow.update(deltaTime);
	if (gameEndTime <= gameTime) {
		sceneManager.setActiveScene(new GameOver());
	}
}

void drawAnimatingFlag(float x, float y, float z) {
    if (flagCollected) {
        return;
    }
    const int NUM_SEGMENTS = 20;  // Number of segments for the flag
    const float WAVE_SPEED = 2.0f;  // Speed of the wave
    const float WAVE_AMPLITUDE = 0.2f;  // Amplitude of the wave
    const float FLAG_HEIGHT = 1.0f;  // Height of the flag
    const float FLAG_WIDTH = 1.5f;  // Width of the flag

    glPushMatrix();
    glTranslatef(x, y, z);  // Position the flag

    // Draw Flagpole
    glColor3f(0.6f, 0.3f, 0.0f);  // Brown for the flagpole
    glBegin(GL_QUADS);
    glVertex3f(-0.05f, 0.0f, 0.0f);  // Bottom-left
    glVertex3f(0.05f, 0.0f, 0.0f);   // Bottom-right
    glVertex3f(0.05f, 3.0f, 0.0f);   // Top-right
    glVertex3f(-0.05f, 3.0f, 0.0f);  // Top-left
    glEnd();

    // Draw Waving Flag
    glColor3f(1.0f, 0.0f, 0.0f);  // Red for the flag
    glBegin(GL_TRIANGLE_STRIP);
    for (int i = 0; i <= NUM_SEGMENTS; ++i) {
        float t = static_cast<float>(i) / NUM_SEGMENTS;  // Segment interpolation [0, 1]
        float x = t * FLAG_WIDTH;  // Horizontal position
        float wave = sin(WAVE_SPEED * deltaTime + t * 2.0f * 3.14159f) * WAVE_AMPLITUDE;  // Wave effect

        glVertex3f(x, 2.0f + FLAG_HEIGHT + wave, 0.0f);

        // Bottom vertex of the segment
        glVertex3f(x, 2.0f + wave, 0.0f);
    }
    glEnd();

    glPopMatrix();
}

void Play::onSceneStart() {
    gameTime = 0;
	camera.switchView(Camera::FRONT_VIEW);
    audioManager.playMusic("background-play");
}

void Play::draw() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    player.draw();

    ground.draw(floorSize);
    walls.draw(floorSize);
    scoreboard.draw(5.0f, 4.0f, -10.0f);
    benches.draw(-10.0f, 0.0f, 5.0f);
	bullseye1.draw(0.0f, 1.0f, -10.0f);
    bullseye2.draw(2.0f, 1.0f, -10.0f);
    bullseye3.draw(4.0f, 1.0f, -10.0f);
    bullseye4.draw(6.0f, 1.0f, -10.0f);
    arrow1.draw(-4.0f, 1.0f, 0.0f);
    arrow2.draw(-4.4f, 1.0f, 0.0f);
    arrow3.draw(-4.8f, 1.0f, 0.0f);
    arrow4.draw(-5.2f, 1.0f, 0.0f);
	bow.draw(-5.0f, 1.0f, 0.0f);
    drawHUD();
    drawAnimatingFlag(0.0f, 0.0f, -5.0f);


}

void Play::keyPress(unsigned char key, int x, int y) {
    switch (key) {
    case 'w':
        player.moveForward();
        break;
    case 's':
        player.moveBackward();
        break;
    case 'a':
        player.moveLeft();
        break;
    case 'd':
        player.moveRight();
        break;
    case 'q':
        player.rotateLeft();
        break;
    case 'e':
        player.rotateRight();
        break;
    case '1':
        camera.rotateLeft();
        break;
    case '2':
        camera.rotateUp();
        break;
    case '3':
        camera.rotateDown();
        break;
    case '4':
        camera.rotateRight();
        camera;
    case 'f':
        benches.startAnimation();
        bullseye1.startAnimation();
        bullseye2.startAnimation();
        bullseye3.startAnimation();
        bullseye4.startAnimation();
        scoreboard.startAnimation();
        arrow1.startAnimation();
        arrow2.startAnimation();
        arrow3.startAnimation();
        arrow4.startAnimation();
        bow.startAnimation();
		audioManager.stopMusic();
        audioManager.playMusic("background-win");
        break;
    case 'g':
        benches.stopAnimation();
        bullseye1.stopAnimation();
        bullseye2.stopAnimation();
        bullseye3.stopAnimation();
        bullseye4.stopAnimation();
        scoreboard.stopAnimation();
        arrow1.stopAnimation();
        arrow2.stopAnimation();
        arrow3.stopAnimation();
        arrow4.stopAnimation();
        bow.stopAnimation();
        audioManager.stopMusic();
        audioManager.playMusic("background-play");
        break;
    }
    glutPostRedisplay();
}

void Play::keyRelease(unsigned char key, int x, int y) {
    player.setIsMoving(false);
    glutPostRedisplay();
}

void Play::keySpecial(int key, int x, int y) {
    switch (key) {
    case GLUT_KEY_UP:
        camera.move(0.0f, 0.0f, -0.5f);
        break;
    case GLUT_KEY_DOWN:
        camera.move(0.0f, 0.0f, 0.5f);
        break;
    case GLUT_KEY_LEFT:
        camera.move(-0.5f, 0.0f, 0.0f);
        break;
    case GLUT_KEY_RIGHT:
        camera.move(0.5f, 0.0f, 0.0f);
        break;
    case GLUT_KEY_PAGE_UP:
        camera.move(0.0f, 0.5f, 0.0f);
        break;
    case GLUT_KEY_PAGE_DOWN:
        camera.move(0.0f, -0.5f, 0.0f);
        break;
    case GLUT_KEY_F1:
        camera.switchView(Camera::TOP_VIEW);
        break;
    case GLUT_KEY_F2:
        camera.switchView(Camera::SIDE_VIEW);
        break;
    case GLUT_KEY_F3:
        camera.switchView(Camera::FRONT_VIEW);
        break;
    }
}

void Play::keySpecialUp(int key, int x, int y) {

}

void Play::handleMouseClick(int button, int state, int x, int y) {

}