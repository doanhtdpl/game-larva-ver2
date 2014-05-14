#include "ChangeBodyHourglassItemFactory.h"
#include "Utils.h"

ChangeBodyHourglassItemFactory* ChangeBodyHourglassItemFactory::_instance = NULL;

ChangeBodyItemFactory* ChangeBodyHourglassItemFactory::getInstanceHourglassFactory()
{
	if (_instance == NULL)
	{
		_instance = new ChangeBodyHourglassItemFactory();
	}

	return _instance;
}

ChangeBodyHourglassItemFactory::ChangeBodyHourglassItemFactory()
{

}

cocos2d::CCSprite* ChangeBodyHourglassItemFactory::createBodyItem( ItemStateEnum state )
{
	cocos2d::CCSprite* body;

	//switch (state)
	//{
	//case ELockState:
	//	break;
	//case EUnlockState:
	//	break;
	//case EReadyState:
	//	break;
	//case EMovementState:
	//	break;
	//case EUsedState:
	//	break;
	//default:
	//	break;
	//}

	return body;
}