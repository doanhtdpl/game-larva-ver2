#ifndef __ITEM_READY_STATE__
#define __ITEM_READY_STATE__

#include "ItemContainerState.h"

class ItemContainer;
class ReadyState : public ItemContainerState
{
public:
	void unlock(int level);
	void update(float dt);
	void OnTouches();
	void OnMove();
	void ChangeImageItem();
	ReadyState();
	ReadyState(ItemContainer* _itemContainer);
protected:
private:
	ItemContainer* itemContainer;
};

#endif // !__ITEM_READY_STATE__