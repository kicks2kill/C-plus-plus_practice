int main()
{
    struct T1{ int a, b;};
    struct T2 {int c; double d;};
    union U { T1 t1; T2 t2;};
    int f() {
        U u = { { 1, 2} }; //using struct T1 object
        return u.t2.c; //okay as long as u.t1.a were nominated
    }
    

    struct X {
        typedef int T;
        static T count;
        void f(T);
    };
    void X::f(T t = count) {}
    
    typedef void fv();
    typedef void fvc() const;

    struct S {
        fv memfunc1; //style choice. Can be void memfunc1()
        void memfunc2();
        fvc memfunc3; //style choice again, can be void memfunc3()
    };
    fv S::* pmfv1 = &S::mefunc1;
    fv S::* pmfv2 = &S::memfunc2;
    fvc S::* pmfv3 = &S::memfunc3;
    
    
    
    
    return 0;

}