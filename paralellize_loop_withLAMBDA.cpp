#include <vector>
#include <algorithm>
#include <iostream>
 
struct Sum
{
    void operator()(int n) { sum += n; }
    int sum{0};
};
 
int main()
{
    std::vector<int> nums{3, 4, 2, 8, 15, 267};
 
    auto print = [](const int& n) { std::cout << " " << n; }; // LAMBDA IFADESI ILE VEKTOR ELEMANLARI YAZDIRMA FONKSIYONU TEK SATIRDA OLUSTU
 
    std::cout << "before:";
    std::for_each(nums.begin(), nums.end(), print); 
    std::cout << '\n';
 
    std::for_each(nums.begin(), nums.end(), [](int &n){ n++; }); // LAMBDA IFADESI ILE VEKTOR ELEMANLARI 1' er ARTTIRILIR
                                                                 // LAMBDA IFADESI: CAPTURE (BOS) - PARAMETRE - LAMBDA ( "{n++}" ) OLUSUR.
    // Sum::operator() HER NUMARA ICIN CAGIRILIR
    Sum s = std::for_each(nums.begin(), nums.end(), Sum());
 
    std::cout << "after: ";
    std::for_each(nums.begin(), nums.end(), print);
    std::cout << '\n';
    std::cout << "sum: " << s.sum << '\n';
}
