#include "BugFactory.h"
#include "Bug.h"

BugFactory* BugFactory::_instanceBF = NULL;

ObjFactory* BugFactory::getInstanceBF()
{
	if (_instanceBF == 0)
	{
		_instanceBF = new BugFactory();
	}
	return _instanceBF;
}

BugFactory::BugFactory()
{

}

GameObj* BugFactory::CreateObj(vector<string> arr)
{
	return new Bug(arr);
}