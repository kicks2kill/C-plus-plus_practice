int main()
{
    int a = {1};
    std::complex<double> z{1,2};
    new std::vector<std::string>{"once", "upon", "a", "time"};
    f({"Nicholas", "Annemarie"}); //pass list of two elements
    return { "Norah "}; //return list of one element
    int* e {}; //init to zero /nullptr
    x = double{1}; //explicitly construct a double
    std::map<std::string, int> anim = { {"bear, 4"}, {"cassowary", 2}, {"tiger", 7} } 
    return 0;

    double ad[] = {1, 2.0};
    int ai[] = {1, 2.0}; //error: narrowing

    struct S2 {
        int m1,
        double m2, m3;
    };

    S2 s21 = {1,2,3.0}; //okay
    S2 s22 {1.0,2,3}; //error: narrowing
    S2 s23 {}; //zeroed out
}