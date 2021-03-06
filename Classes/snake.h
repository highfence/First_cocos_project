

#include "HelloWorldScene.h"


#ifndef _SNAKE_H__
#define _SNAKE_H__

const int MAX_BODY = 384;

const int RIGHT = 1;
const int LEFT = -1;
const int UP = 2;
const int DOWN = -2;

class Snake : public Node {
public :
	CREATE_FUNC(Snake);
	bool init() override;
	enum INIT_SETTING {
		INIT_FOOD = 4,
		INIT_DIRECTION = RIGHT
	};


	int ateFood;
	int direction;
	int INIT_COMPLETE = 0; // 0 means INIT is not yet, 1 means INIT is done.
	cocos2d::Sprite* head;
	cocos2d::Sprite* body[MAX_BODY];

	void SpriteSnake();
	void InitSetting();
	void MoveSnake();
	void MoveEnd();
	void MakeLonger();
	void HeadRotate();

	void onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
};

#endif //_SNAKE_H__