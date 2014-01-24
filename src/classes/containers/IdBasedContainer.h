#ifndef IdBasedContainer_h
  #define IdBasedContainer_h

  #include <map>

  #include "definitions.h"

namespace BS_Billing {

  template <class ItemType>
  class IdBasedContainer {
    //types
    private:
      typedef typename ItemType::tID                      tID;
      typedef std::map <tID, ItemType>                    tDB;
      typedef typename tDB::const_iterator                tCIt;
      typedef typename tDB::iterator                      tIt;
    protected:
    public:
      typedef IdBasedContainer<ItemType>                  SelfType;
    //data
    private:
      tDB static              gDB;
    protected:
    public:
    //methods
    private:
                              IdBasedContainer  ( );
                              ~IdBasedContainer ( );
                              IdBasedContainer  ( IdBasedContainer const & toCpy);
      IdBasedContainer      & operator =    ( IdBasedContainer const & toCpy);
    protected:
    public:
      static SelfType       & instance      ( );

      ItemType const          getByID       ( tID const             & id,
                                              AccessMode              mode);
      ItemType const          getByID       ( AnsiString const      & strId,
                                              AccessMode              mode);
      void                    update        ( ItemType const     & inst,
                                              AccessMode              mode = AccessMode::Existing);
  };

} //namespace BS_Billing

  #include "IdBasedContainer.impl"

#endif  //IdBasedContainer_h
