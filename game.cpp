
#include <iostream>
#include <Framework.h>
#include "AllBlocks.h"
#include "Platform.h"
#define SPEED 10
#define SWIDTH 800
#define SHEIGHT 600
using namespace std;
/* Test Framework realization */

class MyFramework : public Framework {

public:

	AllBlocks allBlocks;
	int movePlatform;
	int xMouse,yMouse;
	bool mouseClick = false;
	virtual void PreInit(int& width, int& height, bool& fullscreen)
	{
		width = SWIDTH;
		height = SHEIGHT;
		fullscreen = false;
	}

	virtual bool Init() {
		allBlocks.LoadBlocks(800, 600);
		return true;
	}

	virtual void Close() {

	}

	virtual bool Tick() {
		
		if (mouseClick == true &&allBlocks.ball->getYPosition()<=allBlocks.platform->getYPosition()&& allBlocks.hearts.size() > 0) {
			
			allBlocks.CollisionAbilityPlatform(allBlocks.platform, SWIDTH, SHEIGHT);
			allBlocks.RandomAndMoveAbility(allBlocks.ability, SWIDTH);
			allBlocks.platform->Move(movePlatform, SWIDTH);
			for (int i = 0; i < allBlocks.blocks.size(); i++)
			{
					allBlocks.ball->CollisionBallBlock(allBlocks.blocks[i]);
					if (allBlocks.blocks[i]->destroy == true) {
						allBlocks.DestroyBlockNextToOrnage(allBlocks.blocks[i]);
					}

			}
			allBlocks.ball->CollisionBallPlatform( allBlocks.platform);
			allBlocks.ball->MoveBall(SWIDTH, SHEIGHT);
		}
		else {
			if (allBlocks.hearts.size() > 0&&mouseClick==true) {
				allBlocks.hearts.pop_back();
				allBlocks.ball->RestartBall(SWIDTH, SHEIGHT);
				allBlocks.platform->RestartPlatform(SWIDTH, SHEIGHT);
				mouseClick = false;
			}

		}
		allBlocks.DrawBlocks();
		return false;
	}

	virtual void onMouseMove(int x, int y, int xrelative, int yrelative) {
		xMouse = x;
		yMouse = y;
	}

	virtual void onMouseButtonClick(FRMouseButton button, bool isReleased) {
		if (button==FRMouseButton::LEFT && isReleased==true&&mouseClick==false)
		{
			allBlocks.ball->Angle(xMouse, yMouse);
			mouseClick = true;
		}
	}

	virtual void onKeyPressed(FRKey k) {
		if (k == FRKey::LEFT) {
			movePlatform = -1;
		}
		else if (k == FRKey::RIGHT) {
			movePlatform = 1;
		}
	}

	virtual void onKeyReleased(FRKey k) {
		movePlatform = 0;
	}

	virtual const char* GetTitle() override
	{
		return "Arcanoid";
	}
};

int main(int argc, char* argv[])
{
	MyFramework test;
	int height;
	int width;
	
	bool fullscreen = false;
	test.PreInit(height, width, fullscreen);
	//drawSprite(createSprite(s) , 100, 100);

	return run(&test);
}
