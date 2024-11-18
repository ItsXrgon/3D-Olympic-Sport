#pragma once
class Walls
{
private:
	bool isAnimating;
	float timeFactor;
public:
	Walls();
	void draw(int floorSize);
	void update(float deltaTime);
	void startAnimation();
	void stopAnimation();
};

