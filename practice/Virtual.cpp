struct A {
    virtual void f();
};
struct B : virtual A {
    virtual void f();
};
struct C : B, virtual A {
    using A::f;
};

void foo() {
    C c;
    c.f(); //calls B::f, the final overrider
    c.C::f(); //calls A::f because of the using declaration.
}


struct A { virtual void f();};

struct B : A {};
struct C : A{void f();};
struct D: B, C {}; //okay A::f and C::f are the final overriders for the B and C subojects respectively