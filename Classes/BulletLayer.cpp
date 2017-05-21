#include "BulletLayer.h"
#include "PlaneLayer.h"
// Hit-airplane
BulletLayer::BulletLayer(void)
{


	m_pAllBullet = __Array::create();
	m_pAllBullet->retain();
}

BulletLayer::~BulletLayer(void)
{
	m_pAllBullet->release();
	m_pAllBullet = nullptr;
}

bool BulletLayer::init()
{
	bool bRet = false;
	do 
	{
		CC_BREAK_IF(!Layer::init());


		bRet = true;
	} while (0);
	return bRet;
}

void BulletLayer::StartShoot(float delay)
{
	this->schedule(schedule_selector(BulletLayer::AddBullet), 0.20f, kRepeatForever, delay);
}

void BulletLayer::StopShoot()
{
	this->unschedule(schedule_selector(BulletLayer::AddBullet));
}

void BulletLayer::AddBullet(float dt)
{
	CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("bullet.mp3");
	auto bullet = Sprite::createWithSpriteFrameName("bullet1.png");

	this->addChild(bullet);
	this->m_pAllBullet->addObject(bullet);

	Point planePosition = PlaneLayer::sharedPlane->getChildByTag(AIRPLANE)->getPosition();
	Point bulletPosition = Point(planePosition.x, planePosition.y+PlaneLayer::sharedPlane->getChildByTag(AIRPLANE)->getContentSize().height/2);
	bullet->setPosition(bulletPosition);
    
	float length = Director::getInstance()->getWinSize().height+bullet->getContentSize().height/2-bulletPosition.y;
	float velocity = 320/1;
	float realMoveDuration = length/velocity;

	auto actionMove = MoveTo::create(realMoveDuration, Point(bulletPosition.x,Director::getInstance()->getWinSize().height+bullet->getContentSize().height/2));
	auto actionDone = CallFuncN::create(CC_CALLBACK_1(BulletLayer::bulletMoveFinished, this));

	auto sequence = Sequence::create(actionMove, actionDone, nullptr);
	bullet->runAction(sequence);
}

void BulletLayer::bulletMoveFinished(Node* pSender)
{
	auto bullet = (Sprite*)pSender;
	this->removeChild(bullet, true);
    this->m_pAllBullet->removeObject(bullet);
}

void BulletLayer::RemoveBullet(Sprite* bullet)
{
	if (bullet != nullptr)
	{
        this->removeChild(bullet, true);
		this->m_pAllBullet->removeObject(bullet);
	}
}

