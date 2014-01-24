//CDR.h
#pragma once

#include "definitions.h"
#include "Account.h"

#include "classes/UniqueKey.h"

namespace BS_Billing {
  class CDR
  {
  public:
    typedef UniqueKey::tID    tID;
  public:
                      CDR         ( );
                      CDR         ( tID const           & id,
                                    Account const       & account, 
                                    PhoneNumber const   & calledNumber,
                                    TimePoint const     & start,
                                    Duration const      & duration);
                      ~CDR        ( );

    bool              isValid     ( ) const;

    static CDR const  make        ( Account const       & account, 
                                    PhoneNumber const   & calledNumber,
                                    TimePoint const     & start,
                                    Duration const      & duration);
  public:
    Account           mAccount;
    PhoneNumber       mCalledNumber;
    TimePoint         mStart;
    Duration          mDuration;
  private:
    static UniqueKey::EntityPtr   gIdGenerator;
    UniqueKey         mID;
  };
}

