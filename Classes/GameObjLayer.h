#ifndef __GAME_OBJECT_LAYER__
#define __GAME_OBJECT_LAYER__

#include "cocos2d.h"
#include "vector"

using namespace cocos2d;

class Bug;
class FileUtil;

class GameObjLayer : public CCLayer
{
public:
	// implement the "static node()" method manually
	CREATE_FUNC(GameObjLayer);
	bool init();
	void ccTouchesBegan(CCSet* , CCEvent*);
	void ccTouchesEnded(CCSet *pTouches, CCEvent *pEvent);
	virtual void didAccelerate(CCAcceleration* pAccelerationValue);
	void getBugs(std::vector<Bug*> arr);
	void update(float delta);
protected:
private:
	std::vector<Bug*> arrBug;
	FileUtil* file;

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

#endif // !__GAME_OBJECT_LAYER__
