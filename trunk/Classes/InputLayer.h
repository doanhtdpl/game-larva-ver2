#ifndef __INPUT_LAYER_H__
#define __INPUT_LAYER_H__

#include "cocos2d.h"
#include "FileUtil.h"

using namespace cocos2d;

class BackgroundLayer;
class GameObjLayer;

class InputLayer : public CCLayer
{
public:
	BackgroundLayer* BGLayer;
	GameObjLayer* gameObjLayer;

	// implement the "static node()" method manually
	CREATE_FUNC(InputLayer);

	bool init();
	virtual void ccTouchesBegan(CCSet* , CCEvent*);
	virtual void ccTouchesEnded(CCSet* , CCEvent*);
	void getLayer(BackgroundLayer*,GameObjLayer*);
	void registerWithTouchDispatcher();
	virtual void onEnter();
	virtual void onExit();
	virtual void didAccelerate(CCAcceleration* pAccelerationValue);
protected:
private:
	FileUtil* file;
};

#endif // !__INPUT_LAYER_H__

