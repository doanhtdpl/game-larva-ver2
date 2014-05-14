#include "MineItemContainer.h"
#include "ChangeBodyMineItemFactory.h"
#include "Utils.h"

MineItemContainer::MineItemContainer() : ItemContainer()
{

}

MineItemContainer::~MineItemContainer()
{

}

void MineItemContainer::ChangeBody( ItemStateEnum state )
{
	this->body = ChangeBodyMineItemFactory::getInstanceMineFactory()->createBodyItem( state );
}
