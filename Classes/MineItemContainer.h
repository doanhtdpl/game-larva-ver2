#ifndef __MINE_ITEM_CONTAINER_
#define __MINE_ITEM_CONTAINER_

#include "ItemContainer.h"

class MineItemContainer : public ItemContainer
{
public:
	MineItemContainer();
	~MineItemContainer();
	void ChangeBody( ItemStateEnum state );
protected:
private:
};

#endif // !__MINE_ITEM_CONTAINER_