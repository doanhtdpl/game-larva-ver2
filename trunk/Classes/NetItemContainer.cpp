#include "NetItemContainer.h"
#include "ChangeBodyNetItemFactory.h"
#include "Utils.h"

NetItemContainer::NetItemContainer() : ItemContainer()
{

}

NetItemContainer::~NetItemContainer()
{

}

void NetItemContainer::ChangeBody( ItemStateEnum state )
{
	this->body = ChangeBodyNetItemFactory::getInstanceNetFactory()->createBodyItem( state );
}
