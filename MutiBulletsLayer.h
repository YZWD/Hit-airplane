#pragma once

#include "cocos2d.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

class MutiBulletsLayer : public Layer
{
public:
	MutiBulletsLayer(void);

	~MutiBulletsLayer(void);

	CREATE_FUNC(MutiBulletsLayer);

	virtual bool init();

	void AddMutiBullets(float dt);

	void mutiBulletsMoveFinished(Node* pSender);

	void RemoveMutiBullets(Sprite* mutiBullets);

	void StartShoot();

	void StopShoot();

public:

	__Array* m_pAllMutiBullets;

};
