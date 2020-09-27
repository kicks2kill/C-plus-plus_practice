enum BOOL { FALSE=0, TRUE=1};
struct A {
    BOOL b:1;
};
A a;
void f() {
    a.b = TRUE;
    if(a.b == TRUE)
    {} //execute some code
}
