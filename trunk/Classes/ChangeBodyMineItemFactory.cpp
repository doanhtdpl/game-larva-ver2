#include "ChangeBodyMineItemFactory.h"
#include "Utils.h"

ChangeBodyMineItemFactory* ChangeBodyMineItemFactory::_instance = NULL;

ChangeBodyItemFactory* ChangeBodyMineItemFactory::getInstanceMineFactory()
{
	if (_instance == NULL)
	{
		_instance = new ChangeBodyMineItemFactory();
	}

	return _instance;
}

ChangeBodyMineItemFactory::ChangeBodyMineItemFactory()
{

}

cocos2d::CCSprite* ChangeBodyMineItemFactory::createBodyItem( ItemStateEnum state )
{
	cocos2d::CCSprite* body;

	switch (state)
	{
	case ELockState:
		break;
	case EUnlockState:
		break;
	case EReadyState:
		break;
	case EMovementState:
		break;
	case EUsedState:
		break;
	default:
		break;
	}

	return body;
}