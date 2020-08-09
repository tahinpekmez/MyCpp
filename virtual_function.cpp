#include <iostream>
using namespace std;

class A
{
    public:

    virtual void f()
    {
        cout << "class A" << endl;
    }
};

class B: public A
{
    public:
    
    void f() 
    {
        cout << "class B" << endl;
    }
    
};

class C: public B
{
    public:
    void f()
    {
        cout << "class C" << endl;
    }

};


/*
 void g(A& arg)
 {
     arg.f();
 }
*/

// OR

/*
 void g(B& arg)
 {
     arg.f()
 }
*/

int main()
{   
    A a;
    B b;
    C c;
    A* p1 = &b;
    A* p2 = &c;
    A* p3 = &a;
    p1->f(); // RUN TIME POLYMORHISM
    p2->f(); // RUN TIME POLYMORHISM
    p3->f(); // RUN TIME POLYMORHISM
    
    //A x;
    //g(x); // OUTPUT Class A
    
    //B y;
    //g(y); // OUTPUT Class B
    
}
