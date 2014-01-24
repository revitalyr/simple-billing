#include "stdafx.h"

#include "UsageTariff.h"
#include "UsageTariff.inl"

#include "classes/VO/Account.h"

#include "utils/exceptions.h"


namespace BS_Billing {

BillItemPtr UsageTariff::
workupImpl ( CDRPtr cdr) const {
  throw NotImplementedException (__FUNCTION__);
}

//TODO: check cdr validity before processing
BillItemPtr FixedTariff::
workupImpl ( CDRPtr cdr) const {
  UsageTariffPtr  tariff (new FixedTariff (*this));
  BillItemPtr     result (new BillItem (tariff, *cdr));
  
  result->setTotal (fee ());
  return result;
}

BillItemPtr TimedTariff::
workupImpl ( CDRPtr cdr) const {
  UsageTariffPtr  tariff (new TimedTariff (*this));
  BillItemPtr     result (new BillItem (tariff, *cdr));
  TimePoint       start = cdr->mStart;
  TimePoint       balanceDate = cdr->mAccount.mBalanceDate;

  if ( (start - balanceDate) < mPayFreeDuring ) {
    Duration      used = cdr->mAccount.mFreeTimeUsed;
    Duration      duration = cdr->mDuration;
    Duration      restDur = duration - used;

    if ( restDur > mPayFreeDuration ) {
      cdr->mAccount.mFreeTimeUsed += mPayFreeDuration;
      restDur -= mPayFreeDuration;
    }
    else {
      cdr->mAccount.mFreeTimeUsed += restDur;
      restDur = Duration::zero();
    }

    cdr->mDuration = restDur;
    result->mDuration = restDur;
  }

  return result;
}

BillItemPtr DelayedTariff::
workupImpl ( CDRPtr cdr) const {
  UsageTariffPtr  tariff (new DelayedTariff (*this));
  BillItemPtr     result (new BillItem (tariff, *cdr));
  
  throw NotImplementedException (__FUNCTION__);

  return result;
}

/*
UsageTariff::
~UsageTariff ( )
{
}
*/

// template struct UsageTariff <UserType>;

} //namespace BS_Billing
