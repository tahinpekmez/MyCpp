#include <iostream>

class Abstract
{
    protected:
    int a, b;

    public:

    // If we have no default constructor for initializing, the Swap() call would produce garbage value
    // and the compiler provdes an inline constructor.
    Abstract (int num1, int num2) : a(num1), b(num2) {} //DEFAULT CONSTRUCTOR FOR INITIALIZING 

    public:
    virtual void swap() = 0; // PURE VIRTUAL FUNCTION

    void print_swap()
    {
        this->swap();
    }
};

class Swap : public Abstract
{
    public:
    Swap(int num1, int num2) : Abstract(num1,num2) {}

    void swap()
    {
        std::cout << "before swapping." << "\n";
        std::cout << "a: " << a << ", b: " << b << "\n";
        
        a = a+b;
        b = a-b;
        a = a-b;

        std::cout << "after swapping." << "\n";
        std::cout << "a: " << a << ", b: " << b << "\n";

    }

};

int main()
{
    // ALLOCATING 2 and 3 TO DEMONSTRATE DYNAMIC MEMORY ALLOCATION 
    Abstract *a = new Swap(2,3); 
    a->print_swap();
    
    delete a; // DELETE ALLOCATING

    return 0;
}
  
