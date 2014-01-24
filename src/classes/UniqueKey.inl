#ifndef UniqueKey_inl
  #define UniqueKey_inl

  #include "UniqueKey.h"
  //#include "Utils.h"

  #ifdef _DEBUG
    #define inline
  #endif //_DEBUG

namespace BS_Billing {

  inline  UniqueKey::
  ~UniqueKey ( )
  {
  }


/*
  inline  UniqueKey::
  UniqueKey ( UniqueKey const & toCpy)
  {
  }

  inline  UniqueKey & UniqueKey::
  operator = ( UniqueKey const & toCpy)
  {
  }
*/

} //namespace BS_Billing

  #ifdef _DEBUG
    #undef inline
  #endif //_DEBUG

#endif  //UniqueKey_inl
