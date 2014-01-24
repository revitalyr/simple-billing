//forward_dcl.h
#pragma once

#include <memory>

namespace BS_Billing {
  class BillItem;         typedef std::shared_ptr <BillItem>      BillItemPtr;
  class UsageTariff;      typedef std::shared_ptr <UsageTariff>   UsageTariffPtr;
  class Account;          typedef std::shared_ptr <Account>       AccountPtr;
  class PhoneNumber;      typedef std::shared_ptr <PhoneNumber>   PhoneNumberPtr;
  class CDR;              typedef std::shared_ptr <CDR>           CDRPtr;
}
