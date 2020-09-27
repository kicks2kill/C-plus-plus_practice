#include <cstdlib>

struct B 
{
    virtual void f();
    void mutate();
    virtual ~B();
};

struct D1 : B { void f();};
struct D2 : B {void f();};

void B::mutate()
{
    new (this) D2;
    f();
    ... = this;

}

void g()
{
    void* p = std::malloc(sizeof(D1) + sizeof(D2));
    B* pb = new (p) D1;
    pb->mutate();
    *pb;
    void* q = pb;
    pb->f();
}



int main()
{
    return 0;
}