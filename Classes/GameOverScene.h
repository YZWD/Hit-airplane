#pragma once
#include "cocos2d.h"
#include "GameOverLayer.h"

USING_NS_CC;

class GameOverScene : public Scene
{
public:

	GameOverScene(void);
	
	~GameOverScene(void);

	virtual bool init();

	static GameOverScene* create(int passScore);

public:

	GameOverLayer* gameOverLayer;

	int score;
};
