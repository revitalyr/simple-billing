#include "stdafx.h"

#include "CDR_DB.h"
#include "CDR_DB.inl"

#include "utils/utils.h"
#include "utils/exceptions.h"

namespace BS_Billing {

  CDR_DB::tDB             CDR_DB::gDB;

CDR_DB & CDR_DB::instance () {
  static CDR_DB   inst;
  return inst;
}

/*
CDR_DB::
~CDR_DB ( )
{
}
*/

  CDR const CDR_DB::
getByID ( AnsiString const & strId, AccessMode mode) {
  return getByID (strToInt (strId), mode);
}

  CDR const CDR_DB::
getByID ( CDR::tID const & id, AccessMode mode) {
  tCIt    it = gDB.find (id);

  if ( it != gDB.end () )
    return it->second;

  if ( mode != AccessMode::AllowCreation )
    throw NonExistingException ("Account id " + id);

  return CDR::make (Account (), PhoneNumber (), TimePoint (), Duration ());
}

// template struct CDR_DB <UserType>;

} //namespace BS_Billing
