#ifndef __ITEM_CONTAINER___
#define __ITEM_CONTAINER___

#include "cocos2d.h"
#include "GameObj.h"
#include "ItemContainerInterface.h"

using namespace cocos2d;

class ItemContainer : public GameObj, IItemContainer
{
public:
	ItemContainer();
	~ItemContainer();
	virtual void unlock(int level);
	virtual void update(float dt);
	virtual void OnTouches();
	virtual void OnMove();
	virtual void ChangeBody( ItemStateEnum state );
	virtual void setState(ItemContainerState* state);
	virtual ItemContainerState* getState();

	virtual ItemContainerState* getLockState();
	virtual ItemContainerState* getUnlockState();
	virtual ItemContainerState* getReadyState();
	virtual ItemContainerState* getMovementState();
	virtual ItemContainerState* getUsedState();

	virtual void setCost(int _cost);
	virtual int  getCost();
	virtual void setLevelUnlock(int _level);
	virtual int  getLevelUnlock();
	virtual void setCount(int _count);
	virtual int  getCount();
	virtual void setDuringTime(float _dt);
	virtual float  getDuringTime();
protected:
private:
	int cost;
	int levelUnlock;
	float duringTime;
	int count;
	ItemContainerState* state;
};

#endif // !__ITEM_CONTAINER___
