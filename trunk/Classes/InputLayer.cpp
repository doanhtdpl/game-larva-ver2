#include "InputLayer.h"
#include "BackgroundLayer.h"
#include "GameObjLayer.h"

bool InputLayer::init()
{
//	CCDirector::sharedDirector()->getTouchDispatcher()->addStandardDelegate( this, 0 );
	//CCDirector::sharedDirector()->getTouchDispatcher()->addStandardDelegate(this, 0);
	/*this->setTouchEnabled( true );*/
	//CCDirector::sharedDirector() -> getTouchDispatcher() -> addStandardDelegate( this, 0 );
	
	this->scheduleUpdate();
	return true;
}

void InputLayer::registerWithTouchDispatcher()
{
	CCDirector::sharedDirector()->getTouchDispatcher()->addStandardDelegate( this, 0 );
}

void InputLayer::ccTouchesBegan(CCSet* ptouch, CCEvent* event)
{
	this->gameObjLayer->ccTouchesBegan(ptouch, event);
}

void InputLayer::ccTouchesEnded(CCSet *pTouches, CCEvent *pEvent)
{
	this->gameObjLayer->ccTouchesEnded(pTouches, pEvent);
}

void InputLayer::getLayer(BackgroundLayer* bg,GameObjLayer* go)
{
	this->gameObjLayer = go;
	this->BGLayer = bg;
}

void InputLayer::onEnter()
{
	CCLayer::onEnter();
	setAccelerometerEnabled(true);
	setTouchEnabled(true);
}

void InputLayer::onExit()
{
	CCLayer::onExit();
}

void InputLayer::didAccelerate(CCAcceleration* pAccelerationValue)
{
	this->BGLayer->didAccelerate(pAccelerationValue);
	this->gameObjLayer->didAccelerate(pAccelerationValue);
}
