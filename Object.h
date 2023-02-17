#pragma once

#include <Framework.h>

class Object {
protected:
	float xPosition;
	float yPosition;
	const char* path;
	Sprite* texture;
	int width;
	int height;
public:

	Object(float xPosition, float yPosition, const char* path, int width, int height);
	float getXPosition();
	float getYPosition();
	void setXPosition(float x);
	void setYPosition(float y);
	void Draw();
	void Destroy();
	~Object();
};