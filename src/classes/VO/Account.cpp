#include "stdafx.h"
#include "Account.h"

namespace BS_Billing {
  UniqueKey::EntityPtr    Account::gIdGenerator (new UniqueKey::Entity ());

  Account::Account() 
                  : mID (gIdGenerator, UniqueKey::ID_NONE) {
  }

  Account::Account (tID const  & id, PhoneNumber const & phoneNumber) 
                  : mID (gIdGenerator, id)
                  , mPhoneNumber (phoneNumber) {
  }

  Account::~Account() {
  }

  bool Account::operator == ( Account const & other) const {
    return std::make_tuple (mID, mPhoneNumber) == std::make_tuple (other.mID, other.mPhoneNumber);
  }

  bool Account::isValid ( ) const {
    return mID.isValid () && mPhoneNumber.isValid ();
  }

  Account::tID Account::getID ( ) const {
    return mID.getID ();
  }

  Account  Account::make (PhoneNumber const & phoneNumber) {
    return Account (gIdGenerator->getNextID (), phoneNumber);
  }

  Account  Account::make ( AnsiString const  & phoneNumber, MonetaryUnits balance, TimePoint balanceDate) {
    Account result = make (PhoneNumber::make (phoneNumber));
    result.mBalance = balance;
    result.mBalanceDate = balanceDate;
    return result;
  }
}