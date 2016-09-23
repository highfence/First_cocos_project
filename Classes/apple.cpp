#include "pch.h"
#include "apple.h"

const int BASIC_WIDTH = 24;
const int BASIC_HEIGHT = 16;

bool Apple::init()
{
	body = Sprite::create("food_apple.png");
	addChild(body);
	InitPos();

	return true;
}

void Apple::InitPos()
{
	_x = rand() % 20;
	_y = rand() % 20;

	this->body->setPosition(Vec2(_x * BASIC_WIDTH, _y * BASIC_HEIGHT));
}

void Apple::NewApplePop()
{
	_x = rand() % 19 + 1;
	_y = rand() % 19 + 1;

	this->body->setPosition(Vec2(_x * BASIC_WIDTH, _y * BASIC_HEIGHT));
}
