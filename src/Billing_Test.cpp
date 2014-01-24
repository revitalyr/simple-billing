// Billing.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

#include <fstream>
#include <algorithm>

#include "classes/VO/PhoneNumber.h"
#include "classes/VO/Account.h"
#include "classes/VO/CDR.h"

#include "classes/containers/AccountsDB.h"
#include "classes/containers/PhoneNumberDB.h"

#include "classes/rating/UsageTariff.h"

#include "utils/utils.h"

#include "gtest/gtest.h"

using namespace BS_Billing;

namespace {
  using std::chrono::system_clock;

  //typedef std::chrono::duration<int,std::ratio<60*60*24> > days;

  AnsiString const  asTime_t (TimePoint const tp) {
    return toStr (system_clock::to_time_t (tp));
  }

  AnsiString const  asTime_t (Duration const &duration) {
    return asTime_t (TimePoint() + duration);
  }

  TimePoint now () {
    return system_clock::now();
  }

  //Duration operator "" s (size_t v) {
  //  return std::chrono::seconds (v);
  //}
}

namespace testing {
  namespace internal {//gtest.h
    template<>  ::std::string FormatForComparison <PhoneNumber, PhoneNumber>::Format(const PhoneNumber& value) {
      return toStr(value);
    }
    template<> ::std::string FormatForComparison <Duration, Duration>::Format(const Duration& value) {
      return toStr(value);
    }
    template<> ::std::string FormatForComparison <::std::chrono::minutes, Duration>::Format(const ::std::chrono::minutes& value) {
      return toStr(value.count ());
    }
    template<> ::std::string FormatForComparison <Duration, ::std::chrono::minutes>::Format(const Duration& value) {
      return toStr(value);
    }
  }


  typedef std::vector<CDR>    CDRs;

  const AnsiString    CDRs_FILE_NAME = "test_cdrs.csv";
  char const        * phoneNumbers [] = { "123-456", "050-123", "050-456", "066-123", "066-456" };

  AnsiString const  csvLineCDR (Account const &account, PhoneNumber const &phoneNumber, TimePoint const &start, Duration const &duration) {
    AnsiString  delim = ",";
    AnsiString  result;

    (result += toStr (account.getID ())) += delim;
    (result += toStr (phoneNumber.getID ())) += delim;
    (result += asTime_t (start)) += delim;
    result += asTime_t (duration);

    return result;
  }

  void makeCDRcsvFile (AnsiString const  &filename) {
    using namespace std;

    PhoneNumberDB   & pn_guide = PhoneNumberDB::instance ();
    AccountsDB      & acc_guide = AccountsDB::instance ();
    ofstream          file (filename);

    //TODO: check IO errors
    for_each (begin (phoneNumbers), end (phoneNumbers), [&file, &acc_guide, &pn_guide] (char const * acc_pn) {
      Account         account = acc_guide.getByID (UniqueKey::ID_NONE, AccessMode::AllowCreation);

      account.mPhoneNumber = PhoneNumber::make (acc_pn);
      acc_guide.update (account);

      for_each (begin (phoneNumbers), end (phoneNumbers), [&file, &account, &pn_guide] (char const * pn) {
        PhoneNumber   called = pn_guide.getByID (UniqueKey::ID_NONE, AccessMode::AllowCreation);
        called.mNumber = pn;

        for (TimePoint start, end (TimePoint () + minutes (10)); start <= end; start += seconds (145)) {
          for (Duration duration, max_length (minutes (10)); duration < max_length; duration += seconds (45)) {
            AnsiString  cdr = csvLineCDR (account, called, start, duration);

            file << cdr << "\n";
          }
        }
      });
    });

    file.close ();
  }

  CDR const parseCDR (AnsiString const &csv) {
    AnsiStringList        fields (std::move (split (csv, ",", 4)));
    Account               account (AccountsDB::instance ().getByID (fields [0], AccessMode::AllowCreation));
    PhoneNumber           phoneNumber (PhoneNumberDB::instance ().getByID (fields [1], AccessMode::AllowCreation));
    CDR                   result = CDR::make (account, phoneNumber, strToTimePoint (fields [2]), strToDuration (fields [3]));

    if ( ! result.isValid () )
      throw BadConversionException (csv, "csv", "CDR");

    return result;
  }

  CDRs importCDRs (AnsiString const  &filename, size_t cnt = 0) {
    using namespace std;

    CDRs        result;
    ifstream    file (filename);
    char        buf [1024];

    //TODO: check IO errors
    while ( file.getline (buf, sizeof (buf)) && (!cnt || (result.size () < cnt)) ) {

      if ( (result.size () % 10000) == 0 )
        result.reserve (10000);

      result.push_back (parseCDR (buf));
    }

    return result;
  }
}

//======================================================PrimitiveTypeTest
TEST(PrimitiveTypeTest, MakeTimePoint) {
  TimePoint     emptyTP;
  TimePoint     zeroTP = strToTimePoint ("0");
  TimePoint     hundredTP = strToTimePoint ("100");

  EXPECT_EQ (emptyTP,                 zeroTP);
  EXPECT_NE (emptyTP,                 hundredTP);
  EXPECT_NE (emptyTP + minutes(1),    zeroTP);
  EXPECT_EQ (seconds(60),             minutes(1));
}

TEST(PrimitiveTypeTest, MakeDuration) {  
  Duration      emptyDuration;
  Duration      zeroDuration = strToDuration ("0");

  EXPECT_EQ (emptyDuration, zeroDuration);

  TimePoint     zeroTP = strToTimePoint ("0");
  TimePoint     hundredTP = strToTimePoint ("100");
  Duration      hundredDuration = strToDuration ("100");

  EXPECT_EQ (hundredTP - zeroTP, hundredDuration);
}

//======================================================ValueObjectTest
TEST(ValueObjectTest, MakePhoneNumber) {  
  EXPECT_FALSE  (PhoneNumber().isValid ());
  EXPECT_TRUE   (PhoneNumber::make ("123").isValid ());
  EXPECT_TRUE   (PhoneNumber::make ("095-123").isHomeNetwork ());
  EXPECT_FALSE  (PhoneNumber::make ("195-123").isHomeNetwork ());
  EXPECT_TRUE   (PhoneNumber::make ("456-123").isSameOperator (PhoneNumber::make ("456-789")));
  EXPECT_FALSE  (PhoneNumber::make ("456-123").isSameOperator (PhoneNumber::make ("789-456")));
}

TEST(ValueObjectTest, MakeAccount) {  
  PhoneNumber   emptyPN;
  PhoneNumber   homePN = PhoneNumber::make ("095-123");

  EXPECT_FALSE  (Account ().isValid ());
  EXPECT_FALSE  (Account::make (emptyPN).isValid ());
  EXPECT_TRUE   (Account::make (homePN).isValid ());
}

TEST(ValueObjectTest, MakeCDR) {  
  EXPECT_FALSE  (CDR ().isValid ());

  PhoneNumber   emptyPN;
  PhoneNumber   homePN = PhoneNumber::make ("095-123");
  PhoneNumber   foreignPN = PhoneNumber::make ("123-456");
  Account       emptyAccount;
  Account       homeAccount = Account::make (homePN);
  TimePoint     emptyStart;
  Duration      emptyDuration;

  EXPECT_FALSE  (CDR::make (emptyAccount, emptyPN,  emptyStart, emptyDuration).isValid ());
  EXPECT_TRUE   (CDR::make (homeAccount,  homePN,   emptyStart, emptyDuration).isValid ());

  TimePoint     start1h = strToTimePoint (asTime_t (hours (1)));
  Duration      duration30s = strToDuration (asTime_t (seconds (30)));
  EXPECT_TRUE   (CDR::make (homeAccount,  homePN,   start1h,    duration30s).isValid ());

  AccountsDB::instance ().update (homeAccount, AccessMode::AllowCreation);
  PhoneNumberDB::instance ().update (homePN, AccessMode::AllowCreation);
  AnsiString    cdrStr1 = testing::csvLineCDR (homeAccount,  homePN,   start1h,    duration30s);
  CDR           cdr1 = testing::parseCDR (cdrStr1);

  EXPECT_TRUE   (cdr1.isValid ());
}

//======================================================ContainerTest
TEST(ContainerTest, CreateInstancePhoneNumberDB) {
  PhoneNumberDB & db = PhoneNumberDB::instance ();
  PhoneNumber     pn = db.getByID (UniqueKey::ID_NONE, AccessMode::AllowCreation);

  EXPECT_NE       (pn.getID (), UniqueKey::ID_NONE);

  pn.mNumber = "123";     EXPECT_TRUE (pn.isValid ());
  db.update (pn);         EXPECT_EQ   (pn, db.getByID (pn.getID (), AccessMode::Existing));
}

TEST(ContainerTest, CreateInstanceAccountsDB) {
  AccountsDB    & db = AccountsDB::instance ();
  Account         account = db.getByID (UniqueKey::ID_NONE, AccessMode::AllowCreation);

  EXPECT_NE       (account.getID (), UniqueKey::ID_NONE);

  account.mPhoneNumber = PhoneNumber::make ("123-456");   EXPECT_TRUE (account.isValid ());
  db.update (account);                                    EXPECT_EQ   (account, db.getByID (account.getID (), AccessMode::Existing));
}

//======================================================RatingTest
struct RatingTest : testing::Test {

  static const size_t CHECK_SIZE = 10;
  AnsiString          mCDRsFilename;

  void SetUp () override {
    mCDRsFilename = testing::CDRs_FILE_NAME;
    GTEST_SUCCESS_((AnsiString ("makeCDRcsvFile start -> ") + mCDRsFilename).c_str());
    testing::makeCDRcsvFile (mCDRsFilename);
    GTEST_SUCCESS_("makeCDRcsvFile done");
  }
};

TEST_F(RatingTest, ApplyFixedTariff) {
  using namespace std;
  using namespace testing;

  FixedTariff     fixedTariff (0.33);
  CDRs            cdrs = importCDRs (mCDRsFilename, CHECK_SIZE);

  for_each (begin (cdrs), end (cdrs), 
            [fixedTariff] (CDR &x) {
              CDRPtr        cdr = make_shared <CDR> (x);
              BillItemPtr   billItem = fixedTariff.workup (cdr);
              EXPECT_EQ   (billItem->getTotal (), fixedTariff.fee ());
            });
}

TEST_F(RatingTest, ApplyFixedTimedTariff) {
  using namespace std;
  using namespace testing;

  TimedTariff     timedTariff (days (30), minutes (30));
  Account         account = Account::make ("123", 10, now ());
  PhoneNumber     called = PhoneNumber::make ("456");
  Duration        callTime = minutes (10);
  CDRPtr          cdr = make_shared<CDR> (CDR::make (account, called, now (), callTime));
  BillItemPtr     billItem = timedTariff.workup (cdr);

  EXPECT_EQ   (cdr->mDuration, Duration::zero ());
  EXPECT_EQ   (cdr->mAccount.mFreeTimeUsed, callTime);
  EXPECT_EQ   (billItem->mDuration, Duration::zero ());

  cdr->mDuration = minutes (45);
  billItem = timedTariff.workup (cdr);
  EXPECT_EQ   (cdr->mDuration, minutes (15));
  EXPECT_EQ   (cdr->mAccount.mFreeTimeUsed, timedTariff.mPayFreeDuration);
  EXPECT_EQ   (billItem->mDuration, minutes (15));
}


int _tmain(int argc, _TCHAR* argv[])
{
  std::wcout << argv [0] << std::endl;

  testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

