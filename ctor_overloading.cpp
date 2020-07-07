#include <iostream>

class Area
{
    private:
       int length;
       int breadth;

    public:
       // hic bir arguman olmadan Constructor yaziyoruz
       Area(): length(7), breadth(3) { }

       // iki arguman ile Constructor yeniden yazdik.
       Area(int l, int b): length(l), breadth(b){ } // ayni constructor farkli yada eklenen argumanlarla (ctor overloading)

       void GetLength()
       {
           std::cout << "Enter length and breadth respectively: ";
           std::cin >> length >> breadth;
       }

       int AreaCalculation() {  return length * breadth;  }

       void DisplayArea(int temp)
       {
           std::cout << "Area: " << temp << std::endl;
       }
};


int main()
{
    Area A1, A2(2, 1);
    int temp;

    std::cout << "default alan." << std::endl;
    temp = A1.AreaCalculation();
    A1.DisplayArea(temp);

    std::cout << "(2,1) argumanlari ile yeniden yazilan." << std::endl;
    temp = A2.AreaCalculation();
    A2.DisplayArea(temp);

    return 0;
}

