#include <iostream>

static void f();
static int i = 0;

void g()
{
    extern void f();
    int i = 2;
    std::cout << i << std::endl;
    {
        extern void f();
        extern int i;
    }
}


int main()
{
    g();
    return 0;
}