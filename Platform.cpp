#include "Platform.h"

Platform::Platform(int xPosition, int yPosition, const char* path, int width, int height)
	:Object(xPosition, yPosition, path, width, height) {};

void Platform::Move(int move,int sWidth) {
	if (xPosition + move >= 0 && xPosition + move <= sWidth - platformWidth)
	{
		xPosition = xPosition + move;
	}
}
void Platform::RestartPlatform(int sWidth, int sHeight) {
	xPosition = sWidth/ 2 - platformWidth / 2;
	yPosition = sHeight - 100;
}
Platform::~Platform() {};