#include "ItemContainer.h"

#include "LockState.h"
#include "UnlockState.h"
#include "ReadyState.h"
#include "MovementState.h"
#include "UsedState.h"

ItemContainer::ItemContainer() : GameObj()
{
	state = new LockState( this );
}

ItemContainer::~ItemContainer()
{

}

void ItemContainer::unlock(int level)
{
	this->state->unlock(level);
}

void ItemContainer::update(float dt)
{
	this->state->update(dt);
}

void ItemContainer::OnTouches()
{
	this->state->OnTouches();
}

void ItemContainer::OnMove()
{
	this->state->OnMove();
}

void ItemContainer::ChangeBody( ItemStateEnum state )
{

}

ItemContainerState* ItemContainer::getState()
{
	return state;
}

void ItemContainer::setState(ItemContainerState* state)
{
	this->state = state;
}

void ItemContainer::setCost(int _cost)
{
	this->cost = _cost;
}

int  ItemContainer::getCost()
{
	return this->cost;
}

void ItemContainer::setLevelUnlock(int _level)
{
	this->levelUnlock = _level;
}

int  ItemContainer::getLevelUnlock()
{
	return this->levelUnlock;
}

void ItemContainer::setCount(int _count)
{
	this->count = _count;
}

int  ItemContainer::getCount()
{
	return this->count;
}

void ItemContainer::setDuringTime(float dt)
{
	this->duringTime = dt;
}

float  ItemContainer::getDuringTime()
{
	return this->duringTime;
}

ItemContainerState* ItemContainer::getLockState()
{
	ItemContainerState* state1 = new LockState( this );
	return state;
}

ItemContainerState* ItemContainer::getUnlockState()
{
	state = new UnlockState( this );
	return state;
}

ItemContainerState* ItemContainer::getReadyState()
{
	state = new ReadyState( this );
	return state;
}

ItemContainerState* ItemContainer::getMovementState()
{
	state = new MovementState( this );
	return state;
}

ItemContainerState* ItemContainer::getUsedState()
{
	state = new UsedState(  this );
	return state;
}