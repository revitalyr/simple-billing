//PhoneNumber.h
#pragma once

#include "definitions.h"
#include "classes/UniqueKey.h"

namespace BS_Billing {
  class PhoneNumber
  {
  public:
    typedef UniqueKey::tID    tID;
    static const size_t       OPERATOR_PREFIX_LENGTH = 3;
  public:
                        PhoneNumber     ( );
                        PhoneNumber     ( tID const           & id);
                        PhoneNumber     ( tID const           & id,
                                          AnsiString const    & num);
                        ~PhoneNumber    ( );

    bool                operator ==     ( PhoneNumber const   & other)  const;

    bool                isHomeNetwork   ( )                             const;
    bool                isSameOperator  ( PhoneNumber const   & other)  const;
    bool                isValid         ( )                             const;
    tID                 getID           ( ) const;

    static PhoneNumber  make            ( AnsiString const    & num);
  public:
    AnsiString          mNumber;
  private:
    static UniqueKey::EntityPtr   gIdGenerator;
    UniqueKey           mID;
  };
}