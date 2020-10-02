#include <iostream>

class Base
{
	protected:
	int x, y;
	
    public:
    Base (int no1, int no2) : x(no1), y(no2) {} // default constructor
    
    // virtual function
	virtual void swapping() {} 

    void print_swapping()
    {
        this->swapping();
    }

    // we have used virtual Base destructor therefore, object of derived class(class Swap) is destructed properly
    virtual ~Base()
    {
        std::cout << "Destructed Base!";
    }
};


// inheriance from Base to Swap
class Swap : public Base
{
    public:

    Swap(int no1, int no2) : Base(no1, no2){}

    void swapping()
    {
        std::cout << "without swapping: " << "\n";
		std::cout << "x: " << x << " y: " << y << "\n";

	    x=x+y;
		y=x-y;
		x=x-y;

		std::cout << "swapping x: " << x << " swapping y: " << y << "\n"; 

    }
    
    // virtual Swap destructor
    ~Swap()
    {
        std::cout << "Destructed Swap!" << "\n";
    }
};

int main()
{
    Base *i = new Swap(5,15);
    i->print_swapping(); // Run-Time Polymorphism because, we have used virtual function.
    
    delete i;
}

