#include "stdafx.h"

#include "IdBasedContainer.h"
#include "IdBasedContainer.inl"
#include "IdBasedContainer.impl"

namespace BS_Billing {

  template <class ItemType>
  typename IdBasedContainer<ItemType>::tDB    IdBasedContainer<ItemType>::gDB;

/*
IdBasedContainer::
~IdBasedContainer ( )
{
}
*/

// template struct IdBasedContainer <UserType>;

} //namespace BS_Billing
