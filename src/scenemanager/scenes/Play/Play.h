#ifndef PLAY_H
#define PLAY_H

#include "../Scene.h"
#include "../../SceneManager.h"

class Play : public Scene {
public:
    Play();

    void onSceneStart() override;
    void update(float deltaTime) override;
    void draw() override;
    void keyPress(unsigned char key, int x, int y) override;
    void keyRelease(unsigned char key, int x, int y) override;
    void keySpecial(int key, int x, int y) override;
    void keySpecialUp(int key, int x, int y) override;
    void handleMouseClick(int button, int state, int x, int y) override;
};

#endif