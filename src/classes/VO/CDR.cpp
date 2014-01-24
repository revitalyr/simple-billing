#include "stdafx.h"
#include "CDR.h"

namespace BS_Billing {

UniqueKey::EntityPtr    CDR::gIdGenerator (new UniqueKey::Entity ());

CDR::CDR()
          : mID (gIdGenerator, UniqueKey::ID_NONE)
{
}

CDR::CDR (tID const & id, Account const & account, PhoneNumber const & calledNumber, TimePoint const   & start, Duration const  & duration)
          : mID (gIdGenerator, id)
          , mAccount (account)
          , mCalledNumber (calledNumber)
          , mStart (start)
          , mDuration (duration) {
        
}

CDR::~CDR(void)
{
}

bool CDR::isValid ( ) const {
  return mID.isValid () && mAccount.isValid ();
}

CDR const CDR::make ( Account const & account, PhoneNumber const & calledNumber, TimePoint const & start, Duration const & duration) {
  return CDR (gIdGenerator->getNextID (), account, calledNumber, start, duration);
}

}