class AccountNo;
class Account {
    public:
        Account(const AccountNo&);
    private:
        AccountNo no_;
        // if any of the data members are sub-objects, the compiler will automatically use the data member's default constructor, if they don't set it with a colon, before the curly bracket. (just like the Rational number)
};
// bad version, without the initialization
Account(const AccountNo & no) {
    no_ = no;
}

// We initialize the account number here explicitly, without using the default constructor.
Account(const AccountNo & no) : no_(no) {
    // We show the compiler how to create it right the first time on the line above this one, so the code isn't run twice (i.e. the bad example).
    /*
    no = _no; 
    */
}