#ifndef ___CHANGE_BODY_TRIDENT_ITEM_FACTORY__H__
#define ___CHANGE_BODY_TRIDENT_ITEM_FACTORY__H__

#include "ChangeBodyItemFactory.h"

class ChangeBodyTridentItemFactory : public ChangeBodyItemFactory
{
public:
	static ChangeBodyItemFactory* getInstanceTridentFactory();
	cocos2d::CCSprite* createBodyItem( ItemStateEnum state );
protected:
	ChangeBodyTridentItemFactory();
private:
	static ChangeBodyTridentItemFactory* _instance;
};

#endif // !___CHANGE_BODY_TRIDENT_ITEM_FACTORY__H__

