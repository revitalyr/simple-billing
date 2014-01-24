#ifndef Charge_h
  #define Charge_h

  #include "definitions.h"

namespace BS_Billing {

  class Charge
  {
    //types
    private:
    protected:
    public:
    //data
    private:
      MonetaryUnits       mFee;
    protected:
    public:
    //methods
    private:
      //                Charge  ( Charge const & toCpy);
      //Charge  & operator =    ( Charge const & toCpy);
    protected:
                          Charge          ( MonetaryUnits       fee);
    public:
                          ~Charge         ( );

      MonetaryUnits       fee             ( ) const;
  };

  struct FixedCharge 
        : public Charge {
                          FixedCharge     ( MonetaryUnits       fee);
  };

  struct TimedCharge
        : public Charge {
                          TimedCharge     ( MonetaryUnits       fee);

    Duration              payFreeDuring   ( ) const;
    Duration              payFreeDuration ( ) const;
  };

  struct DelayedCharge
        : public Charge {
                          DelayedCharge   ( MonetaryUnits       fee);

    Duration              startsAfter     ( ) const;
  };

  struct HomeCharge
        : public DelayedCharge {
                          HomeCharge      ( MonetaryUnits       fee);
  };

  struct ForeignCharge
        : public DelayedCharge {
                          ForeignCharge   ( MonetaryUnits       fee);
  };

} //namespace BS_Billing

  #ifndef _DEBUG
    #include "Charge.inl"
//    #include "Charge.imp"
  #endif //_DEBUG

#endif  //Charge_h
