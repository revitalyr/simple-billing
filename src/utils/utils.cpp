//utils.cpp
#include "stdafx.h"
#include <regex>

#include "classes/containers/AccountsDB.h"
#include "classes/containers/PhoneNumberDB.h"

#include "utils.h"
#include "exceptions.h"

namespace BS_Billing {
  using namespace std;

    AnsiStringList const  
  split (AnsiString const &s, AnsiString const &re, size_t expected_size) {
    regex                 rgx(re);
    sregex_token_iterator it(s.begin(), s.end(), rgx, -1),
                          end;
    AnsiStringList        result;

    if ( expected_size > 0 )
      result.reserve (expected_size);

    for ( ; it != end; ++it)
      result.push_back (*it);

    if ( (expected_size > 0) && (result.size () != expected_size) )
      throw UnexpectedSizeException (s, expected_size, result.size ());

    return result;
  }

    int 
  strToInt  ( AnsiString const &  s) {
    std::string::size_type  sz;
    int                     result = stoi (s, &sz);

    if ( sz != s.length () )
      throw BadConversionException (s, "string", "int");
    
    return result;
  }

    TimePoint const       
  strToTimePoint  ( AnsiString const &  s) {
    return std::chrono::system_clock::from_time_t (strToInt (s));
  }

    Duration const
  strToDuration   ( AnsiString const &  s) {
    TimePoint   t = std::chrono::system_clock::from_time_t (strToInt (s));
    return std::chrono::duration_cast<Duration> (t - TimePoint ());
  }

    UniqueKey const
  strToUniqueKey  ( UniqueKey::EntityPtr entity, AnsiString const & s) {
    return UniqueKey (entity, strToInt (s));
  }

  Duration days (size_t v) {
    return std::chrono::duration_cast<Duration> (std::chrono::hours (24) * v);
  }

  Duration hours (size_t v) {
    return std::chrono::duration_cast<Duration> (std::chrono::hours (v));
  }

  Duration minutes (size_t v) {
    return std::chrono::duration_cast<Duration> (std::chrono::minutes (v));
  }

  Duration seconds (size_t v) {
    return std::chrono::duration_cast<Duration> (std::chrono::seconds (v));
  }
}
