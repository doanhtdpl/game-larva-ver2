#ifndef __ITEM__CONTAINER__STATE__
#define __ITEM__CONTAINER__STATE__

#include "cocos2d.h"

class ItemContainerState
{
public:
	virtual void unlock(int level) = 0;
	virtual void update(float dt) = 0;
	virtual void OnTouches() = 0;
	virtual void OnMove() = 0;
	virtual void ChangeImageItem() = 0;
protected:
private:
};

#endif // !__ITEM__CONTAINER__STATE__


