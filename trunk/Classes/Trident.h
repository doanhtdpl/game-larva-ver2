//---------------------------------------
//Name:    So Tuan Hoang
//Class:   Nets
//Project: Game Larva
//Purpose: Nets Item
//---------------------------------------

#ifndef __TRIDENT__H_
#define __TRIDENT__H_

#include "Item.h"

class Bug;
class Arrow;

class Trident : public Item
{
public:
	Trident();
	Trident(vector<string> );
	~Trident();
	void update(float dt);
	void AffectToBugs(Bug* );
	void Use();
protected:
private:
	Arrow** arrArrow;
};

#endif // !__TRIDENT__H_
