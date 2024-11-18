#pragma once
class Benches
{
private:
	bool isAnimating;
public:
	Benches();
	void draw(float x, float y, float z);
	void update(float deltaTime);
	void startAnimation();
	void stopAnimation();
};

