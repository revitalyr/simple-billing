//definitions.h

#pragma once

#include <vector>
#include <string>
#include <chrono>

namespace BS_Billing {
  typedef	std::string                           AnsiString;
  typedef	std::vector <AnsiString>              AnsiStringList;

  typedef	double                                MonetaryUnits;

  typedef	std::chrono::seconds	                Duration;
	typedef	std::chrono::system_clock::time_point	TimePoint;

  enum class AccessMode {
    Existing, AllowCreation
  };
}
