#pragma once
class Bow
{
private:
	bool isAnimating;
	float rotateAng;
public:
	Bow();
	void draw(float x, float y, float z);
	void update(float deltaTime);
	void startAnimation();
	void stopAnimation();
};
