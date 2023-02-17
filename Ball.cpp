#include "Ball.h"
#include <cmath> 
#include <iostream>

using namespace std;
Ball::Ball(float xPosition, float yPosition, const char* path, int width, int height)
	:Object(xPosition, yPosition, path, width, height) {};

void Ball::Angle(int xMouse, int yMouse) {
	angle = atan2( yPosition-yMouse,  xPosition-xMouse);
}
void Ball::ChangeBallSpeed(bool add) {
	if (add==true&&currentSpeed<=3*speed )
	{
		currentSpeed += 0.1*speed;
	}
	else if( add==false&&currentSpeed>=0.4*speed) {
		currentSpeed -= 0.1*speed;
	}
}
void Ball::MoveBall(int sWidth, int sHeight) {

	xMove = currentSpeed * cos(angle);
	yMove = currentSpeed * sin(angle);
	float angleDegree = angle*180/3.14;
	if (xPosition-xMove<=0 ) {//left side

		angle = 3.14-angle ;
		ChangeBallSpeed(true);
	}
	if (xPosition - xMove+ballSize >= sWidth) {//right side
		float angle2 = 3.14 - angle;
		angle = angle2;
		ChangeBallSpeed(true);
	}
	if (yPosition - yMove <= 0) {//top side

		float angle2 = 0 - angle;
		angle = angle2;
		ChangeBallSpeed(true);
	}

	xPosition -= xMove;
	yPosition -= yMove;
	
	
};

void Ball::CollisionBallBlock(Block* block) {
	if (block->getYPosition() + block->blockHeight >= yPosition-yMove  && (xPosition + ballSize-xMove >= block->getXPosition() && xPosition -xMove <= block->blockWidth + block->getXPosition())&& (yPosition + ballSize - yMove >= block->getYPosition() && yPosition - yMove <= block->getYPosition() + block->blockHeight) &&block->getVisable()==true) {
		float angle2 = 0 - angle;
		angle = angle2;
		block->setVisable(false);
		ChangeBallSpeed(false);
		if (block->isOrange==true)
		{
			block->destroy = true;
		}
	}
	else if (block->getXPosition() <= xPosition  +ballSize-xMove&& (xPosition + ballSize -xMove >= block->getXPosition() && xPosition -xMove <= block->blockWidth + block->getXPosition()) && (yPosition + ballSize - yMove >= block->getYPosition() && yPosition - yMove <= block->getYPosition() + block->blockHeight) && block->getVisable() == true) {
		angle = 3.14 - angle;
		block->setVisable(false);
		ChangeBallSpeed(false);
		if (block->isOrange == true)
		{
			block->destroy = true;
		}
	}
	else if (block->getXPosition() + block->blockWidth-xMove >= xPosition && (xPosition + ballSize -xMove >= block->getXPosition() && xPosition -xMove <= block->blockWidth + block->getXPosition()) && (yPosition + ballSize - yMove >= block->getYPosition() && yPosition - yMove <= block->getYPosition() + block->blockHeight) && block->getVisable() == true) {
		float angle2 = 3.14 - angle;
		angle = angle2;
		block->setVisable(false);
		ChangeBallSpeed(false);
		if (block->isOrange == true)
		{
			block->destroy = true;
		}
	}
	else if (block->getYPosition() <= yPosition+ballSize-yMove && (xPosition + ballSize -xMove >= block->getXPosition() && xPosition -xMove <= block->blockWidth + block->getXPosition()) && (yPosition + ballSize - yMove >= block->getYPosition() && yPosition - yMove <= block->getYPosition() + block->blockHeight) && block->getVisable() == true) {
		angle = -angle;
		block->setVisable(false);
		ChangeBallSpeed(false);
		if (block->isOrange == true)
		{
			block->destroy = true;
		}
	}
};


void Ball::CollisionBallPlatform(Platform* platform) {
	if (yPosition -yMove+ballSize>= platform->getYPosition() && (xPosition >= platform->getXPosition() && xPosition <= (platform->getXPosition() +ballSize+ platform->platformWidth))) {
		angle = -angle;
		ChangeBallSpeed(true);
	}

}
void Ball::RestartBall(int sWidth, int sHeight) {
	xPosition = sWidth / 2;
	yPosition = sHeight - 100 - ballSize;
	angle = 0;
	currentSpeed = speed;
}
Ball::~Ball() {};
