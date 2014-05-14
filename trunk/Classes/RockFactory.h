#ifndef __ROCK_FACTORY_
#define __ROCK_FACTORY_
#include "ObjFactory.h"

class RockFactory : public ObjFactory
{
private:
	static RockFactory* _instanceBF;
protected:
	RockFactory();
public:
	static ObjFactory* getInstanceBF();
	GameObj* CreateObj(std::vector<string>);
};
#endif