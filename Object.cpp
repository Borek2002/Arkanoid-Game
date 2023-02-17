#include "Object.h"



Object::Object(float xPosition,float yPosition, const char* path, int width, int height) :xPosition(xPosition), yPosition(yPosition), path(path), width(width), height(height) {
	texture = createSprite(path);
	setSpriteSize(texture, width, height);
};

float Object::getXPosition() { return xPosition; }
float Object::getYPosition() { return yPosition; }
void Object::setXPosition(float x) { this->xPosition = x; }
void Object::setYPosition(float y) { this->yPosition = y; }
void Object::Draw() {
	drawSprite(texture, xPosition, yPosition);
}
void Object::Destroy() {
	destroySprite(texture);
}
Object::~Object() {};