#ifndef CDR_DB_h
  #define CDR_DB_h

  #include <map>

  #include "definitions.h"
  #include "classes/VO/CDR.h"

namespace BS_Billing {

  class CDR_DB
  {
    //types
    private:
      typedef std::map <CDR::tID, CDR>                    tDB;
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
                              CDR_DB        ( );
                              ~CDR_DB       ( );
                              CDR_DB        ( CDR_DB const & toCpy);
      CDR_DB                & operator =    ( CDR_DB const & toCpy);
    protected:
    public:
      static CDR_DB         & instance      ( );

      CDR const               getByID       ( CDR::tID const        & id,
                                              AccessMode              mode);
      CDR const               getByID       ( AnsiString const      & strId,
                                              AccessMode              mode);
  };

} //namespace BS_Billing

  #ifndef _DEBUG
    #include "CDR_DB.inl"
//    #include "CDR_DB.imp"
  #endif //_DEBUG

#endif  //CDR_DB_h
