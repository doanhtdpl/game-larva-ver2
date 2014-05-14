#ifndef __ITEM__MOVEMENT_STATE__
#define __ITEM__MOVEMENT_STATE__

#include "ItemContainerState.h"

class ItemContainer;
class MovementState : public ItemContainerState
{
public:
	void unlock(int level);
	void update(float dt);
	void OnTouches();
	void OnMove();
	void ChangeImageItem();
	MovementState();
	MovementState(ItemContainer* _itemContainer);
protected:
private:
	ItemContainer* itemContainer;
};

#endif // !__ITEM__MOVEMENT_STATE__