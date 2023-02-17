#pragma once

#include <Framework.h>
#include "Object.h"
class Ability :public Object {
public:
	const int blockWidth = 50;
	const int blockHeight = 50;
	bool visable = false;
	bool isPositive = false;
	Ability(int xPosition, int yPosition, const char* path, int width, int height);
	bool getVisable();
	void setVisable(bool x);
	bool getIsPositive();
	void setIsPositive(bool x);
	void ChangePath(const char* path);
	~Ability();
};
