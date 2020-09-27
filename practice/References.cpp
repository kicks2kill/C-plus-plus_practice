int main()
{
    
    int g(int) noexcept;
    void f(){
        int i;
        int& r = i;
        r = 1;
        int* p = &r;
        int& rr = r; //refers to what x refers to, which is to i
        int (&rg)(int) = g //rg refers to the function g
        rg(i); //call function g
        int a[3];
        int (&ra)[3] = a; //ra refers to the array a
        ra[1] = i;
        

    double d = 2.0;
    double& rd = d;
    const double& rcd = d;

    struct A {};
    struct B : A {operator int&();} b;
    A& ra = b; //ra refers to A which is a subobject in b
    const A& rca = b; //rca refers to A which is a suboject in b
    int& ir = B(); //ir refers to the result of B::operator int&


    struct A {};
    struct B : A {} b;
    extern B f();
    const A& rca2 = f(); //bound to the A suboject of the B rvalue
    A&& rra = f(); //bound to the A subobject of the B rvalue
    struct X {
        operator B();
        operator int&();
    } x;
    const A& r = x; //bound to the A suboject of the result of the conversion
    int i2 = 42;
    int&& rri = static_cast<int&&>(i2); //bound directly to i2
    B&& rrb = x; //bound directly to the result of operator B

}