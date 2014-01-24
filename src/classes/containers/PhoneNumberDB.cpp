#include "stdafx.h"

#include "PhoneNumberDB.h"
#include "PhoneNumberDB.inl"

#include "utils/utils.h"
#include "utils/exceptions.h"

namespace BS_Billing {

template class IdBasedContainer <PhoneNumber>;
IdBasedContainer<PhoneNumber>::tDB    IdBasedContainer<PhoneNumber>::gDB;


#if 0
PhoneNumberDB::tDB         PhoneNumberDB::gDB;

PhoneNumberDB & PhoneNumberDB::instance () {
  static PhoneNumberDB    inst;
  return inst;
}

/*
PhoneNumberDB::
~PhoneNumberDB ( )
{
}
*/

  PhoneNumber const PhoneNumberDB::
getByID ( PhoneNumber::tID const & id, AccessMode mode) {
  tCIt    it = gDB.find (id);

  if ( it != gDB.end () )
    return it->second;

  if ( mode != AccessMode::AllowCreation )
    throw NonExistingException ("Account id " + id);

  PhoneNumber result (id, AnsiString ());

  gDB [result.getID ()] = result;

  return result;
}

  void PhoneNumberDB::
update ( PhoneNumber const & inst, AccessMode mode) {
  if ( ! inst.isValid () )
    throw BadInstanceException (toStr (inst));

  tCIt    it = gDB.find (inst.getID ());

  if ( (it == gDB.end ()) && (mode != AccessMode::AllowCreation) )
    throw NonExistingException (toStr (inst));

  gDB [inst.getID ()] = inst;
}
#endif

} //namespace BS_Billing
