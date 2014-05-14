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
	// 'scene' is an autorelease object
	CCScene *scene = CCScene::create();

	// 'layer' is an autorelease object
	GameScene *layer = GameScene::create();

	InputLayer *input = InputLayer::create();
	BackgroundLayer *background  = BackgroundLayer::create();
	GameObjLayer *gameObj = GameObjLayer::create();
	//input->init();
	input->BGLayer = background;
	input->gameObjLayer = gameObj;
	// add layer as a child to scene
	scene->addChild(background);
	scene->addChild(gameObj);
	//scene->addChild(layer);
	scene->addChild(input);
	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool GameScene::init()
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
		menu_selector(GameScene::menuCloseCallback));

	pCloseItem->setPosition(ccp(origin.x + visibleSize.width - pCloseItem->getContentSize().width/2 ,
		origin.y + pCloseItem->getContentSize().height/2));
	// create menu, it's an autorelease object
	CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
	pMenu->setPosition(CCPointZero);
	this->addChild(pMenu, 1);

	//this->inputLayer = new InputLayer();
	//this->backgroundLayer = new BackgroundLayer();
	//this->gameObjLayer = new GameObjLayer();

	//this->inputLayer->init();
	//this->backgroundLayer->init();
	//this->gameObjLayer->init();

	//GameScene::scene()->addChild(this->inputLayer);
	//GameScene::scene()->addChild(this->gameObjLayer);
	//GameScene::scene()->addChild(this->backgroundLayer);

	////backGround = new BackGround();
	//////backGround->sprite->getContentSize().height;
	////this->addChild(backGround);

	//backGround = CCSprite::create("backGround.png");
	//backGround->setPosition( CCPoint( backGround->getContentSize().width / 2, backGround->getContentSize().height / 2 ) );
	//backGround->setScale(1.0);
	//this->addChild(backGround);
	////int h = sprite->getContentSize().height;
	////n = 0;
	////arrRock = new Rock*[n];

	////copy
	//file = new FileUtil();
	//CCDictionary* mymap = file->ReadCSV("Bug.csv",BugFactory::getInstanceBF());
	//for (int i = 0; i < mymap->count(); ++i)
	//{
	//	stringstream ss;
	//	ss<<i + 1;
	//	Bug* bug = dynamic_cast<Bug*> (mymap->objectForKey(ss.str()));
	//	arrBug.push_back(bug);
	//}
	//srand( time(0) );
	//for ( int i = 0 ; i < arrBug.size(); ++i)
	//{
	//	int x = rand() % (int)( visibleSize.width );
	//	int y = rand() % (int)( visibleSize.height );
	//	if( x < arrBug.at(i)->getBound().size.width / 2)
	//		x += + arrBug.at(i)->getBound().size.width / 2;
	//	if(y < arrBug.at(i)->getBound().size.height / 2)
	//		y +=  + arrBug.at(i)->getBound().size.height / 2;
	//	arrBug.at(i)->setLocation(ccp(x,y));
	//	this->addChild(arrBug.at(i));
	//}
	////copy of huy

	//srand( time(0) );
	//this->objs = new cocos2d::CCArray( 0 );
	//n = rand() % 50 + 50;
	//arrRock = new Rock*[n];
	//for (int i = 0; i < n; i++)
	//{
	//	arrRock[i] = new Rock();
	//	CCPoint pos = arrRock[i]->getPosition();
	//	pos.x = rand() % (int)( CCDirector::sharedDirector()->getVisibleSize().width - arrRock[i]->getBound().size.width ) 
	//		+ arrRock[i]->getBound().size.width / 2;
	//	pos.y = rand() % (int)( CCDirector::sharedDirector()->getVisibleSize().height - arrRock[i]->getBound().size.height ) 
	//		+ arrRock[i]->getBound().size.height / 2;
	//	arrRock[i]->setPosition( pos );
	//	this->addChild( arrRock[i] );
	//	objs->addObject( arrRock[i] );
	//}

	//speedAcc = 0;
	////std::string str = "Hello daica hoang";
	////std::strcpy(&str.c_str(), "aaa");
	//pLabel = CCLabelTTF::create("", "Arial", 25);

	////// position the label on the center of the screen
	//pLabel->setPosition( CCPoint(150, 50) );

	//pLabel1 = CCLabelTTF::create("", "Arial", 25);

	////// position the label on the center of the screen
	//pLabel1->setPosition( CCPoint(250, 50) );

	//pLabel2 = CCLabelTTF::create("", "Arial", 25);

	////// position the label on the center of the screen
	//pLabel2->setPosition( CCPoint(350, 50) );

	//pLabel3 = CCLabelTTF::create("", "Arial", 25);

	////// position the label on the center of the screen
	//pLabel3->setPosition( CCPoint(250, 100) );

	//pLabel4 = CCLabelTTF::create("", "Arial", 25);

	////// position the label on the center of the screen
	//pLabel4->setPosition( CCPoint(250, 150) );

	//pLabel5 = CCLabelTTF::create("", "Arial", 25);

	////// position the label on the center of the screen
	//pLabel5->setPosition( CCPoint(350, 200) );

	//// add the label as a child to this layer
	//this->addChild(pLabel, 1);
	//this->addChild(pLabel1, 1);
	//this->addChild(pLabel2, 1);
	//this->addChild(pLabel3, 1);
	//this->addChild(pLabel4, 1);
	//this->addChild(pLabel5, 1);

	//flagAcc = false;
	//timeDuringAccUpdate = 0;
	//d = 0;
	this->setTouchEnabled( true );
	this->scheduleUpdate();

	return true;
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
	
}

void GameScene::ccTouchesEnded(CCSet *pTouches, CCEvent *pEvent)
{

}

void GameScene::onEnter()
{

	//CCLabelTTF* pLabel = CCLabelTTF::create("Hello World", "Arial", 24);

	//// position the label on the center of the screen
	//pLabel->setPosition( CCPoint(50, 50) );

	//// add the label as a child to this layer
	//this->addChild(pLabel, 1);

	//CCLayer::onEnter();
	//setAccelerometerEnabled(true);
}

void GameScene::didAccelerate(CCAcceleration* pAccelerationValue)
{
//	CCDirector* pDir = CCDirector::sharedDirector();
//
//	CCSize rockSize = arrRock[1]->getContentSize();
//	CCPoint ptNow = arrRock[1]->getPosition();
//	CCPoint ptTemp = pDir->convertToUI(ptNow);
//
//	ptTemp.x += pAccelerationValue->x * 9.81f;
//	ptTemp.y -= pAccelerationValue->y * 9.81f;
//
//	CCPoint ptTemp1;
//	ptTemp1.x = pAccelerationValue->x;
//	ptTemp1.y  =pAccelerationValue->y;
//
//
//	sprintf(string2, "%.10g", pAccelerationValue->timestamp);
//	pLabel3->setString(string2);
//
//
//    CCPoint ptNext = pDir->convertToGL(ptTemp);
////	FIX_POS(ptNext.x, rockSize.width / 2.0, (CCDirector::getVisibleSize().width - rockSize.width / 2.0));
////	FIX_POS(ptNext.y, rockSize.height / 2.0, (CCDirector::getVisibleSize().height - rockSize.height / 2.0));
////	arrRock[1]->setPosition(ptNext);
//
//	//count distance
//	if (timeDuringAccUpdate > 0.1f)//not first time
//	{
//		if (flagAcc)
//		{
//			//posOldAcc = posCurAcc;
//			//posCurAcc = pDir->convertToGL(ptTemp);
//			//posCurAcc = ptTemp1;
//			speedAcc = ( ( pAccelerationValue->x + pAccelerationValue->y + pAccelerationValue->z) 
//								- (last_x + last_y + last_z) ) / timeDuringAccUpdate * 1000;
//			/*if (speedAcc < 0.0f)
//				speedAcc *= -1.0f*/;
//
//			if (speedAcc < -200)//is shaking
//			{
//				isShaking = true;
//				d += sqrt( pow( (pAccelerationValue->x - last_x), 2) + pow( (pAccelerationValue->y - last_y) ,2 ) + pow( (pAccelerationValue->z - last_z), 2) );
//
//				//update vector Acc Delta
//				vectorAccDelta.x = ( pAccelerationValue->x - last_x ) * 9.81f;
//				vectorAccDelta.y = ( pAccelerationValue->y - last_y ) * 9.81f;
//			}else if (speedAcc > 200)
//			{
//				isShaking = true;
//				d += sqrt( pow( (pAccelerationValue->x - last_x), 2) + pow( (pAccelerationValue->y - last_y) ,2 ) + pow( (pAccelerationValue->z - last_z), 2) );
//
//				//update vector Acc Delta
//				vectorAccDelta.x = ( pAccelerationValue->x - last_x ) * 9.81f;
//				vectorAccDelta.y = ( pAccelerationValue->y - last_y ) * 9.81f;
//			}
//			else
//			{
//				isShaking = false;
//				d -= 5.0f;
//				if (d < 0)
//				{
//					d = 0.0f;
//				}
//				vectorAccDelta = CCPoint(0 , 0);
//			}
//
//			last_x = pAccelerationValue->x;
//			last_y = pAccelerationValue->y;
//			last_z = pAccelerationValue->z;
//		}else
//		{
//			//posOldAcc = posCurAcc = ptTemp1; //pDir->convertToGL(ptTemp);
//			flagAcc = true;
//			
//			last_x = pAccelerationValue->x;
//			last_y = pAccelerationValue->y;
//			last_z = pAccelerationValue->z;
//
//			vectorAccDelta = CCPoint(0 , 0);
//		}
//		timeDuringAccUpdate = 0;
//	}
//
//	float vx = vectorAccDelta.x * 30;
//	float vy = vectorAccDelta.y * 30;
//	for (int i = 0; i < n; i++)
//	{
//		float randx = rand() % 5;
//		float randy = rand() % 5; 
//		arrRock[i]->setVx( vx * randx );
//		arrRock[i]->setVy( vy * randy );
//	}
//
//	sprintf(string, "%.2f", pAccelerationValue->x);
//	sprintf(string1, "%.2f", pAccelerationValue->y);
//	sprintf(string2, "%.2f", pAccelerationValue->z);
//
//	pLabel->setString(string);
//	pLabel1->setString(string1);
//	pLabel2->setString(string2);
//
//	sprintf(string, "%.2f", vectorAccDelta.x);
//	sprintf(string1, "%.1f", speedAcc);
//	sprintf(string2, "%.2f", d);
//	pLabel4->setString(string);
//	pLabel5->setString(string1);
//	pLabel3->setString(string2);
}

void GameScene::update( float deltaTime )
{
	//timeDuringAccUpdate += deltaTime;
	//for (int i = 0; i < n - 1; i++)
	//{
	//	for (int j = i + 1; j < n; j++)
	//	{
	//		if ( arrRock[i]->getBound().intersectsRect( arrRock[j]->getBound() ) )
	//		{
	//			arrRock[i]->setVx( -arrRock[i]->getVx() );
	//			arrRock[i]->setVy( -arrRock[i]->getVy() );
	//			arrRock[j]->setVx( -arrRock[i]->getVx() );
	//			arrRock[j]->setVy( -arrRock[i]->getVy() );
	//		}
	//	}
	//}

	//srand( time(0) );
	//for (int i = 0; i < arrBug.size(); ++i)
	//{
	//	//int curPower = rand() % 400 + 100;
	//	arrBug.at(i)->setCurPower( d * 30 );
	//}
}