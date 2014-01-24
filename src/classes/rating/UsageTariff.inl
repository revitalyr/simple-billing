#pragma once

#include "UsageTariff.h"
#include "utils/utils.h"

#ifdef _DEBUG
  #define inline
#endif //_DEBUG

namespace BS_Billing {

  inline  UsageTariff::
  UsageTariff ( MonetaryUnits  fee, int priority)
              : mFee (fee)  
              , mPriority (priority)
  {  }

  inline  UsageTariff::
  ~UsageTariff ( )  {
  }

  inline  MonetaryUnits UsageTariff::
  fee ( ) const {
    return mFee;
  }

  inline  BillItemPtr UsageTariff::
  workup ( CDRPtr cdr) const {
    return workupImpl (cdr);
  }
           

  inline  FixedTariff::
  FixedTariff ( MonetaryUnits  fee)
              : UsageTariff (fee, 0)  
  {  }

  inline  TimedTariff::
  TimedTariff ( Duration payFreeDuring, Duration payFreeDuration) 
              : UsageTariff (0, -1)
              , mPayFreeDuring (payFreeDuring)
              , mPayFreeDuration (payFreeDuration) 
  {  }

  inline  DelayedTariff::
  DelayedTariff ( Duration startsAfter) 
              : UsageTariff (0, -1)
              , mStartsAfter (startsAfter)
  {  }

/*
  inline  UsageTariff::
  UsageTariff ( UsageTariff const & toCpy)
  {
  }

  inline  UsageTariff & UsageTariff::
  operator = ( UsageTariff const & toCpy)
  {
  }
*/

} //namespace BS_Billing

#ifdef _DEBUG
  #undef inline
#endif //_DEBUG

