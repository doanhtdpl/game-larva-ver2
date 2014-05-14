#ifndef __TRIDENT_ITEM_CONTAINER__
#define __TRIDENT_ITEM_CONTAINER__

#include "ItemContainer.h"

class TridentItemContainer : public ItemContainer
{
public:
	TridentItemContainer();
	~TridentItemContainer();
	void ChangeBody( ItemStateEnum state );
protected:
private:
};

#endif // !__TRIDENT_ITEM_CONTAINER__