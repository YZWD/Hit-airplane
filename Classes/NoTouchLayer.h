#pragma once
#include "cocos2d.h"
USING_NS_CC;

class NoTouchLayer : public Layer
{
public:
	virtual bool init();
	
	CREATE_FUNC(NoTouchLayer);
    
	virtual bool onTouchBegan (Touch *touch, Event *event);
	virtual void onTouchMoved (Touch *touch, Event *event);
	virtual void onTouchEnded (Touch *touch, Event *event);
};
