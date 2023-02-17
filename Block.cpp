#include "Block.h"

Block::Block(int xPosition, int yPosition, const char* path, int width, int height)
	:Object(xPosition, yPosition, path, width, height) {};
void Block::setVisable(bool x) { this->visable = x; }
bool Block::getVisable() { return visable; }
void Block::DrawP(int xPosition) {
	drawSprite(texture, xPosition, yPosition);
}
Block::~Block() {};
