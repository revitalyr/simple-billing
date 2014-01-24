#include "stdafx.h"

#include "BillItem.h"
#include "BillItem.inl"

#include "classes/VO/CDR.h"

namespace BS_Billing {

BillItem::
BillItem  (UsageTariffPtr tariff, CDR const & cdr) 
          : mTariff (tariff)
          , mTotal (0)
          , mStart (cdr.mStart)
          , mDuration (cdr.mDuration) 
{
  mAccount = AccountPtr (new Account (cdr.mAccount));
  mCalledNumber = PhoneNumberPtr (new PhoneNumber (cdr.mCalledNumber));
}

/*
BillItem::
~BillItem ( )
{
}
*/

// template struct BillItem <UserType>;

} //namespace BS_Billing
