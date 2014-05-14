#ifndef ___CHANGE_BODY_ITEM_FACTORY__H__
#define ___CHANGE_BODY_ITEM_FACTORY__H__

#include "cocos2d.h"
#include <string>
#include "Utils.h"

class ChangeBodyItemFactory
{
public:
	virtual cocos2d::CCSprite* createBodyItem( ItemStateEnum state ) = 0;
protected:
private:
};

#endif // !___CHANGE_BODY_ITEM_FACTORY__H__

