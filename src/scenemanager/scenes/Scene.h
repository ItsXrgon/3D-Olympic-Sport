#ifndef SCENE_H
#define SCENE_H


class Scene {
public:
    Scene() {};
    ~Scene() = default;
    virtual void onSceneStart() = 0;
    virtual void draw() = 0;
    virtual void update(float deltaTime) = 0;
    virtual void handleMouseClick(int button, int state, int x, int y) = 0;
    virtual void keyPress(unsigned char key, int x, int y) = 0;
    virtual void keyRelease(unsigned char key, int x, int y) = 0;
    virtual void keySpecial(int key, int x, int y) = 0;
    virtual void keySpecialUp(int key, int x, int y) = 0;
};

#endif
