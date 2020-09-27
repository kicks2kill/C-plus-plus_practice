#include <iostream>
using namespace std;

template<typename iter, typename Val>
Val sum(iter first, iter last)
{
    Val s = 0;
    while(first!=last)
    {
        s = s + *first;
        ++first;
    }
    return s;
}

template<typename iter, typename Val>
Val accumulate(iter first, iter last, Val s)
{
    while(first != last)
    {
        s = s + *first;
        ++first;
    }
    return s;
}

template<typename Iter, typename Val, typename Oper>
Val accumulate( Iter first, Iter last, Val s, Oper op)
{
    while(first != last)
    {
        s = op(s, *first);
        ++first;
    }
    return s;
}


double ad[] = {1,2,3,4};
double s1 = accumulate(ad, ad+4,0.0);
double s2 = accumulate(ad, ad +4,0);



double s = sum<double*, double>(ad, ad+4);
struct Node { Node* next; int data;};
struct Node_iter { Node* pos;};

Node_iter operator++(Node_iter& p) {return p.pos =p.pos-> next;}
int operator*(Node_iter p) {return p.pos->data;}
bool operator!=(Node_iter p, Node_iter q) {return p.pos != q.pos;}

void test(Node* lst)
{
    int s = sum<Node_iter,int>(lst,nullptr); //use the nullptr as end operator and an explicit template argument list to allow caller to specify the type for accumulator variable
}



int main()
{
    return 0;
}