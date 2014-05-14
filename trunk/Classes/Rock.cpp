//---------------------------------------
//Name:    So Tuan Hoang
//Class:   Rock
//Project: Game Larva
//Purpose: Object rock make effect in game
//---------------------------------------

#include "Rock.h"

Rock::Rock() : GameObj()
{
	CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();

	vx = 0;
	vy = 0;
	last_vx = 0;
	last_vy = 0;
	time_move = 0;
	a = 3;
	ax = 0;
	ay = 0;
	body = cocos2d::CCSprite::create("rock.png");
	body->setScaleX(visibleSize.width / body->getContentSize().width / 50);
	body->setScaleY(visibleSize.width / body->getContentSize().width / 50);
	this->addChild(body);
	screen = CCRect(0,0,CCDirector::sharedDirector()->getVisibleSize().width,CCDirector::sharedDirector()->getVisibleSize().height );
	scheduleUpdate();
}

float Rock::getVx()
{
	return this->vx;
}

void Rock::setVx(float _vx)
{
	this->vx = _vx;
}

float Rock::getVy()
{
	return this->vy;
}

void Rock::setVy(float _vy)
{
	this->vy = _vy;
}

float Rock::getLastVx()
{
	return this->last_vx;
}

void Rock::setLastVx(float _last_vx)
{
	this->last_vx = _last_vx;
}

float Rock::getLastVy()
{
	return this->last_vy;
}

void Rock::setLastVy(float _last_vy)
{
	this->last_vy = last_vy;
}

void Rock::update(float dt)
{
	CCPoint p = this->getPosition();
	p.x += vx * dt;
	p.y += vy * dt;
	
	if (vx == 0 && vy == 0)
	{
		//if (last_vx >= 0)
		//{
		//	p.x += last_vx * dt + ax * dt * dt;
		//	last_vx += ax * dt;
		//}
		//
		//if (last_vy >= 0)
		//{
		//	p.y += last_vy * dt + ay * dt * dt;
		//	last_vy += ay * dt;
		//}
		if (last_vx != 0 || last_vy != 0) {
			//move 5s
			p.x += last_vx * dt;
			p.y += last_vy + dt;
			time_move += dt;
			if (time_move >= 5)
			{
				last_vx = 0;
				last_vy = 0;
				time_move = 0;
			}
		}

	}else
	{
		time_move = 0;
	}

	if (p.x < this->getBound().size.width / 2)
	{
		p.x = this->getBound().size.width / 2;
	}

	if (p.y < this->getBound().size.height / 2)
	{
		p.y = this->getBound().size.height / 2;
	}

	if (p.x > screen.size.width - this->getBound().size.width / 2)
	{
		p.x = screen.size.width - this->getBound().size.width / 2;
	}

	if (p.y > screen.size.height - this->getBound().size.height / 2)
	{
		p.y = screen.size.height - this->getBound().size.height / 2;
	}

	this->setPosition( p );
}

Rock::~Rock()
{
	
}