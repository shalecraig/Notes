// Resource Acquisition is Iniitialization (RAII) - equates resource management with object lifetime
// 
// - resource is allocated in the object's constructor
// 
// - resource is released in the object's destructor
// 
// Smart pointer is an ADT that simulates a pointer, but uses RAII to provide other characteristics.
// 
// auto_ptr<> is a c++ stl templated object that holds an internal pointer.
// 
// 1. It deallocates the referent automatically when the scope exits
// 
// 2. It ensures the single ownership of an object
// 
// 3. It allows ownership to transfer among auto_ptrs
// 
/* code: */
// -----------------------------------------------------------------------
// Auto-pointer interface
template <class X>
class auto_ptr {
public:
    typedef X element_type;
    
    // can initialize to ptr
    explicit auto_ptr(X* p=0) throw ();
    
    // transfers ownership to new auto_ptr
    auto_ptr(auto_ptr&) throw ();
    
    // transfers ownership from one ptr to another.
    auto_ptr& operator= (auto_ptr &) throw ();
    
    // Deallocates memory
    ~auto_ptr() throw();

    // allows deferences of ptr.
    X& operator* () const throw();

    // returns a pointer
    X* operator->() const throw();

    // returns a pointer
    X* get() const throw();

    // returns a pointer, unbind the auto_ptr
    X* release() throw();

    // deallocates referent, resets auot_ptr to new referrent
    void reset(X* p=0) throw();
};

// -----------------------------------------------------------------------

// **Example of smart pointers being used**

// header for the auto_pointers
#include<memory>

int main() {
    // creates an auto_ptr that points to 0/1
    auto_ptr<Rational> ar (new Rational());
    // creates an auto_ptr that points to (another) 0/1
    auot_ptr<Rational> as (new Rational());

    // check that auto_ptr is bound defereence & use referent
    if (ar.get()) {
        cin >> *ar;
    }

    // at holds ptr to referent and is unbound.
    auto_ptr<Rational> at(ar);

    // ar holds ptr to referent, as becomes unbound.
    ar = as;

    // ar's old referent is deallocated
    // 
    // ar holds ptr to new Rational
    ar.reset(new Rational(100));

    // as's referent is deallocated, as is unbound
    as.reset();

    // all deallocations are run.
}

// -------------------------------------------------------------------------
/* snip */

// Exceptions - Best Practices
// 
// 1. Signal all errors as exceptions
// 
// 2. Use RAII to automate cleanup of local resources
// 
// 3. If 1) and 2) are followed religiously then only the code that _handles_ an exception needs to catch it
// 
// **Throwing an exception**
// 
// 1. Constructors - dealloc the value of other parts of the object, if necessary.
// 
// 2. Mutators - first rollback the value of the object to initial value.
// 
// Should not throw exceptions in:
// 
// - destructors
// 
//  - needs to catch any exception thrown by its calls
//  
// - in copy constructor, assignment
// 
// - accessors
// 
// - in value operators (operator== operator*)
// 
// Avouid exception specifications:
// 
// If the exceptions are only thrown at runtime, leave the exceptions out (or in comments).
// It depends on what the compiler can check, but usually don't over-specialize the exception.
// 
//     int foo() throws (exception);
// 
// 
// -------------------------------------------------------------------------
/* snip */

// Header file - set of declarations to be included in any module that uses declared name
// 
// **#include** the header file to include external declarations in module.
// 
// Global Declarations:
// 
// - class declarations
// 
// - void foo(int);
//   - function prototypes
// 
// - extern int i;
//   - variable declarations. (distinguishin declaration from definition)
//   - in this case, extern is used to indicate that it should be exterally visible
// 
// - extern const int j = 100;
//   - global constants
//   - extern used to indicate that the constant is global
// 
// 
// -------------------------------------------------------------------------
/* snip */

// **Benefits of header files**
// 
// - abstract view of component
// 
// - saves work
// 
// - ensures consistency
// 
// - easier maintenance
// 
// -------------------------------------------------------------------------
/* snip */


// **Header Etiquette**
/* snip */
// Checks if preprocessor name has been defined.
// 
// If false, code fragment (until endif) is included in compilation.
// 
// If we didn't include the #ifndef & #def declarations, and we had circular dependencies, we can hit an **infinite loop** in the compiler.
#ifndef X 

// defines existance of preprocessor variable. Refer to infinite loop, above.
#define X

// ends the "#ifndef X"
#endif
