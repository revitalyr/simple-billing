#ifndef PhoneNumberDB_h
  #define PhoneNumberDB_h

  #include <map>

  #include "definitions.h"
  #include "classes/VO/PhoneNumber.h"
  #include "IdBasedContainer.h"

namespace BS_Billing {

  typedef IdBasedContainer <PhoneNumber>      PhoneNumberDB;

/*
  class PhoneNumberDB
  {
    //types
    private:
      typedef std::map <PhoneNumber::tID, PhoneNumber>    tDB;
      typedef tDB::const_iterator                         tCIt;
      typedef tDB::iterator                               tIt;
    protected:
    public:
    //data
    private:
      tDB static              gDB;
    protected:
    public:
    //methods
    private:
                              PhoneNumberDB ( );
                              ~PhoneNumberDB( );
                              PhoneNumberDB ( PhoneNumberDB const & toCpy);
      PhoneNumberDB         & operator =    ( PhoneNumberDB const & toCpy);
    protected:
    public:
      static PhoneNumberDB  & instance      ( );

      PhoneNumber const       getByID       ( PhoneNumber::tID const  & id,
                                              AccessMode              mode);
      PhoneNumber const       getByID       ( AnsiString const      & strId,
                                              AccessMode              mode);
      void                    update        ( PhoneNumber const     & inst,
                                              AccessMode              mode = AccessMode::Existing);
  };
*/

} //namespace BS_Billing

  #ifndef _DEBUG
    #include "PhoneNumberDB.inl"
//    #include "PhoneNumberDB.imp"
  #endif //_DEBUG

  #include "IdBasedContainer.impl"

#endif  //PhoneNumberDB_h
