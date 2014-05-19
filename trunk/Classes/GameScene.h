//---------------------------------------
//Name:    So Tuan Hoang
//Class:   Rock
//Project: Game Larva
//Purpose: Object rock make effect in game
//---------------------------------------

#ifndef __GAME_SCENE_H_
#define __GAME_SCENE_H_

#include "cocos2d.h"
#include "Bug.h"
#include "FileUtil.h"
using namespace cocos2d;
class BackgroundLayer;
class GameObjLayer;
class InputLayer;

class GameScene : public CCLayer
{
public:
	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init();  

	// there's no 'id' in cpp, so we recommend returning the class instance pointer
	static cocos2d::CCScene* scene();

	// a selector callback
	void menuCloseCallback(CCObject* pSender);

	// implement the "static node()" method manually
	CREATE_FUNC(GameScene);

	void ccTouchesBegan(CCSet* , CCEvent*);
	/*void onEnter();
	void didAccelerate(CCAcceleration* pAccelerationValue);*/
	
protected:
private:
	/*static InputLayer* inputLayer;
	static GameObjLayer* gameObjLayer;*/
	CCMenuItemImage *pCloseItem;
	////CCSprite* backGround;
	//Rock** arrRock;
	//int n;
	//cocos2d::CCArray	*objs;
	//CCAcceleration* pAccValueOld;
	//float last_x;
	//float last_y;
	//float last_z;

	//char string[10];
	//char string1[10];
	//char string2[10];
	//char string3[10];

	//CCLabelTTF* pLabel;
	//CCLabelTTF* pLabel1;
	//CCLabelTTF* pLabel2;
	//CCLabelTTF* pLabel3;
	//CCLabelTTF* pLabel4;
	//CCLabelTTF* pLabel5;

	//float speedAcc;
	//bool flagAcc;
	//bool isShaking;
	//CCPoint posOldAcc;
	//CCPoint posCurAcc;
	//float d;
	//CCPoint vectorAccDelta;
	//float timeDuringAccUpdate;
	//BackGround* backGround;
};
#endif // !__GAME_SCENE_H_



