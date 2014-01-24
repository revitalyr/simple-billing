//UsageTariff.h
#pragma once

#include <memory>

#include "definitions.h"
#include "classes/forward_dcl.h"
#include "BillItem.h"

namespace BS_Billing {

  class UsageTariff
  {
    //types
    private:
    protected:
    public:
    //data
    private:
      MonetaryUnits       mFee;
      int                 mPriority;  //TODO: make it enum like BEFORE_ALL, ..., AFTER_ALL
    protected:
    public:
    //methods
    private:
//                      UsageTariff  ( UsageTariff const & toCpy);
//      UsageTariff  & operator =    ( UsageTariff const & toCpy);
    protected:
                          UsageTariff     ( MonetaryUnits       fee,
                                            int                 priority);

      virtual BillItemPtr workupImpl      ( CDRPtr              cdr) const = 0;
    public:
      virtual             ~UsageTariff    ( );

      MonetaryUnits       fee             ( ) const;
      BillItemPtr         workup          ( CDRPtr              cdr) const;
  };

  struct FixedTariff : public UsageTariff {
                          FixedTariff     ( MonetaryUnits       fee);
    BillItemPtr           workupImpl      ( CDRPtr              cdr) const override;
  };

  struct TimedTariff : public UsageTariff {
    Duration              mPayFreeDuring;
    Duration              mPayFreeDuration;
                          TimedTariff     ( Duration            payFreeDuring,
                                            Duration            payFreeDuration);
    BillItemPtr           workupImpl      ( CDRPtr              cdr) const override;
  };

  struct DelayedTariff : public UsageTariff {
    Duration              mStartsAfter;
                          DelayedTariff   ( Duration            startsAfter);
    BillItemPtr           workupImpl      ( CDRPtr              cdr) const override;
  };

  struct DiscountTariff : public UsageTariff {
                          DiscountTariff  ( MonetaryUnits       fee);
  };
  

} //namespace BS_Billing

#ifndef _DEBUG
  #include "UsageTariff.inl"
#endif //_DEBUG
//#include "UsageTariff.imp"

