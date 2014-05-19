//---------------------------------------
//Name:    So Tuan Hoang
//Class:   Rock
//Project: Game Larva
//Purpose: Object rock make effect in game
//---------------------------------------

#include "GameScene.h"
#include "InputLayer.h"
#include "GameObjLayer.h"
#include "BackgroundLayer.h"

#define FIX_POS(_pos, _min, _max) \
	if (_pos < _min)        \
	_pos = _min;        \
else if (_pos > _max)   \
	_pos = _max;  

CCScene* GameScene::scene()
{
	//// 'scene' is an autorelease object
	CCScene *scene = CCScene::create();

	//// 'layer' is an autorelease object
	GameScene *layer = GameScene::create();

	//InputLayer *input = InputLayer::create();
	//BackgroundLayer *background  = BackgroundLayer::create();
	//GameObjLayer *gameObj = GameObjLayer::create();
	//input->getLayer(background,gameObj);
	//scene->addChild(background);
	//scene->addChild(gameObj);
	//scene->addChild(input);
	scene->addChild(layer);
	return scene;
}

// on "init" you need to initialize your instance
bool GameScene::init()
{

	if ( !CCLayer::init() )
	{
		return false;
	}

	CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
	CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();

	/////////////////////////////
	// 2. add a menu item with "X" image, which is clicked to quit the program
	//    you may modify it.

	// add a "close" icon to exit the progress. it's an autorelease object
	pCloseItem = CCMenuItemImage::create(
		"CloseNormal.png",
		"CloseSelected.png",
		this,
		menu_selector(GameScene::menuCloseCallback));

	pCloseItem->setPosition(ccp(origin.x + visibleSize.width - pCloseItem->getContentSize().width/2 ,
		origin.y + pCloseItem->getContentSize().height/2));

	// create menu, it's an autorelease object
	CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
	pMenu->setPosition(CCPointZero);
	this->addChild(pMenu, 1);

	/////////////////////////////
	// 3. add your codes below...

	// add a label shows "Hello World"
	// create and initialize a label

	CCLabelTTF* pLabel = CCLabelTTF::create("Hello World", "Arial", 24);

	// position the label on the center of the screen
	pLabel->setPosition(ccp(origin.x + visibleSize.width/2,
		origin.y + visibleSize.height - pLabel->getContentSize().height));

	// add the label as a child to this layer
	this->addChild(pLabel, 1);

	// add "HelloWorld" splash screen"
	CCSprite* pSprite = CCSprite::create("HelloWorld.png");

	// position the sprite on the center of the screen
	pSprite->setPosition(ccp(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
	this->setTouchEnabled(true);
	// add the sprite as a child to this layer
	this->addChild(pSprite, 0);

	return true;
	//////////////////////////////
	//// 1. super init first
	//if ( !CCLayer::init() )
	//{
	//	return false;
	//}

	//CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
	//CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();

	///////////////////////////////
	//// 2. add a menu item with "X" image, which is clicked to quit the program
	////    you may modify it.

	//// add a "close" icon to exit the progress. it's an autorelease object
	///*CCMenuItemImage **/pCloseItem = CCMenuItemImage::create(
	//	"CloseNormal.png",
	//	"CloseSelected.png",
	//	this,
	//	menu_selector(GameScene::menuCloseCallback));

	//pCloseItem->setPosition(ccp(origin.x + visibleSize.width - pCloseItem->getContentSize().width/2 ,
	//	origin.y + pCloseItem->getContentSize().height/2));
	//// create menu, it's an autorelease object
	//CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
	//pMenu->setPosition(CCPointZero);
	//this->addChild(pMenu, 1);

	//
	////CCDirector::sharedDirector() -> getTouchDispatcher() -> addStandardDelegate( this, 0 );
	//this->setTouchEnabled(true);
	//this->scheduleUpdate();

	//return true;
}

// a selector callback
void GameScene::menuCloseCallback(CCObject* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT) || (CC_TARGET_PLATFORM == CC_PLATFORM_WP8)
	CCMessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
#else
	CCDirector::sharedDirector()->end();
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
#endif
}

void GameScene::ccTouchesBegan(CCSet* ptouch, CCEvent* event)
{
	if(pCloseItem->isVisible() == true)
		pCloseItem->setVisible(false);
	else pCloseItem->setVisible(true);
}
