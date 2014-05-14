#ifndef __ITEM_USED_STATE__
#define __ITEM_USED_STATE__

#include "ItemContainerState.h"

class ItemContainer;
class UsedState : public ItemContainerState
{
public:
	void unlock(int level);
	void update(float dt);
	void OnTouches();
	void OnMove();
	void ChangeImageItem();
	UsedState();
	UsedState(ItemContainer* _itemContainer);
protected:
private:
	ItemContainer* itemContainer;
};

#endif // !__ITEM_USED_STATE__
