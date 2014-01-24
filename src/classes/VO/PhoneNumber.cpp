#include "stdafx.h"

#include <tuple>

#include "PhoneNumber.h"

namespace BS_Billing {

  UniqueKey::EntityPtr    PhoneNumber::gIdGenerator (new UniqueKey::Entity ());

PhoneNumber::PhoneNumber()
                        : mID (gIdGenerator, UniqueKey::ID_NONE) {
}

PhoneNumber::PhoneNumber (tID const & id) 
                        : mID (gIdGenerator, id) {
}

//TODO: normalize number
PhoneNumber::PhoneNumber (tID const & id, AnsiString const & num) 
                        : mID (gIdGenerator, id)
                        , mNumber (num) {
}

PhoneNumber::~PhoneNumber()
{
}

bool PhoneNumber::operator == ( PhoneNumber const   & other)  const {
  return std::make_tuple (mID, mNumber) == std::make_tuple (other.mID, other.mNumber);
}

bool PhoneNumber::isHomeNetwork() const {
  static AnsiString const   prefixes [] = { "050", "066", "095", "099" };

  return std::any_of (begin (prefixes), end (prefixes), 
               [this] (AnsiString const & s) 
                { 
                  return s == mNumber.substr(0, OPERATOR_PREFIX_LENGTH); 
                });
}

bool PhoneNumber::isSameOperator(PhoneNumber const &other) const {  
  return mNumber.substr(0, OPERATOR_PREFIX_LENGTH) == other.mNumber.substr(0, OPERATOR_PREFIX_LENGTH);
}

bool PhoneNumber::isValid ( ) const {
  return mID.isValid () && (mNumber.length () >= OPERATOR_PREFIX_LENGTH);
}

PhoneNumber::tID PhoneNumber::getID ( ) const {
  return mID.getID ();
}

PhoneNumber PhoneNumber::make ( AnsiString const    & num) {
  return PhoneNumber (gIdGenerator->getNextID (), num);
}

}