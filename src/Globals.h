#include "scenemanager/SceneManager.h"
#include "audiomanager/AudioManager.h"
#include "camera/Camera.h"

#ifndef GLOBALS_H
#define GLOBALS_H

extern int windowWidth;
extern int windowHeight;
extern float speed;
extern float floorSize;
extern bool flagCollected;
extern float deltaTime;
extern float gameTime;
extern float gameEndTime;
extern SceneManager sceneManager;
extern AudioManager audioManager;
extern Camera camera;
extern float M_PI;

#endif
