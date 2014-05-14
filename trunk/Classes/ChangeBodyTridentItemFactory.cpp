#include "ChangeBodyTridentItemFactory.h"
#include "Utils.h"

ChangeBodyTridentItemFactory* ChangeBodyTridentItemFactory::_instance = NULL;

ChangeBodyItemFactory* ChangeBodyTridentItemFactory::getInstanceTridentFactory()
{
	if (_instance == NULL)
	{
		_instance = new ChangeBodyTridentItemFactory();
	}

	return _instance;
}

ChangeBodyTridentItemFactory::ChangeBodyTridentItemFactory()
{

}

cocos2d::CCSprite* ChangeBodyTridentItemFactory::createBodyItem( ItemStateEnum state )
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