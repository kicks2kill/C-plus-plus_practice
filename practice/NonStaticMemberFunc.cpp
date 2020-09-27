int main()
{
    /*
    In the body of the member function tnode::set, the member names tword, count, left and right refer to the members of the object for which the function is called.
        Thus, in the call n1.set... tword refers to n1.tword


    */

    struct tnode {
        char tword[20];
        int count;
        tnode* left;
        tnode* right;
        void set( const char*, tnode* l, tnode* r );
    };
    void tnode::set(const char* w, tnode* l, tnode* r) {
        count = strlen(w) + 1;
        if(sizeof(tword)<=count)
            perror("tnode string too long");
        strcpy(tword, w);
        left = l;
        right = r;
    }

    void f(tnode n1, tnode n2) {
        n1.set("abc", &n2, 0);
        n2.set("def", 0.0);
    }
    
    return 0;
}