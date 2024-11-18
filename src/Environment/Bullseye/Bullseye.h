#pragma once
class Bullseye
{
private:
	bool isAnimating;
public:
	Bullseye();
	void draw(float x, float y, float z);
	void update(float deltaTime);
	void startAnimation();
	void stopAnimation();
};

