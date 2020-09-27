int x1 {2};

int x2 {2.0}; //error: narrowing

struct S {
    S(std::initalizer_list<double>);
    S(const std::string&);
};

const S& r1 = {1,2,3.0}; //invoke initializer_list
const S& r2 {"spinach"}; //invoke std::string reference
S& r3 = {1,2,3}; //error. Initializer is not an lvalue
const int& i1 = {1}; //okay
const int& i2 = {1.1}; //error narrowing
const int (&iar)[2] = {1,2}; //ok. iar is bound to temp array

int** pp {}; //init to nullptr
