
// She likes this naming convention:
double quotient (int numerator, int denominator);
/* Requires: nothing (i.e. is not null/etc) */
/* Modifies: nothing */
/* Ensures: it returns a double equal to the two numbers divided. */
/* Returns: numerator / denominator */
/* Optional: */
    /* Throws: DivideByZero if denominator = 0 */

// ------------------------------------------------------

class Account  {
// Specification fields:
//  AccountNo = account number
//  Balance =  amount money oud.
//  fee = monthly fee
public:
    Account(const AccountNo &a);
    // ensures: initializes to a new account
    //  AccountNo = a
    //  balance = 0;
virtual void print() ;
    //Requires: cout open
    //modifies: cout
    //Ensures: cout = (coun @ pre) + "account" + this.AcctNo + " Balance " + this.Balance;
};

class CheapAccount : public Account {
    // specification fields:
    //  minutes = num minutes called since last bill()
    //  freemin = number of free minutes per calling period.
    //  rate = charge of nonfree calls per minute
public:
    CheapAccount (const AccountNo & a);
    // ensures:
    //  This is initializaed to a new CheapAccount where:
    //      ActNo = a
    //      balance = 0
    //      fee = 300
    //      minutes = 0
    //      freemin = 200
    //      rate = 1
};