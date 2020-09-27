class point {};
class shape {
    point center;
public:
    point where() { return center;}
    void move(point p) { center=p; draw();}
    virtual void rotate(int) = 0;
    virtual void draw() = 0;
};

shape x; //error: object of abstract class
shape* p; //ok
shape f(); //error
void g(shape); //error
shape& h(shape&); //ok

//an abstract class shall not be used as a parameter type, as a function return type, or as the type of an explicit conversion. Pointers and references to an abstract class can be declared.

class ab_circle : public shape {
    int radius;
public:
    void rotate(int) {}
    //ab_circle::draw() ... this is a pure virtual .. we would need to have a defintion like void draw();
};


