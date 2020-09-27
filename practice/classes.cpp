class A {
    typedef int I;
    I f();
    friend I g(I);
    static I x;
    template<int> struct Q;
    template<int> friend struct R;
protected:
    struct B {};
};


A::I A::f() {return 0;}
A::I g(A::I p = A::x);
A::I g(A::I p) {return 0;}
A::I A::x = 0; //why would we want to define this way? Just use int A::x = 0...right?
template<A::I> struct A::Q {};
template<A::I> struct R {};

struct D: A::B, A {};
//Believe it or not, all of the uses here are well-formed because A::f, A::x, and A::q are members of class A and g and R are friends of class A.
//This implies that access checking on the first use of A::I must be deferred until it is determined that this use is the return type of a member of class A.


class B {};
template <class T> class C {
protected:
    typedef T TT;
};

template <class U, class V = typename U::TT>
class D : public U {};

D <C<B>>* d; //access error because C::TT is protected ...



class A {};
class B : private A {};
class C : public B {
    A* p; //this causes an error. injected-class-name A is inaccessible
    ::A* q; //this is okay.
}