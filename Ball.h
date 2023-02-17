#pragma once
#include	<Framework.h>
#include "Object.h"
#include "Platform.h"
#include "Block.h"
#include <cmath> 

class Ball:public Object
{
public:
	float angle;

	const float speed = 1.0;
	float currentSpeed = 1.0;
	float xMove, yMove;
	const int ballSize = 15;
	const char* ballPath = "data/63-Breakout-Tiles.png";
	Ball(float xPosition,float yPosition, const char* path, int width, int height);
	void Angle(int xMouse, int yMouse);
	void MoveBall(int sWidth, int sHeight);
	void CollisionBallPlatform(Platform* platform);
	void CollisionBallBlock(Block* block);
	void ChangeBallSpeed(bool add);
	void RestartBall(int sWidth, int sHeight);
	~Ball();

};