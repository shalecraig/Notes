// **Error Handling**
// 
// In general, about 50% of your code could be handling errors.
// 
// Why is this bad?
// 
// - 50% of the code will be error handling
// 
// - it will be hard to see what the code is doing.
// 
// Exceptions can be triggered by unusual condition or situation that precludes a function from completing normally
// 
// 
ifstream infile;
infile.open("data");
if (!infile.good()) {
    /* error handling */
    cout << "Error opening file " << endl;
    exit();
}
while (!infile.eof() ) {
    string name;
    infile >> name;
    if (infile.bad()) {
        /* error handling */
    } else if (infile.fail()) {
        /* error handling */
    } else {
        /* process data */
    }
}

//--------------------------------------------------------
/*snip*/
// Suggested - try-catch block:
// 
// Exception handling:
// 
// - separates error-handling code from "normal" code
// 
// - separates risky from nonrisky code
// 
// - exceptions cannot be ignored
/* risk-free code */
try {
    /* code that can throw exceptions */
} catch (exceptType1 &e1) {
    /* error handling */
} catch (exceptType2 &e2) {
    /* error handling */
}
/* risk-free code */


//--------------------------------------------------------
/*snip*/
Rational:: Rational(int num, int denom) {
    if (denom == 0) {
        // in C++, we can throw integers, strings, or objects
        /* throw 0; */
        /* throw "Wrong"; */
        /* throw DivideByZeroException(); */
        throw 0;
    }
}

//--------------------------------------------------------
/*snip*/
// **Creating error objects**
class Rational {
    /* code for the Rational class */

    // Error object
    class DivideByZeroException {
        int num;
    public:
        DivideByZeroException(int num) : num_(num) {}
        int num() {
            return num_;
        }
    };
    /*...*/
    public Rational(int num=0, int denom = 1);
    /*...*/
};
// 