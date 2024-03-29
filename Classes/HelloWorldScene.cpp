#include "HelloWorldScene.h"

#include "BugFactory.h"
USING_NS_CC;

CCScene* HelloWorld::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    HelloWorld *layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
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
    CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
                                        "CloseNormal.png",
                                        "CloseSelected.png",
                                        this,
                                        menu_selector(HelloWorld::menuCloseCallback));
    
	pCloseItem->setPosition(ccp(origin.x + visibleSize.width - pCloseItem->getContentSize().width/2 ,
                                origin.y + pCloseItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
    pMenu->setPosition(CCPointZero);
  /*  this->addChild(pMenu, 1);
	file = new FileUtil();
    CCDictionary* mymap = file->ReadCSV("Bug.csv",BugFactory::getInstanceBF());
	for (int i = 0; i < mymap->count(); ++i)
	{
		stringstream ss;
		ss<<i + 1;
		Bug* bug = dynamic_cast<Bug*> (mymap->objectForKey(ss.str()));
		arrBug.push_back(bug);
	}*/
	srand( time(0) );
	for ( int i = 0 ; i < arrBug.size(); ++i)
	{
		int x = rand() % (int)( visibleSize.width );
		int y = rand() % (int)( visibleSize.height );
		if( x < arrBug.at(i)->getBound().size.width / 2)
			x += + arrBug.at(i)->getBound().size.width / 2;
		if(y < arrBug.at(i)->getBound().size.height / 2)
			y +=  + arrBug.at(i)->getBound().size.height / 2;
		arrBug.at(i)->setLocation(ccp(x,y));
		this->addChild(arrBug.at(i));
	}
	
	this->setTouchEnabled(true);
	this->scheduleUpdate();
	int a = 1;
    return true;
}

void HelloWorld::ccTouchesEnded(CCSet *pTouches, CCEvent *pEvent)
{
	CCTouch* touch = (cocos2d::CCTouch*)( pTouches->anyObject());
	CCPoint point = touch->getLocation();
	int i = rand() % 3;
	arrBug.at(i)->setLocation(point); 
}

void HelloWorld::update(float deltatime)
{
	srand( time(0) );
	for (int i = 0; i < arrBug.size(); ++i)
	{
		int curPower = rand() % 400 + 100;
		arrBug.at(i)->setCurPower(curPower);
	}
	
}
void HelloWorld::menuCloseCallback(CCObject* pSender)
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
