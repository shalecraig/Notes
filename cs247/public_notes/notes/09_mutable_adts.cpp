// - **Mutable ADT - objects can change value**
// 
// - **Immutable ADT - objects that cannot change value**
// 
// >- int, float, bool, string, AccountNo, Date
// 
// >- can always change the value of a varaible through assignment
// 
// - Mutable ADTs tend to reflect real-world entries
// 
// >- student marks, health record, bank account
// 
// >- may want to disallow copy construction
// 
// -----------------------------------------------
/* snip */
//Rational example:
Rational r; // r is set to: 0/1
Rational s(r); // s is set to: 0/1
cin >> r; // input 10/1
// if Rational is mutable, we have r = 10/1, s = **10**/1
//
// if Rational is immutable: r = 10/1, s = **0**/1
cout << "r= " << r << ", s ="<< s << endl;
/* snip */
// -----------------------------------------------
// 
// Person example (Java example)
// 
Person myperson("Danny O'Leary", new Date(1));
System.out.println(myperson.DOB().toString());
Date mydate = myperson.DOB();
myDate.setMonth(myDate.Month() + 1);
// this call can be problematic if multiple variables share the same mutable object
cout << myperson.DOB(); 
/* snip */
// -----------------------------------------------
// 
// When building an immutable ADT
// 
// 1. data members must be private
// 
// 2. no mutators
// 
// 3. non-essential methods are const
// 
// 4. Accessors return a copy of the requested value, not a reference to the value
// 
// 5. \>\> creator makes a new copy of r
// 
// 6. assignment, copy constructor make deep copies
// 
// 7. data members are immutable, or assign to copies of values
// 
// 
// **Basically, immutable adts cannot be changed**
