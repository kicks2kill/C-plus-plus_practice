struct A {}; //A::operator= is implicitly declared
struct B : A {
    B& operator=(const B &);
};

B& B::operator=(const B& s) {
    this->A::operator=(s);
    return *this;
}