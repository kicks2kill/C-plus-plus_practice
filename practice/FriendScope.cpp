class X; //forward declared
void a();
void f() {
    class Y;
    extern void b();
    class A {
        friend class X; //this is a local class, not the global ::X
        friend class Y; //okay as well
        friend class Z; //introduce local class Z
        friend void a(); //error because ::a is not considered
        friend void b(); //okay
        friend void c(); //error
    };
    X* px; //ok but ::X is found
    Z* px; //error. no Z is found. //this would need to be f::A::Z* I think?
}


class B {
protected:
    int i;
    static int j;
};

class D1 : public B  {};
class D2 : public B {
    friend void fr(B*, D1*, D2*);
    void mem(B*, D1*);
};

void fr(B* pb, D1* p1, D2* p2) {
    pb->i = 1; //ill-formed.
    p1->i = 2; //ill-formed.

    p2->i = 3; //ok (access through a D2)
    p2->B::i = 4; //ok. access through a D2 even though naming class is B... just a reminder that you can use base pointers in a derived class.
    
    int B::* pmi_B = &B::i; //ill-formed.
    int B::* pmi_b2 = &D2::i; //this is ok. type of &D2::i is int B::*
    B::j = 5; //ill-formed. not a friend of naming class B
    D2::j = 6; //ok because refers to static member
}

void D2::mem(B* pb, D1* p1) {
    pb->i = 1; // ill-formed
    p1->i = 2; // ill-formed
    i = 3; // OK (access through this)
    B::i = 4; // OK (access through this, qualification ignored)
    int B::* pmi_B = &B::i; // ill-formed
    int B::* pmi_B2 = &D2::i; // OK
    j = 5; // OK (because j refers to static member)
    B::j = 6; // OK (because B::j refers to static member)
}


void g(B* pb, D1* p1, D2* p2) {
    pb->i = 1;
    p1->i = 2;
    p2->i = 3; //all three of these are ill-formed.
}