#pragma once




class Snake;
class Apple;

const int winSize_x = 480;
const int winSize_y = 320;

class HelloWorld : public Layer
{
public:
    static Scene* createScene();

    virtual bool init();

	void CrashWithWall();
	void CrashWithApple();
	
	void update(float dt);

    CREATE_FUNC(HelloWorld);
	
	
	Snake* player;
	Apple* food;

	bool RunActionTrigger;
private :

};

