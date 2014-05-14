#include "Configs.h"

Configs::Configs()
{

}

Configs::~Configs()
{

}


void Configs::Insert(CCDictionary* dic)
{
	myDic.push_back(dic);
}

void Configs::Clear()
{
	myDic.clear();
}