// **Handle Classes**
// 
// * You can do pointer arithmetic to access private variables - this is bad.
// 
// * Also, changing the .h files requires a complete re-compile of all code that derives from this.
// 
// * To prevent this, we have a handle-class instead of doing what we said in [Adt design #06](./06_adt_design.html)
// 
// * This is called a PIMPL (**P**ointer to **IMPL**ementation idiom): We basically have a class that has a pointer to the Implementation Class (which contains the implementation).

// --------------------------------

// ***Rational.h file***
class Rational {
public:
    Rational(int num: 0, int denom: 1);
    int numerator() const;
    int denominator() const;
private:
    struct impl;
    // This is a PIMPL
    impl *rat_;
public:
    
    //delete
    ~Rational();

    // copy
    Rational(const &Rational);

     // assignment
    Rational& operator=(const Rational);
};

// --------------------------------

// ***Rational.cpp file***
// 
// We create a struct named Rational::Impl.
// 
// This allows us to modify the data members, and not have to worry about re-compiling everything.
struct Rational::Impl {
    int num_;
    int denom_;
};

// Rational's constructor:
Rational::Rational(int num, int denom): rat_(new Rational::Impl) {

    // We have a single colon in method because we are using an initialization list.
    // This sets the values to what are in the brackets, basically allowing us to initialize the variables once.
    // If we had the same code inside the method, the compiler would set the value to 0, then change it when we set it (stupidly)
    if (denom == 0) throw "Panic!";
    rat_->num_ = num;
    rat_->denom_ = denom;
}

// Destructor
Rational::~Rational() {
    // This deallocates rat
    delete _rat;
}

// Initialization example (deep)
Rational::Rational(const Rational& r) {
    // copies the values of num_ and denom_ from the other rational.
    *rat_ = *(r.rat_);
}

// Copy example (deep);
Rational& operator=(const Rational& r) {
    // Running a = a fails if we remove this line (we delete left side before copying the right side)
    if (&r == this) {
        return *this;
    }
    delete rat_;
    // Copy the values inside r.rat_, don't reference them. If this was a shallow copy, we would run this instead:
    //            rat_ = r.rat_
    rat_ = new Rational::Impl(*r.rat_);
    return *this;
}

// ---------------------------------
// random code for code snippets:
int main() {
    // initialized as 0/1
    Rational r;

    // initialized as 0/1
    Rational s(r);

    //change the value of r
    cin >> r;

    // If s(r) is a *shallow* copy, we would output r = 10/1, s = 10/1.
    // If s(r) is a *deep* copy, we would output r = 10/1, s = 0/1
    cout << "r= " << r << ", s= ", << s;
}