// RationalExeption.cpp
//------------------------------------
Rational operator* (const Rational &r, const Rational &s) {
    long numer = (long)r.numerator()   * (long) s.numerator();
    long denom = (long)r.denominator() * (long)s.denominator();
    try {
        // are watching for an overflow exception... this is a stupid example to show how try/catches work...
        if (numer <= INT_MAX && denom <= INT_MAX) {
            return Rational(numer, denom);
        } else {
            throw 0;
        }
    } catch (int) {
        long n = (numer> INT_MAX)  ? INT_MAX : numer;
        long d = (denom > INT_MAX) ? INT_MAX : denom;
        return Rational((int) n, (int) d);
    }
}

//------------------------------------
// RationalExeption.cpp
//------------------------------------

Rational::Rational(int num, int denom): _n(1), _d(1) {
    if (denom == 0) {
        // We throw an exception
        // 
        // 1. Exception object is constructed
        // 
        // 1. We pass it to the nearest exception handler, which matches on the exception thrown.
        // 
        // 1. We may exit a number of functions in the call chain.
        // 
        // 1. Local stack-based objects of exited functions are properly destroyed.
        throw DivideByZeroException(num);
    }
    /* ... */
}

//------------------------------------
// **Example of this being used**

int main() {
    Rational r(1, 2);
    try {
        cout << "Enter rational number (a/b). " << endl;
        cin >> r;
    } catch (DivideByZeroException &e) {
        cout << e.numer() << "Rational numbers cannot have 0 in the denominator, doofus."<< endl;
    }
}

//------------------------------------
//
//  **Throwing exception types**

class X {
    class Trouble{};
    class Big: public Trouble{};
    class Small: public Trouble {};
    void f {throw Big();}
};

int main() {
    X x;
    try {
        x.f(); //will throw exception
    } catch (X::Small &) {
        cout << "Small Trouble" << endl;
    } catch (X::Trouble &) {
        // This exception will be the one triggered, because the error thrown (Big) is a child of Trouble, and it is the first caught type that matches.
        cout << "Trouble" << endl;
    } catch (X::Big &) {
        cout << "Big Trouble" << endl;
        // This is a catch-all
    } catch (...) {
        cout << "catches any exception" << endl;
        // Re-throws the same exception.
        throw;
    }
}

// -----------------------------------
// Exception specifications:
// -----------------------------------------------------------------------------------
class foo{
    // Explicitly declares it can only throw a DivideByZero exception, or an OverFlow Exception
    // 
    // Errors not specified in the list generate runtime errors
    double safeDivide (int n, int d) throw (DivideByZero, OverFlow);
    // no specification for exceptions -> no limitations of what it can throw.
    void f();
    // This promises that no exceptions will be thrown.
    void g() throw()
};

// -----------------------------------
// **Standard/predefined exceptions**
// -----------------------------------

// This code needs a *#include &lt;stdexcept&gt;*
class runtime_error: public exception {
public:
    explicit runtime_error (const string& what_arg);
    // inherits virtual const char* what() const throw();
};

// When unwinding the stack:
// 
// - objects on the stack are deallocated automatically invoking the appropriate destructor
// 
// - partially constructed objects will also be properly destroyed (but not using their destructors)
// 
// What about dynamically allocated objects?
// 
// Solution: **RAII**
// 
// Resource allocation is Initialization idiom:
// 
// equates resource management as object lifetime
/* snip */
//
class Resource {
    resource_type * r_;
//  construction
    resource_type* acquire (parms p);
//  destruction
    void release (resource_type *);
public:
    // Calls acquire(p)
    Resource(parms p) : r_ (acquire(p));
    // Calls release(p)
    ~Resource() {release(r_);}
    // sometimes prevent copy assignment when using this.
};

// ----------------------------------
// 
// 
#include <stdio>
#include <stdexcept>
class file {
    std::FILE file_;
    file (const file&) ;
    file & operator= (const file&);
public:
    file(const char* name) : file_(std::fopen(name, "w+")) {
        /* Check if open was successful. */
    }
}