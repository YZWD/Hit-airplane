#pragma once
#include "cocos2d.h"
#include "Enemy.h"
#include "SimpleAudioEngine.h"
USING_NS_CC;

const int ENEMY1_MAXLIFE=1;
const int ENEMY2_MAXLIFE=2;
const int ENEMY3_MAXLIFE=5;

enum Level
{
	EASY,
	MIDDLE,
	HARD,
};

class EnemyLayer : public Layer
{
public:
	EnemyLayer(void);
	~EnemyLayer(void);

	CREATE_FUNC(EnemyLayer);
	virtual bool init();

	void addEnemy1(float dt);
	void enemy1MoveFinished(Node* pSender);
	void enemy1Blowup(Enemy* enemy1);
	void removeEnemy1(Node* pTarget);
	void removeAllEnemy1();

	void addEnemy2(float dt);
	void enemy2MoveFinished(Node* pSender);
	void enemy2Blowup(Enemy* enemy2);
	void removeEnemy2(Node* pTarget);
	void removeAllEnemy2();

	void addEnemy3(float dt);
	void enemy3MoveFinished(Node* pSender);
	void enemy3Blowup(Enemy* enemy3);
	void removeEnemy3(Node* pTarget);
	void removeAllEnemy3();
	void removeAllEnemy();

	__Array* m_pAllEnemy1;
	__Array* m_pAllEnemy2;
	__Array* m_pAllEnemy3;

private:
	SpriteFrame* enemy1SpriteFrame;
	SpriteFrame* enemy2SpriteFrame;
	SpriteFrame* enemy3SpriteFrame_1;
	SpriteFrame* enemy3SpriteFrame_2;


};
// by xiongkaiqi 
