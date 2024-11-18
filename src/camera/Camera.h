#ifndef CAMERA_H
#define CAMERA_H

#include <GL/glut.h>

class Camera {
public:
    enum View { TOP_VIEW, SIDE_VIEW, FRONT_VIEW, TWO_DIMENSIONAL };

    Camera();
	void setupCamera();
    void move(float dx, float dy, float dz);
    void rotateLeft();
	void rotateRight();
	void rotateUp();
	void rotateDown();
    void switchView(View view);
    void apply();

private:
    float x, y, z;
    float pitch, yaw;
    View currentView;
};

#endif
