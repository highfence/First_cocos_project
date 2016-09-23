#include "pch.h"
#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"

#include "apple.h"
#include "snake.h"



Scene* HelloWorld::createScene()
{
    auto scene = Scene::create();
    auto layer = HelloWorld::create();

    scene->addChild(layer);

    return scene;
}

bool HelloWorld::init()
{
    if ( !Layer::init() )
    {
        return false;
    }

	
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

	player = Snake::create();
	this->addChild(player);

	food = Apple::create();
	this->addChild(food);
	
	RunActionTrigger = true;
	scheduleUpdate();

	return true;
}

void HelloWorld::CrashWithWall()
{
	if ((player->head->getPosition().x > winSize_x) || (player->head->getPosition().x < 0) || (player->head->getPosition().y > winSize_y) || (player->head->getPosition().y < 0))
	{
		RunActionTrigger = false;

		Label* endText = Label::createWithSystemFont("GAME END!", "Amatic SC", 50);
		endText->setPosition(winSize_x / 2, winSize_y * 2 / 3);
		this->addChild(endText);
	}



//	int score = player->ateFood - 4;
//	Label* scoreText = Label::createWithSystemFont("Your Score : %d", score, "Ariel", 35);
}

void HelloWorld::CrashWithApple()
{
	Rect headSpr = player->head->getBoundingBox();
	Point foodPoint = Vec2(food->_x * 24, food->_y * 16);

	if (headSpr.containsPoint(foodPoint)) {
		player->MakeLonger();
		food->NewApplePop();
	}
}

void HelloWorld::update(float dt)
{
	if (RunActionTrigger == true) {

		static float st = 0.0f;
		st += dt;
		float timer = (float)(2.0f / player->ateFood);
		if (st >= timer)
		{
			player->HeadRotate();
			player->MoveSnake();
			CrashWithWall();
			CrashWithApple();
			st = 0.f;
		}
	}

}
