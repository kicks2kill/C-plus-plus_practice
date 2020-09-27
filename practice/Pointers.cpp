#include <iostream>

const int ci = 10, *pc = &ci, *const cpc = pc, **ppc; //define a const int, a pointer to const int, a const pointer to a const value, and a pointer to a pointer to a const int
int i, *p, *const cp = &i; //define an int, a pointer to int, a const pointer to int

struct link {
    link* next;
};

link* first;

void h(link*& p) //declares p to be a reference to a pointer to link...so h(q) will leave q with the value zero
{
    p-> next = first;
    first = p;
    p = 0;
}

void k() 
{
    link* q = new link;
    h(q);
}




struct X {
    void f(int);
    int a;
};

struct Y;

int X::* pmi = &X::a; //declares pmi, pmf, pmd and pmc to be a pointer to a member of X of type int, one of void and a pointer to a member of Y of type char
void (X::* pmf)(int) = &X::f;
double X::* pmd;
char Y::* pmc; //Although Y is an incomplete type, pmi and pmf can be used like this:
/*
X obj;

obj.*pmi = 7;  assign 7 to an int num of obj
(obj.*pmf)(7)  call a function member of obj with argument 7


*/



int main()
{
    return 0;
}