#pragma once

#include "cocos2d.h"

USING_NS_CC;

const int AIRPLANE=747;

class PlaneLayer : public Layer
{
public:

	PlaneLayer(void);
	
	~PlaneLayer(void);

	static PlaneLayer* create();

	virtual bool init();

	void MoveTo(Point location);

	void Blowup(int passScore);

	void RemovePlane();

public:

	static PlaneLayer* sharedPlane;

	bool isAlive;

	int score;
};
