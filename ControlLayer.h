#pragma once

#include "cocos2d.h"
#include "SimpleAudioEngine.h"

#include "NoTouchLayer.h"

USING_NS_CC;

const int MAX_SCORE=1000000000;

class ControlLayer : public Layer
{
public:

	ControlLayer(void);

	~ControlLayer(void);

	virtual bool init();

	CREATE_FUNC(ControlLayer);

	void menuPauseCallback(Ref* pSender);

	void updateScore(int score);

public:

	Label* scoreItem;

	MenuItemSprite* pPauseItem;

	NoTouchLayer* noTouchLayer;
};
// by xiongkaiqi 
