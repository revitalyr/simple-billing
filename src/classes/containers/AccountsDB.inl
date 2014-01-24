#ifndef AccountsDB_inl
  #define AccountsDB_inl

  #include "AccountsDB.h"
  //#include "Utils.h"

  #ifdef _DEBUG
    #define inline
  #endif //_DEBUG

namespace BS_Billing {

  inline  AccountsDB::
  ~AccountsDB ( )  {
  }


/*
  inline  AccountsDB::
  AccountsDB ( AccountsDB const & toCpy)
  {
  }

  inline  AccountsDB & AccountsDB::
  operator = ( AccountsDB const & toCpy)
  {
  }
*/

} //namespace BS_Billing

  #ifdef _DEBUG
    #undef inline
  #endif //_DEBUG

#endif  //AccountsDB_inl
