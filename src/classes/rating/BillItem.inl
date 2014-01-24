#pragma once

#include "BillItem.h"
#include "utils/utils.h"

#ifdef _DEBUG
  #define inline
#endif //_DEBUG

namespace BS_Billing {

  inline  BillItem::
  BillItem ( ) {
  }

  inline  BillItem::
  ~BillItem ( ) {
  }

  inline  MonetaryUnits BillItem::
  getTotal  ( ) const {
    return mTotal;
  }

  inline  void  BillItem::
  setTotal  (MonetaryUnits      total) {
    mTotal = total;
  }


/*
  inline  BillItem::
  BillItem ( BillItem const & toCpy)
  {
  }

  inline  BillItem & BillItem::
  operator = ( BillItem const & toCpy)
  {
  }
*/

} //namespace BS_Billing

#ifdef _DEBUG
  #undef inline
#endif //_DEBUG

