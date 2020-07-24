#include <iostream>
using namespace std;

class Abstract
{
    public:
    virtual void f() = 0; // PURE VIRTUAL FUNCTION
    //{
       // cout << "class Abstract" << endl;
    //}
};

class B: public Abstract
{
    public:
    void f()
    {
        cout << "class B" << endl;
    }
};

//------------------------
//void v(Abstract& arg)
//{
    //arg.f();
//}
//-----------------------

int main()
{
    
    //B b;
    //v(b);
    
 // Abstract obj; // compile error.
    Abstract *obj;
    B b;
    obj = &b;
    obj->f();

    
    
}
