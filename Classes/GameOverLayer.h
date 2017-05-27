
#pragma once

#include "cocos2d.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;
 
class GameOverLayer : public Layer
{
public:
	GameOverLayer(void);

	~GameOverLayer(void);

	virtual bool init();

	static GameOverLayer* create(int passScore);

	void menuBackCallback(Ref* pSender);

	void beginChangeHighestScore(Node* pNode);

	void showAD();

public:
	
	int score;

	static int highestHistoryScore;

	Label* highestScore;
};
