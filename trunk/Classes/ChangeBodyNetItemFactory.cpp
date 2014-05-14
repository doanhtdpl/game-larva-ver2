#include "ChangeBodyNetItemFactory.h"
#include "Utils.h"

ChangeBodyNetItemFactory* ChangeBodyNetItemFactory::_instance = NULL;

ChangeBodyItemFactory* ChangeBodyNetItemFactory::getInstanceNetFactory()
{
	if (_instance == NULL)
	{
		_instance = new ChangeBodyNetItemFactory();
	}

	return _instance;
}

ChangeBodyNetItemFactory::ChangeBodyNetItemFactory()
{

}

cocos2d::CCSprite* ChangeBodyNetItemFactory::createBodyItem( ItemStateEnum state )
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