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
	ax = 0;
	ay = 0;
	F_x = 0;
	F_y = 0;

	body = cocos2d::CCSprite::create("rock.png");
	body->setScaleX(visibleSize.width / body->getContentSize().width / 15);
	body->setScaleY(visibleSize.width / body->getContentSize().width / 15);
	this->addChild(body);
	screen = CCRect(0,0,CCDirector::sharedDirector()->getVisibleSize().width,CCDirector::sharedDirector()->getVisibleSize().height );
	scheduleUpdate();
}

//float Rock::getVx()
//{
//	//return this->vx;
//
//}

void Rock::setVx(float _vx)
{
	//this->vx = _vx;
	//if (this->vx * F.x >= 0)
	//{
	//	F.x = this->vx;
	//}else
	//{
	//	this->F.x += _vx;
	//}

	this->F_x += _vx;

	//this->vector_a.x = this->F.x > 0 ? 1 : -1;
	//if (this->vx != 0)
	//{
	//	this->last_vx = F.x;
	//}else
	//{
	//	this->F.x += 0;
	//}
}

//float Rock::getVy()
//{
//	//return this->vy;
//}

void Rock::setVy(float _vy)
{
	//this->vy = _vy;
	//if (F.y * this->vy >= 0)//cung dau
	//{
	//	F.y = this->vy;
	//}else
	//{
	//	this->F.y += _vy;
	//}

	this->F_y += _vy;

	//vector_a.y = this->F.y > 0 ? 1 : -1;

	//if (this->vy != 0)
	//{
	//	this->last_vy = F.y;
	//}else {
	//	this->F.y = 0;
	//}
}

//float Rock::getLastVx()
//{
//	//return this->last_vx;
//}

void Rock::setLastVx(float _last_vx)
{
	//this->last_vx = _last_vx;
}

//float Rock::getLastVy()
//{
//	//return this->last_vy;
//}

void Rock::setLastVy(float _last_vy)
{
	//this->last_vy = _last_vy;
}

float	  Rock::get_ax()
{
	return this->ax;
}

void	  Rock::set_ax(float _ax)
{
	this->ax = _ax;
}

float	  Rock::get_ay()
{
	return this->ay;
}

void	  Rock::set_ay(float _ay)
{
	this->ay = _ay;
}

float	  Rock::getF_x()
{
	return this->F_x;
}

void	  Rock::setF_x(float _fx)
{
	this->F_x = _fx;
}

void      Rock::addF_x(float _fx)
{
	this->F_x += _fx;
}

void      Rock::addF_y(float _fy)
{
	this->F_y += _fy;
}

float	  Rock::getF_y()
{
	return this->F_y;
}

void	  Rock::setF_y(float _fy)
{
	this->F_y = _fy;
}

float	  Rock::getVector_ax()
{
	return this->vector_ax;
}

void	  Rock::setVector_ax(float _vector_ax)
{
	this->vector_ax = _vector_ax;
}

float	  Rock::getVector_ay()
{
	return this->vector_ay;
}

void	  Rock::setVector_ay(float _vector_ay)
{
	this->vector_ay = _vector_ay;
}

void Rock::update(float dt)
{
	CCPoint p = this->getPosition();
	//p.x += F_x * dt;
	//p.y += F.y * dt;

	vector_ax = F_x > 0 ? 1 : -1;
	vector_ay = F_y > 0 ? 1 : -1; 

	ax = F_x / m;
	ay = F_y / m;

	p.x += 100 * ax * dt * dt;
	p.y += 100 * ay * dt * dt;

	//F_x -= m * 2 * dt * vector_a.x;
	//F.y -= m * 2 * dt * vector_a.y;
	//if (F_x < m * 2 * dt * vector_a.x)
	//{
	//	F_x = 0;
	//}else
	//{
	//	F_x -= m * 2 * dt * vector_a.x;
	//}
	//if (F.y < m * 2 * dt * vector_a.y)
	//{
	//	F.y = 0;
	//}else
	//{
	//	F.y -= m * 2 * dt * vector_a.y;
	//}

	if (F_x > 0)
	{
		if (F_x > m * 2 * dt)
		{
			F_x -= m * 2 * dt;
		} 
		else
		{
			F_x = 0;
		}
	} 
	else
	{
		if (F_x < m * (-2) * dt)
		{
			F_x -= m * (-2) * dt;
		}else
		{
			F_x = 0;
		}
	}

	//F_y
	if (F_y > 0)
	{
		if (F_y > m * 2 * dt)
		{
			F_y -= m * 2 * dt;
		} 
		else
		{
			F_y = 0;
		}
	} 
	else
	{
		if (F_y < m * (-2) * dt)
		{
			F_y -= m * (-2) * dt;
		}else
		{
			F_y = 0;
		}
	}
	//if ( vx < 0 || vy < 0)
	//{
	// this->setVisible(false);
	//}else {
	// this->setVisible(true);
	//}

	//if (vx == 0 && vy == 0)
	//{
	//	//if (last_vx >= 0)
	//	//{
	//	//	p.x += last_vx * dt + ax * dt * dt;
	//	//	last_vx += ax * dt;
	//	//}
	//	//
	//	//if (last_vy >= 0)
	//	//{
	//	//	p.y += last_vy * dt + ay * dt * dt;
	//	//	last_vy += ay * dt;
	//	//}
	//	if (last_vx != 0 || last_vy != 0) {
	//		//move 5s
	//		p.x += last_vx * dt;
	//		p.y += last_vy * dt;
	//		time_move += dt;
	//		if (time_move >= 3)
	//		{
	//			last_vx = 0;
	//			last_vy = 0;
	//			time_move = 0;
	//		}
	//	}
	//}else
	//{
	//	time_move = 0;
	//}
	if (p.x < this->getBound().size.width / 2)
	{
		p.x = this->getBound().size.width / 2;
		F_x = - F_x / 2;
	}

	if (p.y < this->getBound().size.height / 2)
	{
		p.y = this->getBound().size.height / 2;
		F_y = -F_y / 2;
	}

	if (p.x > screen.size.width - this->getBound().size.width / 2)
	{
		p.x = screen.size.width - this->getBound().size.width / 2;
		F_x = -F_x / 2;
	}

	if (p.y > screen.size.height - this->getBound().size.height / 2)
	{
		p.y = screen.size.height - this->getBound().size.height / 2;
		F_y = -F_y / 2;
	}

	this->setPosition( p );
}

Rock::~Rock()
{

}