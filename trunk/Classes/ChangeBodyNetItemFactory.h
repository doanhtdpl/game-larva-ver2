#ifndef __CHANGE_BODY_NET_ITEM_FACTORY__H__
#define __CHANGE_BODY_NET_ITEM_FACTORY__H__

#include "ChangeBodyItemFactory.h"

class ChangeBodyNetItemFactory : public ChangeBodyItemFactory
{
public:
	static ChangeBodyItemFactory* getInstanceNetFactory();
	cocos2d::CCSprite* createBodyItem( ItemStateEnum state );
protected:
	ChangeBodyNetItemFactory();
private:
	static ChangeBodyNetItemFactory* _instance;
};

#endif // !__CHANGE_BODY_NET_ITEM_FACTORY__H__

