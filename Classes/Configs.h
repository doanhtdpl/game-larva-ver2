#ifndef __CONFIGS_H_
#define __CONFIGS_H_

#include "cocos2d.h"
#include <vector>
using namespace cocos2d;
class Configs : public CCObject
{
private:
	std::vector<CCDictionary*>myDic;
public:
	Configs();
	~Configs();
	void Clear();
	void Insert(CCDictionary*);
};
#endif