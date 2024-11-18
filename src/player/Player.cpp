#include "Player.h"
#include "../Globals.h"
#include "../utils/vector3f/Vector3f.h"
#include "../scenemanager/scenes/GameOver/GameOver.h"
#include <cmath>
#include <GL/glut.h>

float bodyHeight = 0.5f;
float armLength = 0.6f;
float legLength = 0.7f;
float walkCycle = 0.0f;
float totalWidth = 0.20f;
float totalDepth = 0.1f;

Player::Player(float originalX, float originalY, float originalZ) {
    position = Vector3f(originalX, originalY, originalZ);
	direction = Vector3f(0.0f, 0.0f, -1.0f);
	animCycle = 0.0f;
	speed = 2.0f;
	isMoving = false;
    
}

void Player::setIsMoving(bool moving) {
	isMoving = moving;
}

void Player::draw() {
	glPushMatrix();
	glTranslatef(position.x, position.y, position.z);

	// Calculate the rotation angle to face the direction of movement
	if (direction.x == 1.0f) {
		glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
	}
	else if (direction.x == -1.0f) {
		glRotatef(-90.0f, 0.0f, 1.0f, 0.0f);
	}
	else if (direction.z == -1.0f) {
		glRotatef(180.0f, 0.0f, 1.0f, 0.0f);
	}
	else {
		glRotatef(0.0f, 0.0f, 1.0f, 0.0f);
	}
	// Head
	glColor3f(1.0f, 0.8f, 0.6f); // Skin color
	glPushMatrix();
	glTranslatef(0.0f, bodyHeight + 0.2f, 0.0f);
	glutSolidSphere(0.2f, 20, 20);

	// Draw face
	glColor3f(0.0f, 0.0f, 0.0f); // Black color for eyes and mouth
	glPushMatrix();
	glTranslatef(0.1f, 0.05f, 0.18f); // Right eye
	glutSolidSphere(0.02f, 10, 10);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.1f, 0.05f, 0.18f); // Left eye
	glutSolidSphere(0.02f, 10, 10);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0f, -0.05f, 0.18f); // Mouth
	glScalef(0.1f, 0.05f, 0.02f);
	glutSolidCube(1.0f);
	glPopMatrix();

	glPopMatrix();

	// Body
	glColor3f(0.0f, 2.0f, 1.0f); // Blue color for body
	glPushMatrix();
	glTranslatef(0.0f, bodyHeight / 2, 0.0f);
	glScalef(totalWidth, bodyHeight, totalDepth);
	glutSolidCube(1.0f);
	glPopMatrix();

	// Arms
	glColor3f(1.0f, 0.8f, 0.6f); // Skin color for arms
	glPushMatrix();
	glTranslatef(totalWidth / 4 + 0.1f, bodyHeight, 0.0f);
	glRotatef(sin(walkCycle * M_PI / 180.0f) * 45.0f, 1.0f, 0.0f, 0.0f);
	glTranslatef(0.0f, -armLength / 2, 0.0f);
	glScalef(0.1f, armLength, 0.1f);
	glutSolidCube(1.0f);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-(totalWidth / 4 + 0.1f), bodyHeight, 0.0f);
	glRotatef(-sin(walkCycle * M_PI / 180.0f) * 45.0f, 1.0f, 0.0f, 0.0f);
	glTranslatef(0.0f, -armLength / 2, 0.0f);
	glScalef(0.1f, armLength, 0.1f);
	glutSolidCube(1.0f);
	glPopMatrix();

	// Legs
	glColor3f(0.0f, 0.0f, 1.0f); // Blue color for legs
	glPushMatrix();
	glTranslatef(totalWidth / 4, 0.0f, 0.0f);
	glRotatef(-sin(walkCycle * M_PI / 180.0f) * 45.0f, 1.0f, 0.0f, 0.0f);
	glTranslatef(0.0f, -legLength / 2, 0.0f);
	glScalef(0.1f, legLength, 0.1f);
	glutSolidCube(1.0f);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-(totalWidth / 4), 0.0f, 0.0f);
	glRotatef(sin(walkCycle * M_PI / 180.0f) * 45.0f, 1.0f, 0.0f, 0.0f);
	glTranslatef(0.0f, -legLength / 2, 0.0f);
	glScalef(0.1f, legLength, 0.1f);
	glutSolidCube(1.0f);
	glPopMatrix();

	glPopMatrix();
}

void checkCollision() {
	// Check if player is colliding with any walls
	// If player is colliding with a wall, end the game
	// and display the game over screen
}

void Player::update(float deltaTime) {
	if (isMoving) {
		// Increment walk cycle for leg and arm swinging
		walkCycle += 5.0f;
		if (walkCycle > 360.0f) walkCycle -= 360.0f;

		Vector3f newPosition = position + direction * speed * deltaTime;

		// Define boundaries with a margin based on player size
		float margin = 0.5f; // Adjust this based on the player's size
		float minX = -floorSize + margin;
		float maxX = floorSize - margin;
		float minZ = -floorSize + margin;
		float maxZ = floorSize - margin;

		// Ensure the new position is within the boundaries
		if (newPosition.x >= minX && newPosition.x <= maxX &&
			newPosition.z >= minZ && newPosition.z <= maxZ) {
			position = newPosition; // Update the player's position
		}
		else {
			isMoving = false;
			audioManager.playFile("damage");
		}

		Vector3f flagPosition = Vector3f(0.0f, 0.0f, -5.0f);

		float distance = sqrt(pow(position.x - flagPosition.x, 2) +
			pow(position.y - flagPosition.y, 2) +
			pow(position.z - flagPosition.z, 2));
		if (distance <= 1.0f) {
			flagCollected = true;
			audioManager.playFile("coin");
			sceneManager.setActiveScene(new GameOver());
		}

	}
	else {
		// Reset walk cycle when player is not moving
		walkCycle = 0.0f;
	}
}


void Player::moveForward() {
	direction = Vector3f(0.0f, 0.0f, -1.0f);
	setIsMoving(true);
}

void Player::moveBackward() {
	direction = Vector3f(0.0f, 0.0f, 1.0f);
	setIsMoving(true);

}

void Player::moveLeft() {
	direction = Vector3f(-1.0f, 0.0f, 0.0f);
	setIsMoving(true);
}

void Player::moveRight() {
	direction = Vector3f(1.0f, 0.0f, 0.0f);
	setIsMoving(true);
}

void Player::rotateRight() {
	direction = direction + Vector3f(0.5f, 0.0f, 0.0f);
}

void Player::rotateLeft() {
	direction = direction + Vector3f(-0.5f, 0.0f, 0.0f);
}

void Player::isColliding() {
}