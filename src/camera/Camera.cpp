#include "Camera.h"

Camera::Camera()
    : x(0.0f), y(0.5f), z(1.0f), pitch(0.0f), yaw(0.0f), currentView(FRONT_VIEW) {}

void Camera::setupCamera() {
    if (currentView == TWO_DIMENSIONAL) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glClearColor(1.0f, 1.0f, 1.0f, 0.0f);

        glPushMatrix();
        glLoadIdentity();
        glMatrixMode(GL_PROJECTION);
        glPushMatrix();
        glLoadIdentity();
        gluOrtho2D(0, 800, 0, 600);  // Set the 2D orthographic view
        glMatrixMode(GL_MODELVIEW);
    }
    else {
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluPerspective(60.0, 640.0 / 480.0, 0.1, 100.0);

        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
    }
}


void Camera::move(float dx, float dy, float dz) {
    x += dx;
    y += dy;
    z += dz;
}

void Camera::rotateLeft() {
	yaw -= 1.0f;
}

void Camera::rotateRight() {
	yaw += 1.0f;
}

void Camera::rotateUp() {
	pitch += 1.0f;
}

void Camera::rotateDown() {
	pitch -= 1.0f;
}

void Camera::switchView(View view) {
    currentView = view;
    switch (view) {
    case TOP_VIEW:
		x = 0.0f; y = 20.0f; z = 20.0f;
		pitch = 90.0f; yaw = 0.0f;
        break;
    case SIDE_VIEW:
        x = 20.0f; y = 5.0f; z = 0.0f;
        pitch = 0.0f; yaw = -90.0f;
        break;
    case FRONT_VIEW:
        x = 0.0f; y = 5.0f; z = 20.0f;
        pitch = 0.0f; yaw = 0.0f;
        break;
	case TWO_DIMENSIONAL:
		x = 0.0f; y = 0.0f; z = 0.0f;
		pitch = 0.0f; yaw = 0.0f;
		break;
    }
}

void Camera::apply() {
    glLoadIdentity();
    if (currentView != TWO_DIMENSIONAL) {
        glTranslatef(-x, -y, -z);
        glRotatef(pitch, 1.0f, 0.0f, 0.0f);
        glRotatef(yaw, 0.0f, 1.0f, 0.0f);
    }
}
