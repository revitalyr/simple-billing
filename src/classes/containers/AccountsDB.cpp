#include "stdafx.h"

#include <algorithm>

#include "AccountsDB.h"
//#include "AccountsDB.inl"

#include "utils/utils.h"
#include "utils/exceptions.h"

namespace BS_Billing {

template class IdBasedContainer <Account>;
IdBasedContainer<Account>::tDB    IdBasedContainer<Account>::gDB;


/*
AccountsDB::tDB         AccountsDB::gDB;

AccountsDB::
AccountsDB ( )  {
}

AccountsDB & AccountsDB::instance () {
  static AccountsDB   inst;
  return inst;
}

  Account const AccountsDB::
getByID ( AnsiString const & strId, AccessMode mode) {
  return getByID (strToInt (strId), mode);
}

  Account const AccountsDB::
getByID ( Account::tID const & id, AccessMode mode) {
  tCIt    it = gDB.find (id);

  if ( it != gDB.end () )
    return it->second;

  if ( mode != AccessMode::AllowCreation )
    throw NonExistingException ("Account id " + id);

  return Account::make (PhoneNumber ());
}
*/
/*
AccountsDB::
~AccountsDB ( )
{
}
*/

// template struct AccountsDB <UserType>;

} //namespace BS_Billing
