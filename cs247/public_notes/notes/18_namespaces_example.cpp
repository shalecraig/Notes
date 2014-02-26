

// Create a namespace with name *X*
namespace X {
    int i, j, k;
}
// Create an int k inside the global namespace.
int k;

void f() {
    int i=0;
    using namespace X;
    i+=1;
    j+=1;

    // this is undefined behavior in the c++ spec.
    k+=1;

    // Here's a way to reference the k:
    ::k+=1;

    // k in the X namespace
    X::k += 1;
}

void f2() {
    int k=0;
    // This aliases i with X::i (same for j)
    using X::i;
    using X::j;

    // this clashes with the local k - it will not compile because k is ambiguous past this point.
    using X::k;
    /* X::i += 1; */
    i+= 1;
    /* X::j += 1; */
    j+=1; 
    // invalid 
    k+=1;
}

/* snip */
// ------------------------------------------------------------------------------------------------
// We want to protect local names against possible name clashes, so an nunamed name=space is used to declare local (private) methods in functions.
// 
// This autogens a namespace like "*namespace $$-asdfkkl1==*" in the blank namespace - it ensures it won't be callable from the outside.
// 
// Also generates a "*use namespace $$-asdfkkl1==;*" directly after the namespace.
namespace {
    void foo();
}

// **Namespace lookup (resolution) rules:**
// 
// * Local Scope
// 
// * Enclosing scopes (inner -> outer), global namespace is last.
// 
// * Namespaces of all of function's arguments, if failing already.
// 
/* snip */

namespace Chrono {
    class Date {
        ...
    };

    ...
    bool operator ==(const Date&, const std:: string);
    ...
}

void f(Chrono::Date d, std::strings) {
    // This equality operator is resolved towards:
    // Local, then enclosing scopes, then namespaces of the arguments of the function 9i.e. std::string's namespace -> string
    if (d == ...) {

    }
}
