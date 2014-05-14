#ifndef __OBJ_FACTORY_H_
#define __OBJ_FACTORY_H_
#include <vector>
#include "GameObj.h"
class ObjFactory
{
public:
	virtual GameObj* CreateObj(std::vector<string>) = 0;
};

#endif