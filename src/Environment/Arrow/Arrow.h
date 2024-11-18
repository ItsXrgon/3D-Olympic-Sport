#pragma once
class Arrow
{
private:
	bool isAnimating;
	float timeFactor;
public:
	Arrow();
	void draw(float x, float y, float z);
	void update(float deltaTime);
	void startAnimation();
	void stopAnimation();
};

