#ifndef _INCREASE_TAP_ITEM_CONTAINER__
#define _INCREASE_TAP_ITEM_CONTAINER__

#include "ItemContainer.h"

class IncreaseTapItemContainer : public ItemContainer
{
public:
	IncreaseTapItemContainer();
	~IncreaseTapItemContainer();
	void ChangeBody( ItemStateEnum state );
protected:
private:
};

#endif // !_INCREASE_TAP_ITEM_CONTAINER__
