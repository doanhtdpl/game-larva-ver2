#include "HourglassItemContainer.h"
#include "ChangeBodyHourglassItemFactory.h"
#include "Utils.h"

HourglassItemContainer::HourglassItemContainer() : ItemContainer()
{

}

HourglassItemContainer::~HourglassItemContainer()
{

}

void HourglassItemContainer::ChangeBody( ItemStateEnum state )
{
	this->body = ChangeBodyHourglassItemFactory::getInstanceHourglassFactory()->createBodyItem( state );
}
