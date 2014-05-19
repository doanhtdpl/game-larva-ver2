#ifndef __LIST_VIEW_ITEM__H__
#define __LIST_VIEW_ITEM__H__

#include "cocos2d.h"
#include "ItemContainer.h"
#include "vector"

using namespace cocos2d;

class ListViewItem
{
private:
	CCPoint position;//top and left
	int width;
	int height;
	vector< ItemContainer* > listItem; 
public:
	ListViewItem();
	ListViewItem(float x, float y, int _width, int _height);
	bool addItemToList(ItemContainer* , bool addByVertical);//true: vertical, false: horizon...
};

#endif // !__LIST_VIEW_ITEM__H__

