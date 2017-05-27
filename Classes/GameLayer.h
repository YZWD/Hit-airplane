#pragma once
#include "cocos2d.h"
#include "SimpleAudioEngine.h"
#include "PlaneLayer.h"
#include "BulletLayer.h"
#include "MutiBulletsLayer.h"
#include "ControlLayer.h"
#include "UFOLayer.h"
#include "EnemyLayer.h"

USING_NS_CC;

const int ENEMY1_SCORE = 1000;
const int ENEMY2_SCORE = 6000;
const int ENEMY3_SCORE = 30000;

const int MAX_BIGBOOM_COUNT = 100000;
const int TAG_BIGBOOM_MENUITEM = 1;
const int TAG_BIGBOOMCOUNT_LABEL = 2;
 
class GameLayer : public Layer
{
public:

	GameLayer(void);

	~GameLayer(void);

	CREATE_FUNC(GameLayer);

	virtual bool init();

	void backgroundMove(float dt);

	bool onTouchBegan(Touch* touch, Event  *event);

	void onTouchMoved(Touch* touch, Event  *event);

	void onTouchEnded(Touch* touch, Event  *event);

	void update(float dt);

	void menuBigBoomCallback(Ref* pSender);

	void updateBigBoomItem(int bigBoomCount);

	static Level getCurLevel();

private:
	Sprite* background1;
	Sprite* background2;

	PlaneLayer* planeLayer;
	BulletLayer* bulletLayer;
	MutiBulletsLayer* mutiBulletsLayer;
	ControlLayer* controlLayer;
	UFOLayer* ufoLayer;
	EnemyLayer* enemyLayer;

	Menu* menuBigBoom;
	Label* bigBoomCountItem;

	int score;
	int bigBoomCount;
	static Level level;
};
