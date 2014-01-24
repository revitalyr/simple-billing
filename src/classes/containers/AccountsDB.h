#ifndef AccountsDB_h
  #define AccountsDB_h

  #include <map>

  #include "definitions.h"
  #include "classes/VO/Account.h"
  #include "IdBasedContainer.h"

namespace BS_Billing {

  typedef IdBasedContainer <Account>      AccountsDB;
#if 0
  class AccountsDB
  {
    //types
    private:
      typedef std::map <Account::tID, Account>    tDB;
      typedef tDB::const_iterator                 tCIt;
      typedef tDB::iterator                       tIt;
    protected:
    public:
    //data
    private:
      tDB static          gDB;
    protected:
    public:
    //methods
    private:
                          AccountsDB  ( );
                          ~AccountsDB ( );
                          AccountsDB  ( AccountsDB const  & toCpy) /*= delete*/;
      AccountsDB        & operator =  ( AccountsDB const  & toCpy) /*= delete*/;
    protected:
    public:
      static AccountsDB & instance ();

      Account const       getByID ( Account::tID const  & id,
                                    AccessMode            mode);
      Account const       getByID ( AnsiString const    & strId,
                                    AccessMode            mode);
  };
#endif

} //namespace BS_Billing

  #ifndef _DEBUG
    //#include "AccountsDB.inl"
//    #include "AccountsDB.imp"
  #endif //_DEBUG

  #include "IdBasedContainer.impl"

#endif  //AccountsDB_h

