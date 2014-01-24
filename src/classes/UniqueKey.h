#ifndef UniqueKey_h
  #define UniqueKey_h

  #include <memory>
  #include "definitions.h"

namespace BS_Billing {

  class UniqueKey
  {
    //types
    private:
    protected:
    public:
      typedef size_t                      tID;
      struct Entity {
        tID             mID;

                        Entity    ();
        tID             getNextID ();
      };
      typedef std::shared_ptr <Entity>    EntityPtr;
    //data
    private:
      EntityPtr         mEntity;
      tID               mID;
    protected:
    public:
      tID const static  ID_NONE = 0;
    //methods
    private:
//                        UniqueKey   ( UniqueKey const & toCpy);
//      UniqueKey       & operator =  ( UniqueKey const & toCpy);
    protected:
    public:
                          UniqueKey       ( EntityPtr           entity,
                                            tID                 id);
                          ~UniqueKey      ( );

      bool                operator ==     ( UniqueKey const   & other)  const;
      bool                isValid         ( ) const;
      tID                 getID           ( ) const;
  };

} //namespace BS_Billing

  #ifndef _DEBUG
    #include "UniqueKey.inl"
//    #include "UniqueKey.imp"
  #endif //_DEBUG

#endif  //UniqueKey_h
