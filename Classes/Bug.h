#ifndef __BUG_H_
#define __BUG_H_


#include "GameObj.h"
using namespace cocos2d;
class Bug : public GameObj
{
private:
	int id;
	float powerup;
	float timedisappear;
	int limitcatch;
	bool isEnemy;
	float curpower;
	float TDcurrent;
	bool isAlive;
	CCActionInterval* seq;
public:
	Bug();
	Bug( vector<string> );
	string getId();
	float getTDcurrent();
	void setTDcurrent(float );
	//string getId();
	void update(float );
	void setLocation(CCPoint);
	void FakeIn();
	void FakeOut();
	float getCurPower();
	void setCurPower(float);
	~Bug();
};

#endif