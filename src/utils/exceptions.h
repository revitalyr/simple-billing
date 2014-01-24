//exceptions.h
#pragma once

#include <stdexcept>
#include "definitions.h"

#include "utils.h"

namespace BS_Billing {
  typedef std::runtime_error    RootOfExceptions;

  #define DECLARE_BS_Billing_EXCEPTION( name, msg_tail, ... ) \
    struct name##Exception : RootOfExceptions { \
      name##Exception (AnsiString const &msg, __VA_ARGS__ ) \
      : RootOfExceptions ( #name "Exception: " + msg + msg_tail) { } \
    };

  DECLARE_BS_Billing_EXCEPTION (UnexpectedSize, " expected size " + toStr (expected) + ", got " + toStr (actual), size_t expected, size_t actual)
  DECLARE_BS_Billing_EXCEPTION (BadConversion, " from '" + from + "' to '" + to + "'", AnsiString const &from, AnsiString const &to) 
  DECLARE_BS_Billing_EXCEPTION (NonExisting, "")
  DECLARE_BS_Billing_EXCEPTION (BadInstance, "")
  DECLARE_BS_Billing_EXCEPTION (NotImplemented, "")

  #undef DECLARE_BS_Billing_EXCEPTION
}
