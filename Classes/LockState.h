#ifndef __ITEM__LOCK__STATE__
#define __ITEM__LOCK__STATE__

#include "ItemContainerState.h"

class ItemContainer;

class LockState : public ItemContainerState
{
public:
	void unlock(int level);
	void update(float dt);
	void OnTouches();
	void OnMove();
	void ChangeImageItem();
	LockState();
	LockState(ItemContainer* _itemContainer);
protected:
private:
	ItemContainer* itemContainer;
};

#endif // !__ITEM__LOCK__STATE__
