#pragma once
#include "HelloWorldScene.h"



class Apple : public Sprite 
{
public :
	CREATE_FUNC(Apple);
	bool init() override;
	void InitPos();
	void NewApplePop();

	int _x, _y;
	Sprite* body;
};
