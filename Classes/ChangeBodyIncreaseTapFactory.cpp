#include "ChangeBodyIncreaseTapFactory.h"
#include "Utils.h"

ChangeBodyIncreaseTapItemFactory* ChangeBodyIncreaseTapItemFactory::_instance = NULL;

ChangeBodyItemFactory* ChangeBodyIncreaseTapItemFactory::getInstanceIncreaseTapFactory()
{
	if (_instance == NULL)
	{
		_instance = new ChangeBodyIncreaseTapItemFactory();
	}

	return _instance;
}

ChangeBodyIncreaseTapItemFactory::ChangeBodyIncreaseTapItemFactory()
{

}

cocos2d::CCSprite* ChangeBodyIncreaseTapItemFactory::createBodyItem( ItemStateEnum state )
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