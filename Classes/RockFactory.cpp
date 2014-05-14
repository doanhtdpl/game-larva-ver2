#include "RockFactory.h"

RockFactory* RockFactory::_instanceBF = NULL;

ObjFactory* RockFactory::getInstanceBF()
{
	if (_instanceBF == 0)
	{
		_instanceBF = new RockFactory();
	}
	return _instanceBF;
}

RockFactory::RockFactory()
{

}

GameObj* RockFactory::CreateObj(vector<string> arr)
{
	return NULL;
}