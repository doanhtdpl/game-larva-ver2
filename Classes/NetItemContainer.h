#ifndef __NET_ITEM_CONTAINER_
#define __NET_ITEM_CONTAINER_

#include "ItemContainer.h"

class NetItemContainer : public ItemContainer
{
public:
	NetItemContainer();
	~NetItemContainer();
	void ChangeBody( ItemStateEnum state );
protected:
private:
};

#endif // !__NET_ITEM_CONTAINER_