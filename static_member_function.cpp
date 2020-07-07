#include <iostream> 

class Street
{
    static int numberOfHouses;
public:
    static void addHouse()
    {
        numberOfHouses++;
    }
    void incrementHouse()
    {
        numberOfHouses++;
    }


};
class House
{
public:
    House()
    {
        Street::addHouse();
        //Street sinifi icin yeni bir obje yaratmayacagiz
        Street s;
        s.incrementHouse();
    }   //Street sinifi icin fazladan obje olusturulacaksa memory allocation olmak zorundadir

};