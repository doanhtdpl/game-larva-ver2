#include "TridentItemContainer.h"
#include "ChangeBodyTridentItemFactory.h"
#include "Utils.h"

TridentItemContainer::TridentItemContainer() : ItemContainer()
{

}

TridentItemContainer::~TridentItemContainer()
{

}

void TridentItemContainer::ChangeBody( ItemStateEnum state )
{
	this->body = ChangeBodyTridentItemFactory::getInstanceTridentFactory()->createBodyItem( state );
}
