//Account.h
#pragma once

#include "definitions.h"
#include "PhoneNumber.h"
#include "classes/UniqueKey.h"

namespace BS_Billing {
  class Account
  {
  public:
    typedef UniqueKey::tID    tID;
  public:
                        Account         ( );
                        Account         ( tID const         & id,
                                          PhoneNumber const & phoneNumber = PhoneNumber ());
                        ~Account        ( );

    bool                operator ==     ( Account const     & other)  const;
    bool                isValid         ( ) const;
    tID                 getID           ( ) const;

    static Account      make            ( PhoneNumber const & phoneNumber);
    static Account      make            ( AnsiString const  & phoneNumber, 
                                          MonetaryUnits       balance,
                                          TimePoint           balanceDate);
  public:
    PhoneNumber         mPhoneNumber;
    Duration            mFreeTimeUsed;
    MonetaryUnits       mBalance;
    TimePoint           mBalanceDate;
  private:
    static UniqueKey::EntityPtr   gIdGenerator;
    UniqueKey           mID;
  };
}

