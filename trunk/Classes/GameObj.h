#ifndef __OBJ_PARENT_H_
#define __OBJ_PARENT_H_
#include "cocos2d.h"
#include <vector>
#include <string>
using namespace std;
using namespace cocos2d;
class GameObj :  public CCNode
{
protected:
	cocos2d::CCSprite* body;
public:
	GameObj();
	CCRect getBound();
	CCRect getBound(int);
	virtual void update(float ) = 0;
	~GameObj(){};
	void insert(char*,char*);
};

#endif