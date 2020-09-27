
struct C 
{
    int i;
    void f();
    const C& operator= (const C&);
};

const C& C::operator=(const C& other)
{
    if (this != &other)
    {
        this->~C(); //lifetime of *this ends
        new (this) C(other); //new object of type C created
        f(); //well-defined
    }
    return *this;
}


class T {};

struct B 
{
    ~B();
};


void h()
{
    B b;
    new (&b) T;
} //undefined behavior at block exit


int main()
{
    C c1;
    C c2;
    c1 = c2; //well-defined
    c1.f(); //well-defined. c1 refers to a new object of type C
    return 0;
}



