#include "stdafx.h"

#include "UniqueKey.h"
#include "UniqueKey.inl"
//#include "UniqueKey.imp"

namespace BS_Billing {

UniqueKey::UniqueKey ( EntityPtr entity, tID id)
                    : mEntity (entity)
                    , mID (id) {
  if ( mID == ID_NONE )
    mID = mEntity->getNextID ();
}

bool UniqueKey::operator == ( UniqueKey const   & other)  const {
  return (mEntity == other.mEntity) && (mID == other.mID);
}

bool UniqueKey::isValid ( ) const {
  return mID != ID_NONE;
}

UniqueKey::tID UniqueKey::getID ( ) const {
  return mID;
}

UniqueKey::Entity::Entity () : mID (UniqueKey::ID_NONE) {
}
 
UniqueKey::tID UniqueKey::Entity::getNextID () {
  return ++mID;
}


/*
UniqueKey::
~UniqueKey ( )
{
}
*/

// template struct UniqueKey <UserType>;

} //namespace BS_Billing
