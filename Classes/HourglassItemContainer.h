#ifndef __HOURGLASS_ITEM_CONTAINER_
#define __HOURGLASS_ITEM_CONTAINER_

#include "ItemContainer.h"

class HourglassItemContainer : public ItemContainer
{
public:
	HourglassItemContainer();
	~HourglassItemContainer();
	void ChangeBody( ItemStateEnum state );
protected:
private:
};

#endif // !__HOURGLASS_ITEM_CONTAINER_
