//---------------------------------------
//Name:    So Tuan Hoang
//Class:   Item
//Project: Game Larva
//Purpose: Item Systems for Game
//---------------------------------------

#ifndef __ITEM__H_
#define __ITEM__H_

#include "GameObj.h"

class Bug; 

class Item : public GameObj
{
public:
	Item();
	Item( vector<string> );
	~Item();
	virtual void update(float dt);
	virtual void AffectToBugs(Bug** );
	virtual void Use() = 0;
protected:

	cocos2d::CCRect effectBound;
private:

};

#endif // !__ITEM__H_

