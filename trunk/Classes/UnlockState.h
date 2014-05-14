#ifndef __ITEM__UNLOCK_STATE__
#define __ITEM__UNLOCK_STATE__

#include "ItemContainerState.h"

class ItemContainer;
class UnlockState : public ItemContainerState
{
public:
	void unlock(int level);
	void update(float dt);
	void OnTouches();
	void OnMove();
	void ChangeImageItem();
	UnlockState();
	UnlockState(ItemContainer* _itemContainer);
protected:
private:
	ItemContainer* itemContainer;
};

#endif // !__ITEM__UNLOCK_STATE__
