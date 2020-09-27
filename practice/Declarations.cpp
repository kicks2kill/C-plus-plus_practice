#include <iostream>
/*

*/

class C {};
void f(int(C)) { } //void f(int(*fp)(C c)) {}
                    //not void f(int C) {}
int g(C);

void foo()
{
    f(1);
    f(g);
}

void h(int *(C[10])); //void h(int *(*_fp)(C_parm[10]))
                      // not void h(int *C[10])


int main()
{
    return 0;
}