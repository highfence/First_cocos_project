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
	playable->INIT_COMPLETE = 1;
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
	Director::getInstance()->getEventDispatcher()->addEventListenerWithFixedPriority(keylistener, 2);


	return;
}




void Snake::onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event) {
	
	switch (keyCode)
	{
		case EventKeyboard::KeyCode::KEY_RIGHT_ARROW :
			if (this->direction == LEFT) { break; }
			this->direction = RIGHT;
			break;

		case EventKeyboard::KeyCode::KEY_LEFT_ARROW :
			if (this->direction == RIGHT) { break; }
			this->direction = LEFT;
			break;

		case EventKeyboard::KeyCode::KEY_UP_ARROW :
			if (this->direction == DOWN) { break; }
			this->direction = UP;
			break;

		case EventKeyboard::KeyCode::KEY_DOWN_ARROW :
			if (this->direction == UP) { break; }
			this->direction = DOWN;
			break;
	}

	this->MoveSnake(0);
}

void Snake::MoveSnake(float dt) {

	if (this->INIT_COMPLETE == 0) {
		return;
	}

	int head_width, head_height;
	head_width = this->head->getPosition().x;
	head_height = this->head->getPosition().y;

	auto moveDown = MoveBy::create(0, Vec2(0, -BASIC_HEIGHT));
	auto moveUp = MoveBy::create(0, Vec2(0, BASIC_HEIGHT));
	auto moveLeft = MoveBy::create(0, Vec2(-BASIC_WIDTH, 0));
	auto moveRight = MoveBy::create(0, Vec2(BASIC_WIDTH, 0));


	switch (this->direction) {

		case RIGHT :
			this->head->runAction(moveRight);
			break;
		case LEFT :
			this->head->runAction(moveLeft);
			break;
		case UP :
			this->head->runAction(moveUp);
			break;
		case DOWN :
			this->head->runAction(moveDown);
			break;
	}

	
	for (int idx = ateFood - 1; idx != 0; --idx) {

		this->body[idx]->setPosition(Vec2(this->body[idx-1]->getPosition().x, this->body[idx-1]->getPosition().y));

	}

	this->body[0]->setPosition(Vec2(head_width, head_height));

	
}
