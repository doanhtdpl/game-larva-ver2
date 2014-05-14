#include "IncreaseTapItemContainer.h"
#include "ChangeBodyIncreaseTapFactory.h"
#include "Utils.h"

IncreaseTapItemContainer::IncreaseTapItemContainer() : ItemContainer()
{

}

IncreaseTapItemContainer::~IncreaseTapItemContainer()
{

}

void IncreaseTapItemContainer::ChangeBody( ItemStateEnum state )
{
	this->body = ChangeBodyIncreaseTapItemFactory::getInstanceIncreaseTapFactory()->createBodyItem( state );
}
