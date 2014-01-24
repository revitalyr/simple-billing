//BillItem.h
#pragma once

#include <memory>

#include "definitions.h"
#include "classes/forward_dcl.h"
#include "UsageTariff.h"

namespace BS_Billing {

  class BillItem
  {
    //types
    private:
    protected:
    public:
    //data
    private:
    protected:
    public:
      UsageTariffPtr    mTariff;
      AccountPtr        mAccount;
      PhoneNumberPtr    mCalledNumber;
      TimePoint         mStart;
      Duration          mDuration;
      MonetaryUnits     mTotal;
    //methods
    private:
//                      BillItem  ( BillItem const & toCpy);
//      BillItem  & operator =    ( BillItem const & toCpy);
    protected:
    public:
                        BillItem  ( );
                        BillItem  ( UsageTariffPtr    tariff, 
                                    CDR const       & cdr);
                        ~BillItem ( );

      MonetaryUnits     getTotal  ( ) const;
      void              setTotal  (MonetaryUnits      total);
  };

} //namespace BS_Billing

#ifndef _DEBUG
  #include "BillItem.inl"
#endif //_DEBUG
//#include "BillItem.imp"

