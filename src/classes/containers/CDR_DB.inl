#ifndef CDR_DB_inl
  #define CDR_DB_inl

  #include "CDR_DB.h"
  //#include "Utils.h"

  #ifdef _DEBUG
    #define inline
  #endif //_DEBUG

namespace BS_Billing {

  inline  CDR_DB::
  CDR_DB ( )
  {
  }

  inline  CDR_DB::
  ~CDR_DB ( )
  {
  }


/*
  inline  CDR_DB::
  CDR_DB ( CDR_DB const & toCpy)
  {
  }

  inline  CDR_DB & CDR_DB::
  operator = ( CDR_DB const & toCpy)
  {
  }
*/

} //namespace BS_Billing

  #ifdef _DEBUG
    #undef inline
  #endif //_DEBUG

#endif  //CDR_DB_inl
