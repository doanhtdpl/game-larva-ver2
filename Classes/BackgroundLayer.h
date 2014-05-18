#ifndef __BACKGROUND_LAYER__
#define __BACKGROUND_LAYER__

#include "cocos2d.h"
#include <string>

using namespace cocos2d;

class Rock;

class BackgroundLayer : public CCLayer
{
public:
	// implement the "static node()" method manually
	CREATE_FUNC(BackgroundLayer);

	bool init();
	virtual void didAccelerate(CCAcceleration* pAccelerationValue);
	void update(float delta);
protected:
private:
	CCSprite* backGround;
	Rock** arrRock;
	int n;
	cocos2d::CCArray	*objs;

	float last_x;
	float last_y;
	float last_z;
	float speedAcc;
	bool flagAcc;
	//	bool isShaking;

	//	float d;
	char str[20];
	char strRock[20];
	float vectorAccDelta_x;
	float vectorAccDelta_y;
	float timeDuringAccUpdate;
	CCLabelTTF* pLabel;
	CCLabelTTF* pLabelRock;

	float FAcc_x;
	float FAcc_y;
};

#endif // !__BACKGROUND_LAYER__