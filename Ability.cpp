#include "Ability.h"

Ability::Ability(int xPosition, int yPosition, const char* path, int width, int height)
	:Object(xPosition, yPosition, path, width, height) {};
void Ability::setVisable(bool x) { this->visable = x; }
bool Ability::getVisable() { return visable; }
void Ability::setIsPositive(bool x) { this->isPositive = x; }
bool Ability::getIsPositive() { return isPositive; }
void Ability::ChangePath(const char* path) {
	Destroy();
	texture = createSprite(path);
	setSpriteSize(texture, blockWidth, blockHeight);
}
Ability::~Ability() {};
