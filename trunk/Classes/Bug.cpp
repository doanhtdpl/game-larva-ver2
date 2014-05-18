#include "Bug.h"
#include "FileUtil.h"
Bug::Bug()
{

}


Bug::Bug(vector<string> arr)
{
	id = atoi(arr[0].c_str());
	char *imageinfo = const_cast<char*>(arr[1].c_str());
	Image* image =  new Image(FileUtil::getFileUtilInstance()->getInfoFromBucket(imageinfo,FileUtil::getFileUtilInstance()->getImageDictionary()));
	body = cocos2d::CCSprite::create(image->getFileName());
	powerup = atoi(arr[2].c_str());
	timedisappear = atoi(arr[3].c_str());
	limitcatch = atoi(arr[4].c_str());
	isEnemy = atoi(arr[5].c_str());
	TDcurrent = 0;
	if (body)
	{
		this->addChild(body);
	}
	this->setScale( 0.0f );
	curpower = 0;
	isAlive = true;
	this->scheduleUpdate();
}


float Bug::getTDcurrent()
{
	return TDcurrent;
}

void Bug::setTDcurrent(float x)
{
	TDcurrent = x;
}

string Bug::getId()
{
	stringstream ss;
	ss<<id;
	return ss.str();
}

void Bug::update(float deltatime)
{
	if (curpower > 100)
	{
		if (curpower > powerup * 4)
		{
			curpower = powerup * 4;
		}
		float scale = curpower / powerup;

		this->setScale(scale);
	}else
	{
		this->setScale( 0 );
	}
}

float Bug::getCurPower()
{
	return curpower;
}

void Bug::setCurPower(float power)
{
	curpower = power;
}
void Bug::setLocation(CCPoint point)
{
	this->setPosition(point);
}
Bug::~Bug()
{

}