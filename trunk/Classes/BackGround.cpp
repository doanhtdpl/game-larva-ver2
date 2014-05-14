#include "BackGround.h"

BackGround::BackGround()
{
	sprite = CCSprite::create("backGround.png");
	sprite->setScale(0.5);
	this->addChild(sprite);
	int h = sprite->getContentSize().height;
	//n = 0;
	//arrRock = new Rock*[n];
	srand(0);
	n = rand() % 5 + 5;
	arrRock = new Rock*[n];
	for (int i = 0; i < n; i++)
	{
		arrRock[i] = new Rock();
		int pos_x = rand() % (int)( CCDirector::sharedDirector()->getVisibleSize().width - arrRock[i]->getBound().size.width ) 
			+ arrRock[i]->getBound().size.width / 2;
		int pos_y = rand() % (int)( CCDirector::sharedDirector()->getVisibleSize().height - arrRock[i]->getBound().size.height ) 
			+ arrRock[i]->getBound().size.height / 2;
		arrRock[i]->setPosition( CCPoint(pos_x, pos_y) );
		this->addChild( arrRock[i] );
	}

	this->setTouchEnabled( true );
	this->scheduleUpdate();
}

BackGround::~BackGround()
{
	if (arrRock != NULL)
	{
		delete arrRock;
		arrRock = NULL;
	}
}

bool BackGround::init()
{
	srand(0);
	n = rand() % 5 + 5;
	arrRock = new Rock*[n];
	for (int i = 0; i < n; i++)
	{
		arrRock[i] = new Rock();
		int pos_x = rand() % (int)( CCDirector::sharedDirector()->getVisibleSize().width - arrRock[i]->getBound().size.width ) 
					+ arrRock[i]->getBound().size.width / 2;
		int pos_y = rand() % (int)( CCDirector::sharedDirector()->getVisibleSize().height - arrRock[i]->getBound().size.height ) 
			+ arrRock[i]->getBound().size.height / 2;
		arrRock[i]->setPosition( CCPoint(pos_x, pos_y) );
		this->addChild( arrRock[i] );
	}

	this->setTouchEnabled( true );
	this->scheduleUpdate();

	return true;
}

void BackGround::update( float deltaTime )
{

}
