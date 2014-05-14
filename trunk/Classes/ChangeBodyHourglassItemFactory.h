#ifndef __CHANGE_BODY_HOURGLASS_ITEM_FACTORY__H__
#define __CHANGE_BODY_HOURGLASS_ITEM_FACTORY__H__

#include "ChangeBodyItemFactory.h"

class ChangeBodyHourglassItemFactory : public ChangeBodyItemFactory
{
public:
	static ChangeBodyItemFactory* getInstanceHourglassFactory();
	cocos2d::CCSprite* createBodyItem( ItemStateEnum state );
protected:
	ChangeBodyHourglassItemFactory();
private:
	static ChangeBodyHourglassItemFactory* _instance;
};

#endif // !__CHANGE_BODY_HOURGLASS_ITEM_FACTORY__H__

