#include "snake.h"


using namespace cocos2d;

const int BASIC_WIDTH = 24;
const int BASIC_HEIGHT = 16;

auto winSize = Point(BASIC_WIDTH * 20, BASIC_HEIGHT * 20);

Snake* Snake::create() {

	Snake* playable = new Snake();

	playable->ateFood = INIT_FOOD;
	playable->direction = RIGHT;

	
	playable->SpriteSnake();
	playable->InitSetting();

	return playable;
}



void Snake::SpriteSnake() {

	this->head = Sprite::create("snake_head.png");
	
	for (int idx = 0; idx < ateFood; ++idx) {
		
		this->body[idx] = Sprite::create("snake_body.png");
	}

	this->body[ateFood] = NULL;

	return;
}

void Snake::InitSetting() {

	
	this->head->setPosition(Point(winSize.x * 0.4, winSize.y * 0.5));
	this->body[0]->setPosition(head->getPosition().x - BASIC_WIDTH, head->getPosition().y);

	for (int idx = 1; this->body[idx] != NULL; ++idx) {

		this->body[idx]->setPosition(this->body[idx - 1]->getPosition().x - BASIC_WIDTH, this->body[idx - 1]->getPosition().y);

	}
	
	auto keylistener = EventListenerKeyboard::create();
	keylistener->onKeyPressed = CC_CALLBACK_2(Snake::onKeyPressed, this);
	cocos2d::Node::_eventDispatcher->addEventListenerWithSceneGraphPriority(keylistener, this);
	return;
}




void Snake::onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event) {
	
	int head_width, head_height;

	head_width = this->head->getPosition().x;
	head_height = this->head->getPosition().y;


	switch (keyCode)
	{
		case EventKeyboard::KeyCode::KEY_KP_RIGHT :
			for (int idx = this->ateFood - 1; idx > 0; --idx) {
				this->body[idx]->setPosition(this->body[idx - 1]->getPosition().x, this->body[idx - 1]->getPosition().y);
			}

			this->body[0]->setPosition(this->head->getPosition().x, this->head->getPosition().y);
			this->head->setPosition(Point(head_width + BASIC_WIDTH, head_height));

			break;
	}
}