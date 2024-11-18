#include <vector>
#include <cstdlib>
#include <ctime>
#include "SceneManager/SceneManager.h"
#include "SceneManager/scenes/menu/Menu.h"
#include "SceneManager/scenes/play/Play.h"
#include "camera/Camera.h"
#include "Globals.h"
#include <GL/glut.h>

float lastTime = 0.0f;

void setupLights();
void keyPress(unsigned char key, int x, int y);
void keyRelease(unsigned char key, int x, int y);
void keySpecial(int key, int x, int y);
void keySpecialUp(int key, int x, int y);
void handleMouseClick(int button, int state, int x, int y);
void loadSoundFiles();

void loadSoundFiles() {
    audioManager.addFile("background-play", "sounds/background-play.wav");
    audioManager.addFile("background-win", "sounds/background-win.wav");
    audioManager.addFile("background-loss", "sounds/background-loss.wav");
    audioManager.addFile("coin", "sounds/coin.wav");
    audioManager.addFile("damage", "sounds/damage.wav");
}

void setupLights() {
    GLfloat ambient[] = { 0.7f, 0.7f, 0.7, 1.0f };
    GLfloat diffuse[] = { 0.6f, 0.6f, 0.6, 1.0f };
    GLfloat specular[] = { 1.0f, 1.0f, 1.0, 1.0f };
    GLfloat shininess[] = { 50 };
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, shininess);

    GLfloat lightIntensity[] = { 0.7f, 0.7f, 1, 1.0f };
    GLfloat lightPosition[] = { -7.0f, 6.0f, 3.0f, 0.0f };
    glLightfv(GL_LIGHT0, GL_POSITION, lightIntensity);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightIntensity);
}


void display() {
    setupLights();
    camera.setupCamera();
    camera.apply();

    sceneManager.draw();

    glFlush();
}

void update(int value) {
    static float lastTime = glutGet(GLUT_ELAPSED_TIME) * 0.001f; // Convert to seconds
    float currentTime = glutGet(GLUT_ELAPSED_TIME) * 0.001f;
    deltaTime = currentTime;
	sceneManager.update(deltaTime / 1000);
    glutPostRedisplay();
    glutTimerFunc(1000 / 60, update, 0);
}


int main(int argc, char** argv) {
    glutInit(&argc, argv);

    glutInitWindowSize(800, 600);
    glutInitWindowPosition(50, 50);

    glutCreateWindow("3D Olympic game");
    glutDisplayFunc(display);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glClearColor(1.0f, 1.0f, 1.0f, 0.0f);

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glShadeModel(GL_SMOOTH);

    loadSoundFiles();
	glutMouseFunc(handleMouseClick);
	glutSpecialFunc(keySpecial);
    glutKeyboardFunc(keyPress);
    glutKeyboardUpFunc(keyRelease);
    glutTimerFunc(1000 / 60, update, 0);

    camera.switchView(Camera::TWO_DIMENSIONAL);
    sceneManager.setActiveScene(new Menu());

    glutMainLoop();
}

void keySpecial(int key, int x, int y) {
	sceneManager.keySpecial(key, x, y);
}

void keyPress(unsigned char key, int x, int y) {
    sceneManager.keyPress(key, x, y);
}

void keyRelease(unsigned char key, int x, int y) {
    sceneManager.keyPress(key, x, y);
}

void keySpecialUp(int key, int x, int y) {
    sceneManager.keySpecialUp(key, x, y); 
}

void handleMouseClick(int button, int state, int x, int y) {
    y = windowHeight - y;

    sceneManager.handleMouseClick(button, state, x, y);
}