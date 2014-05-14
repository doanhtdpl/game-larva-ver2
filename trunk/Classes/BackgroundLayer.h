#ifndef __BACKGROUND_LAYER__
#define __BACKGROUND_LAYER__

#include "cocos2d.h"

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
	bool isShaking;
	CCPoint posOldAcc;
	CCPoint posCurAcc;
	float d;
	CCPoint vectorAccDelta;
	float timeDuringAccUpdate;
};

#endif // !__BACKGROUND_LAYER__