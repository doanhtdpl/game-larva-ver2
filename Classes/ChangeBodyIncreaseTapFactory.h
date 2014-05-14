#ifndef __CHANGE_BODY_TAP_ITEM_FACTORY__H__
#define __CHANGE_BODY_TAP_ITEM_FACTORY__H__

#include "ChangeBodyItemFactory.h"

class ChangeBodyIncreaseTapItemFactory : public ChangeBodyItemFactory
{
public:
	static ChangeBodyItemFactory* getInstanceIncreaseTapFactory();
	cocos2d::CCSprite* createBodyItem( ItemStateEnum state );
protected:
	ChangeBodyIncreaseTapItemFactory();
private:
	static ChangeBodyIncreaseTapItemFactory* _instance;
};

#endif // !__CHANGE_BODY_TAP_ITEM_FACTORY__H__