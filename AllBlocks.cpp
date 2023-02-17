#include "AllBlocks.h"
#include "Block.h"
#include "Platform.h"
#include <iostream>
using namespace std;
AllBlocks::AllBlocks() {};


void AllBlocks::LoadBlocks(int screenWidth, int screenHeight) {
	int count = 0;
	srand(time(NULL));
	for (int i = 0; i < screenHeight / (blockHeight*3) ; i++)
	{
		for (int j = 0; j < screenWidth/(blockWidth); j++)
		{	
			int liczba = rand() % 2;
			if (liczba == 1) {
				const char* path = "data/09-Breakout-Tiles.png";
				blocks.insert(blocks.begin() + count, new Block(j * blockWidth, i * blockHeight, path, blockWidth, blockHeight));
				blocks[count]->isOrange = true;
			}
			else{
				const char* path = "data/01-Breakout-Tiles.png";
				blocks.insert(blocks.begin() + count, new Block(j * blockWidth, i * blockHeight, path, blockWidth, blockHeight));
			}
			count++;
		}
	}
	blocksCount = count;
	platform =new Platform(screenWidth/2-platformWidth/2, screenHeight-100, platformPath, platformWidth,platformHeight);
	ball =new Ball(screenWidth/2, screenHeight-100-ballSize, ballPath, ballSize, ballSize);
	ability = new Ability(100, -100, negativePath, abilitySize, abilitySize);
	gameOver = new Block(screenWidth/2-gameOverSize/2, screenWidth / 2 - gameOverSize/2, gameOverPath, gameOverSize, gameOverSize);
	youWin = new Block(screenWidth / 2 - gameOverSize / 2, screenWidth / 2 - gameOverSize / 2, youWinPath, gameOverSize, gameOverSize);
	hearts.insert(hearts.begin(),new Block(space, screenHeight - heartSize, heartPath, heartSize, heartSize));
};

void AllBlocks::DestroyBlockNextToOrnage(Block* block) {
	for (int i = 0; i < blocks.size(); i++)
	{
		
		if (block->getXPosition() - blockWidth == blocks[i]->getXPosition() && block->getYPosition() - blockHeight == blocks[i]->getYPosition()) {
			blocks[i]->setVisable(false);
		}
		
		if (block->getXPosition() + blockWidth == blocks[i]->getXPosition() && block->getYPosition() + blockHeight == blocks[i]->getYPosition()) {
			blocks[i]->setVisable(false);
		}
		
		if (block->getXPosition() - blockWidth == blocks[i]->getXPosition() && block->getYPosition() + blockHeight == blocks[i]->getYPosition())  {
			blocks[i]->setVisable(false);
		}
		
		if (block->getXPosition() + blockWidth == blocks[i]->getXPosition() && block->getYPosition() - blockHeight == blocks[i]->getYPosition()) {
			blocks[i]->setVisable(false);
		}
		if (block->getXPosition() - blockWidth == blocks[i]->getXPosition() && block->getYPosition()  == blocks[i]->getYPosition()) {
			blocks[i]->setVisable(false);
		}
		
		if (block->getXPosition() + blockWidth == blocks[i]->getXPosition() && block->getYPosition()  == blocks[i]->getYPosition()) {
			blocks[i]->setVisable(false);
		}

		if (block->getXPosition()  == blocks[i]->getXPosition() && block->getYPosition() + blockHeight == blocks[i]->getYPosition()) {
			blocks[i]->setVisable(false);
		}
	
		if (block->getXPosition()  == blocks[i]->getXPosition() && block->getYPosition() - blockHeight == blocks[i]->getYPosition()) {
			blocks[i]->setVisable(false);
		}

	}
	block->destroy = false;
}

void AllBlocks::RandomAndMoveAbility(Ability* ability,int sWidth) {
	srand(time(NULL));
	if (ability->getVisable() == false) {
		int positive = rand() % 2;
		int chance = rand() % 7;
		int x = rand() % sWidth - 1;
		if (chance==4) {
			if (positive==0) {
				ability->ChangePath(heartPath);
				ability->setVisable(true);
				ability->setIsPositive(true);
				ability->setXPosition(x);
			}
			else {
				ability->ChangePath(negativePath);
				ability->setVisable(true);
				ability->setIsPositive(false);
				ability->setXPosition(x);
			}
		}
	}
	else {
		ability->setYPosition(ability->getYPosition() + 1);
	}
}

void AllBlocks::CollisionAbilityPlatform(Platform* platform, int screenWidth, int screenHeight) {
	if (ability->getYPosition()+1   + abilitySize >= platform->getYPosition() && (ability->getXPosition() >= platform->getXPosition() && ability->getXPosition() <= (platform->getXPosition() + abilitySize + platform->platformWidth))) {
		if (ability->getIsPositive() == true) {
			hearts.insert(hearts.begin()+hearts.size(), hearts[0]);
		}
		else if(ability->getIsPositive()==false) {
			hearts.pop_back();
			cout << hearts.size() << endl;
		}
		ability->setVisable(false);
		ability->setYPosition(-100);
	
	}
	else if (ability->getYPosition() + 1 + abilitySize >= platform->getYPosition()+platformHeight) {
		ability->setVisable(false);
		ability->setYPosition(-100);
	}
}

void AllBlocks::DrawBlocks() {
	int countB=0;
	for (int i = 0; i < blocks.size(); i++)
	{
		
		if (blocks[i]->visable == true) {
			blocks[i]->Draw();
		}
		else {
			countB++;
		}
	}

	for (int i = 0; i < hearts.size(); i++)
	{
		
		hearts[i]->DrawP(i*abilitySize);
	}
	if (ability->getVisable()==true) {
		ability->Draw();
	}
	if (hearts.size()==0) {
		gameOver->Draw();
	}
	if (blocksCount == countB) {
		youWin->Draw();
	}
	platform->Draw();
	ball->Draw();
}

AllBlocks::~AllBlocks() {};