#include "../utils/vector3f/Vector3f.h"

#pragma once
class Player {
private:
    Vector3f position;
    Vector3f direction;
    bool isMoving;
    float animCycle;
    float speed;

public:
    Player(float x, float y, float z);

    void moveForward();
    void moveBackward();
    void moveLeft();
    void moveRight();
    void rotateRight();
    void rotateLeft();
    void setIsMoving(bool moving);
    void isColliding();
    void update(float deltaTime);
    void draw();

};

