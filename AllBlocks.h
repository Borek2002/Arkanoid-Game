#pragma once
#include <vector>
#include "Platform.h"
#include "Ball.h"
#include <ctime>
#include "Block.h"
#include "Ability.h"
using namespace std;


class AllBlocks
{
public:
	const int blockWidth = 50;
	const int blockHeight = 25;
	const int platformHeight = 25;
	const int platformWidth = 100;
	const int gameOverSize = 360;
	const int space = 5;
	const int ballSize = 15;
	const int heartSize = 50;
	const int abilitySize = 50;
	const char* platformPath = "data/51-Breakout-Tiles.png";
	const char* ballPath = "data/63-Breakout-Tiles.png";
	const char* heartPath = "data/60-Breakout-Tiles.png";
	const char* negativePath = "data/57-Breakout-Tiles.png";
	const char* gameOverPath = "data/gameover.png";
	const char* youWinPath = "data/youwin.png";
	int blocksCount=0;
	vector<Block*> blocks;
	vector<Block*> hearts;
	Block* gameOver;
	Block* youWin;
	Platform* platform;
	Ability* ability;
	Ball* ball;
	AllBlocks();
	void RandomAndMoveAbility(Ability* ability,int sWidth);
	void CollisionAbilityPlatform(Platform* platform, int screenWidth, int screenHeight);
	void LoadBlocks(int screenWidth,int screenHeight);
	void DestroyBlockNextToOrnage(Block* block);
	void DrawBlocks();
	~AllBlocks();

};