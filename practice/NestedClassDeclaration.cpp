int x;
int y;
struct enclose {
    int x;
    static int s;

    struct inner {
        void f(int i) {
            int a = sizeof(x); //operand of sizeof is an unevaluated operand
            x = i; //error. assign to enclose::x
            s = i; //ok to assign to enclose::s
            ::x = i; //okay to assign to global x
            y = i;
        }
        void g(enclose* p, int i) {
            p->x = i; //ok to assign to enclose::x
        }
    }
}

inner* p = 0; //inner not in scope
