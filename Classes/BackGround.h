//---------------------------------------
//Name:    So Tuan Hoang
//Class:   BackGround
//Project: Game Larva
//Purpose: Contains rock and bla
//---------------------------------------

#ifndef __BACK_GROUND__
#define __BACK_GROUND__

#include "cocos2d.h"
#include "Rock.h"

using namespace cocos2d;

class BackGround : public CCLayer
{
public:
	BackGround();
	~BackGround();
	virtual bool init();
	void update( float deltaTime );
protected:
private:
	CCSprite* sprite;
	int n;//numbers of rock
	Rock** arrRock;
};
#endif // !__BACK_GROUND__


