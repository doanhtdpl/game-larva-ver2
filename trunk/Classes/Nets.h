//---------------------------------------
//Name:    So Tuan Hoang
//Class:   Nets
//Project: Game Larva
//Purpose: Nets Item
//---------------------------------------

#ifndef __NETS__H_
#define __NETS__H_

#include "Item.h"

class Bug;

class Nets : public Item
{
public:
	Nets();
	Nets(vector<string> );
	~Nets();
	void update(float dt);
	void AffectToBugs(Bug* );
	void Use();
protected:
private:
};

#endif // !__NETS__H_
