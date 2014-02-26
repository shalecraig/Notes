// Summary of ADT design decisions (what we need to explicitly choose to do)
// 
// * Legal Values, legal Default value?
// 
// * using the explicit keyword in constructors
// 
// * Accessors, mutators
// 
// * function overloading (for flexible interfaces)
// 
// * operator overloading
// 
// * const parameters, methods
// 
// * member v.s.. non-member methods
// 
// * essential methods (using ours or the compiler's)
// 
// * using a mutattable or immutatable ADT
// 
// * information hiding
// 
// -----------------------------------------------
/* top */
// 
// * We're designing a **money ADT**
// 
// *Requirements:*
// 
// * Must hold place value of up to two decimal places
// 
// * Must hold positive and negative values
// 
// * Must hold the currency
// 
// * Must hold very large values with perfect precision (loss of precision would result in $10^100 + $1 = $10^100)
// 
// Data Representation:
// 
//   * No floats!
// 
//   * Keep an integer value
// 
//   * Possibly an array of digits
// 
// Default Constructor, copy constructor
// 
// * define the constructor:
// 
//   * int -> Money
// 
//   * Rational -> Money
//      
// 
// Explicit:
// 
//   * value: Money -> string
// 
//   * dollars: Money -> String
// 
//   * cent: money -> string
// 
//   * +, -
// 
/* Money ADT */
//   * operator* : Money * Rational
/* nonmember functions/methods: */
// 
//   * Operator >>, Operator<< ==, !=, >, >=, <, <=
// 
//   * Copy constructor, operator=
// 