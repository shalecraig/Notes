#include <iostream>

using namespace std;

class Base {
public:
    void aMethod() {cout << "b.amethod" << endl;}
    virtual void bMethod() {cout << "b.bmethod" << endl;}
    virtual void cMethod() {cout << "b.cmethod" << endl;}
};
class Derived : public Base {
public:
    void aMethod() {cout << "d.amethod" << endl;}
    virtual void bMethod() {cout << "d.bmethod" << endl;}
    virtual void dMethod() {cout << "d.dmethod" << endl;}    
private:
    virtual void cMethod() {cout << "d.cmethod" << endl;}  
};
int main (void) {
    Base *b = new Derived();
    // All calls on b use the methods in derived, if they are defined as being
    // virtual in Base. Otherwise, we don't know to call the ones in base, so we
    // call the ones in derived.

    // b.amethod
    b->aMethod(); // (a)

    // d.bmethod
    b->bMethod(); // (b)

    // d.cmethod
    b->cMethod(); // (c)

    // Removed, because base doesn't have a dmethod, it doesn't have a table
    // entry for it.
    // b->dMethod(); // (d)

    Derived d;
    // All calls to d use the methods that are in Derived, but will fall back to
    // Base if necessary.
    // d.amethod
    d.aMethod(); // (e)

    // Removed because it's private in Derived.
    // d.cMethod(); // (f)
    
    // d.dmethod
    d.dMethod(); // (g)

    Base b1 = d;
    // Will call on b's vtable, because b's vtable is what it thinks it's using
    // to look up the contents.

    // b.amethod
    b1.aMethod(); // (h)
    // b.bmethod
    b1.bMethod(); // (i)
    // b.cmethod
    b1.cMethod(); // (j)
}