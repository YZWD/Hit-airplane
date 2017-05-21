#pragma once
// Hit-airplane
#include "cocos2d.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

class BulletLayer :	public Layer
{
public:

	BulletLayer(void);

	~BulletLayer(void);

	CREATE_FUNC(BulletLayer);

	virtual bool init();

	void AddBullet(float dt);

	void bulletMoveFinished(Node* pSender);

	void RemoveBullet(Sprite* bullet);

	void StartShoot(float delay = 0.0f);

	void StopShoot();
	
public:

	__Array* m_pAllBullet;


};
