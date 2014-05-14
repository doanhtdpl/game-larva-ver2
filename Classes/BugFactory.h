#ifndef __BUG_FACTORY_
#define __BUG_FACTORY_

#include "ObjFactory.h"

class BugFactory : public ObjFactory
{
private:
	static BugFactory* _instanceBF;
protected:
	BugFactory();
public:
	static ObjFactory* getInstanceBF();
	GameObj* CreateObj(std::vector<string>);
};
#endif // !__BUG_FACTORY_
