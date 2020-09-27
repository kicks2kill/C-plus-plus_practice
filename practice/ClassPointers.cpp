class B {
public:
    int mi; //non-static
    static int si; //static obv

};
class D : private B {};
class DD : public D {
    void f();
};

void DD:f() {
    mi = 3; //error: private in D
    si = 3; //error private in D
    ::B b;
    b.mi = 3; //ok because b.mi is different from this->mi
    b.si = 3; //ok. because b.si is different from this->si
    ::B::si = 3; //also okay
    ::B* bp1 = this; //error because B is a private base class
    ::B* bp2 = (::B*)this; //ok because of cast
    bp2->mi = 3; //ok: access through a pointer to B
}

/*

Note that a member of a private base class might be inaccessible as an inherited member name, but accessible directly.
B/c of rules on pointer conversions and explicit casts, a conversion from a pointer to a derived class to a pointer to an inaccessible base class might be ill-formed if an implicit conversion is used....
but well-formed if an explicit cast is used. Look above.
 We cam also the friend keyword to make the protected data available through derived classes. Look below.
*/

class B {
public:
    int m;
};

class S : private B {
    friend class N;
};

class N: private S {
    void f() {
        B* p = this; // This is ok. B is a base class of N, accessible in f() because B is accessible base class of S and s is an accessible base class of N
    }
};




//If a base class is accessible, one can implicitly convert a pointer to a derived class to a pointer to that base class.
//the access to a member is affected by the class in which the member is named. example below

class B;
class A {
private:
    int i;
    friend void f(B*);
};
class B : public A {};
void f(B* p) {
    p->i = 1; //ok. because B* can be implicitly converted to A* and f has access to i in A
}