// TDD:
//     Don't write any production code without writing a failing test
//     Don't write any more test code than you need to fail test
//     Don't write any more prod code than needed to pass test
//     Refactor
//     Repeat
// Properties of TDD:
//     +
//         Precise specs
//         tends to lead to more testing
//         regression testing is free
//         outside-in development
//         leads to simpler designs
//         time to write prod code is less
//     -
//         more time consuming
//         tests have to be really good
//         tests can be hard to maintain
// Test strategies:
//     black-box testing - test the desired functionality of code without considering code structure
//         Ex:
//             Date (int y, string m, int d)
//                 valid normal dates
//                 valid abnormal dates
//                 invalid dates
//                 leap year, non-leap years
//                 all valid months
//                 normal, abnormal days per month
//     White-box testing - used to ensure that test suite covers entire program
//         statement coverage
//         loop coverage
//         path coverage
//         ex:
            Date::Date(int y, string m, int d) : d_(d), y_(y) {
                if (invalidYear(y)) {
                    throw ...
                }
                if (invalidMonth(m)) {
                    throw ...
                }
                etc...
                month = Month(m);
            }
//     Boundary Testing - testing inputs that are barely valid, barely invalid, barely within a class of inputs.
//         ex:
//             Feb 29, 1900, 2000, 2100
//         Boundary cases:
//             Off by one values
//             null pointer
//             empty containers
//             containers with one element
//             aliases

Self-testin Objects - assertions that check code assumptions
    pre-conditions are checked
    post-conditions are checked
    invariants
    i.e. has "assers" and other commands.