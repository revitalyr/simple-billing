//utils.h
#pragma once

#include "definitions.h"
#include "classes/VO/CDR.h"

namespace BS_Billing {
  AnsiStringList const  split           ( AnsiString const      & s, 
                                          AnsiString const      & re,
                                          size_t                  expected_size = 0);
  
  template <typename T>
  AnsiString const      toStr           ( T const               & v);

  int                   strToInt        ( AnsiString const      & s);
  UniqueKey const       strToUniqueKey  ( UniqueKey::EntityPtr    entity,
                                          AnsiString const      & s);

  ///time in std::time_t
  TimePoint const       strToTimePoint  ( AnsiString const      & s);
  Duration const        strToDuration   ( AnsiString const      & s);

  Duration              days            ( size_t                  v);
  Duration              hours           ( size_t                  v);
  Duration              minutes         ( size_t                  v);
  Duration              seconds         ( size_t                  v);
}

#include "utils.impl"