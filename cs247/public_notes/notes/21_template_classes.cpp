// Friends:

// * Template class has ordinary class/function friend
// 
// * Template class has template class/function friend
// 
// * Template class has instantiated template class/function friend
// 
template<typename X> class D;
template<typename X> class E;
template<typename Type> class A {
    // B friends with all instantiations of A
    friend class B; 

    // every instance of C is a friend of every instance of A:
    template<typename T> friend class C;

    // only D<char> is a friend of instances of class A
    friend class D<char>;

    // only E with the same Type that A is instantiated with is a friend of instances of class A:
    friend class E<Type>;

    template <typename T> class A;
    // output stream 
    template <typename T> ostream& opeartor<< <T> (ostream& const A<T>);
    template <typename T> class A {
        friend ostream& operator<< <T> (ostream& const A<T>);
    };
    template <typename T> ostream& operator<< (ostream &out, const A<T>);
};

