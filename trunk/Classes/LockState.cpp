#include "LockState.h"
#include "ItemContainer.h"
#include "Utils.h"

LockState::LockState() : ItemContainerState()
{

}

LockState::LockState(ItemContainer* _itemContainer)
{
	this->itemContainer = _itemContainer;
}

void LockState::unlock(int level)
{

}

void LockState::update(float dt)
{

}

void LockState::OnTouches()
{

}

void LockState::OnMove()
{
	this->itemContainer->OnMove();
}

void LockState::ChangeImageItem()
{
	//ItemStateEnum state = ELockState;
	//this->itemContainer->ChangeBody( state );
}
