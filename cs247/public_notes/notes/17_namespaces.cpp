// Namespace pollution is a problem.
// 
// It causes clashes among global names in a large multimodule program.
// 
// Analogy: telephone codes:
//  (country code)(area code)(number)(extensions)
// 
// namespace - used to package related definitions in a commonly named scope
// 
namespace Lib1 {
    void f();
}

namespace Lib2 {
    void f();
    void g() {
        // calls Lib2's method (not Lib1's method)
        f();
    }
    void h() {
        // Qualifies the namespace of the method you are calling
        // -> calls Lib1's Method
        Lib1::f();
    }
}
/* snip */
// Can re-open the namespace in other files. Ex:

/* new file */
// ----------------------------------------
namespace Lib1 {
    // new method defined in the file.
    herpDerpMcGurp();
}

/* snip */
namespace RatADT {
    class Rational {
    // Usually, we would write this to call these methods:
    // 
    //      RatADT::Rational::Rational(...) {...}
    //      RatADT::Rational RatADT::operator+(...) {...}

    public:
        Rational(int num_0, int denom=1);
    };

    Rational operator+ (const Rational & const Rational &);
}

/* snip */
// Referenceing namespace members:
// 
// * Using declarations will add Rational to the visible namespace
// 
//          Using RatADT::Rational;
//        
// * Makes Rational visible or a name in current scope
// * Will clash with local names
// * Using directive:
// 
//          Using namespace RatADT;
//        
//  * Makes namespace member visible as if they had been declared outside their namespace.
//  * Local declarations supersede them
//  * Can have ambiguous names if member of multiple namespaces are made visible with using directives
/* snip */
// Note on etiquette:
// 
// **don't use "using":**
// 
// * inisde a header
// 
//      * it will be included for everything *importing* the header, making the namespace basically global. Stuff will break.
//      
// * before an #include directive:
// 
//      * It will mess up the namespaces of the included files.