// **Design of ADTs:**
// 
// *   Legal Values
// 
// *   Public Interface
// 
// *   Essential Methods
// 
// *   Information Hiding
// 
//   - Data members are private
//   
//   - Desired classes can access data through public/protected methods.
//   
//   - Non-Member functions can only access data through public methods or are friends.
// 
// *   Helper methods
//   
//   - (i.e. int.tofloat, etc).
//   
//   - Protected with namespaces, or as private members if appropriate.
// ------------------------------------------------
/* snip */

// Usually, this in the header file for some class of code:
class Rational {

        // Can be called from anywhere.
    public:
        // Default values of the numerator and denom are 0 and 1;
        Rational (int num: 0, int denom : 1);

        // Accessors
        int numerator() const;
        int denominator() const;

        // Private can only be read from this class
    private:
        int num_;
        int denom_;

        // Child classes can read and access.
    protected:
        void numeratorIs(int newNum);

        // being a friend gives explicit permission to the entire class, or to specific functions in the class to other files.
        // Non-member functions are all outside the class declaration.
        // Friends have access to private (not just protected)
    friend Complex;
    friend Complex Complex:: operator++(const Complex & ) const;
        // The method below is allowed to modfiy all variables and call all methods.
    friend istream& operator>> (istream& si, Rational &);
};

istream& operator>> (istream & sin, Rational& r) {
    char slash;
    // We're going to read from *sin* to create the rational object. We can access num_ because we're a friend.
    sin >> r.num_ >> slash >> r.denom_;
    // We return the istream (the rational was a reference, and was modified that way);
    return sin;
}