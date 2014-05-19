#ifndef __INTERFACE__ITEM_CONTAINER__
#define __INTERFACE__ITEM_CONTAINER__

//enum ItemStateEnum;
#include "Utils.h"

class ItemContainerState;

class IItemContainer
{
public:
	virtual void unlock(int level) = 0;
	virtual void update(float dt) = 0;
	virtual void OnTouches() = 0;
	virtual void OnMove() = 0;
	virtual void ChangeBody( ItemStateEnum stateEnum ) = 0;
	virtual void setState(ItemContainerState* state) = 0;
	virtual ItemContainerState* getState() = 0;

	virtual void setCost(int _cost) = 0;
	virtual int  getCost() = 0;
	virtual void setLevelUnlock(int _level) = 0;
	virtual int  getLevelUnlock() = 0;
	virtual void setCount(int _count) = 0;
	virtual int    getCount() = 0;
	virtual void   setDuringTime(float _dt) = 0;
	virtual float  getDuringTime() = 0;
};

#endif // !__INTERFACE__ITEM_CONTAINER__