#pragma once

#include <Framework.h>
#include "Object.h"
class Block:public Object {
public:
	const int blockWidth = 50;
	const int blockHeight = 50;
	bool visable = true;
	bool isOrange = false;
	bool destroy = false;
	Block(int xPosition, int yPosition, const char* path,int width,int height);
	bool getVisable();
	void setVisable(bool x);
	void DrawP(int xPosition);
	~Block();
};