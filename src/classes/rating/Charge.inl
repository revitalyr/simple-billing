#ifndef Charge_inl
  #define Charge_inl

  #include "Charge.h"
  //#include "Utils.h"

  #ifdef _DEBUG
    #define inline
  #endif //_DEBUG

namespace BS_Billing {

  inline  Charge::
  Charge ( MonetaryUnits fee)
          : mFee (fee)  {
  }

  inline  Charge::
  ~Charge ( )  {
  }


/*
  inline  Charge::
  Charge ( Charge const & toCpy)
  {
  }

  inline  Charge & Charge::
  operator = ( Charge const & toCpy)
  {
  }
*/

} //namespace BS_Billing

  #ifdef _DEBUG
    #undef inline
  #endif //_DEBUG

#endif  //Charge_inl
