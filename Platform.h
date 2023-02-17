#pragma once
#include <Framework.h>
#include "Object.h"

class Platform :public Object {

public:
	const int platformWidth = 100;
	const int platformHeight = 25;
	const char* platformPath = "data/51-Breakout-Tiles.png";
	Platform(int xPosition, int yPosition, const char* path, int width, int height);
	void Move(int move,int sWidth);
	void RestartPlatform(int sWidth, int sHeight);
	~Platform();


};