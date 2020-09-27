struct C;
void no_opt(C*);

struct C {
    int c;
    C() : c(0) { no_opt(this);}
};

const C cobj;

void no_opt(C* cptr) {
    int i = c.obj.c * 100; //value of cobj.c is unspecified because of the way we're accessing.
    cptr->c = 1;
    cout << cobj.c * 100 < '\n'; //value unspecified
}

extern struct D d;

struct D {
    D(int a) : a(a), b(d.a) {} 
    int a, b;
};
D d = D(1); //value of d.b is unspecified



class X {
public:
    X(int);
    X(const X&);
    X& operator=(const X&);
    ~X();
};

class Y {
public:
    Y(int);
    Y(Y&&);
    ~Y();
};

X f(X);
Y g(Y);

void h() {
    X a(1);
    X b = f(X(2));
    Y c = g(Y(3));
    a = f(a);
}