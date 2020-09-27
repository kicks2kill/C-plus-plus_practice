#include <iostream>

template <class T> struct B {
    void g(T) {}
    void h(T);
    friend void i(B, T) {}
};

void f() {
    struct A {int x;};
    A a = { 1 };
    B<A> ba; //declares B<A>::g(A) and B<A>::h(A)
    ba.g(a);
    ba.h(a); //error because B<A>::h(A) is not defined in the translation unit
    i(ba, a);
}
/*
Two names that are the same and that are declared in different scopes shall denote the same variable, function, type, template or namespace if:
    -both have external linkage or else both names have internal linkage and are declared in the same translation unit and
    -both names refer to members of the same namespace or to members, not by inheritance, of the same class and 
    - when both names denote functions, the parameter-type lists of the functions are identical and
    -when both names denote function templates, the signatures are the same.

*/

int main()
{
    return 0;
}