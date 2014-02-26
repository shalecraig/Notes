// **Singleton Design Pattern** - a class that has exactly one object
// 
// --------------------------------------
// 
/* snip */
// .h file
class Egg{
    // We have a singleton instance that is the single instance of the class.
    static Egg e;
    // we give the class some data
    float volume;
    // Constructor, private by default (so there is only one instance of it)
    Egg(int c);
    // private, unimplemented copy constructor
    Egg (const & Egg);
public:
    // returns a pointer to the egg instance.
    static Egg * instance();
    // get i
    int val();
};

// 
// ------------------------------------------------
// 
/* snip */
// Static member initialization, somewhere in the egg namespace, in the class declaration.
// 
// Initializing a static data member that we have already declared
Egg Egg::e(42);
// 
// ------------------------------------------------
// 
/* snip */
int main() {
    // able to access the egg instance, and to get the value.
    cout << Egg::instance()->val() << endl;
}