#ifndef __CHANGE_BODY_MINE_ITEM_FACTORY__H__
#define __CHANGE_BODY_MINE_ITEM_FACTORY__H__

#include "ChangeBodyItemFactory.h"

class ChangeBodyMineItemFactory : public ChangeBodyItemFactory
{
public:
	static ChangeBodyItemFactory* getInstanceMineFactory();
	cocos2d::CCSprite* createBodyItem( ItemStateEnum state );
protected:
	ChangeBodyMineItemFactory();
private:
	static ChangeBodyMineItemFactory* _instance;
};

#endif // !__CHANGE_BODY_MINE_ITEM_FACTORY__H__

