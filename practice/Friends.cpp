//Demonstrate that a friend of a class is a function or class that is given permission to use the private and protected member names from the class.
//a class specifies its friends, if any, by way of friend declarations. They give special access rights, but do not make the nominated friend members of the befriending class
//look below for the differente between members and friends.

class X {
    int a;
    friend void friend_set(X*, int);
public:
    void member_set(int);
};

void friend_set(X* p, int i) {p->a = i;}
void X::member_set(int i) { a = i;}

void f() {
    X obj;
    friend_set(&obj, 10);
    obj.member_set(10);
}






class A {
    class B {};
    friend class X;
};

struct X : A::B {
    A::B mx;
    class Y {
        A::B my;
    };
};

class X {
    enum {a=100};
    friend class Y;
};

class Y {
    int v[X::a]; //Y is a friend of X
};

class Z {
    int v[x::a]; //error X::a is private
};





class C;
typedef C Ct;

class X1 {
    friend C; //class C is a friend
};

class X2 {
    friend Ct; //class C is a friend
    friend D; //error no type-name D in scope
    friend class D; //ok bc elaborated type specifier declares new class
};

template <typename T> class R {
    friend T;
};

R<C> rc; //class C is a friend of R<C>
R<int> Ri; //ok: friend int is ignored




class Y {
    friend char* X::foo(int);
    friend X::X(char); //constructor can be friends
    friend X::~X(); //destructor can be friends
};