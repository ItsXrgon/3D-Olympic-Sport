#pragma once
class ScoreBoard
{
private:
	bool isAnimating;
	float rotateAng;
public:
	ScoreBoard();
	void draw(float x, float y, float z);
	void update(float deltaTime);
	void startAnimation();
	void stopAnimation();
};

