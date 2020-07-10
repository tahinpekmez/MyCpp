#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <random>
#include <cmath>
int main()
{
    
    // elimizdeki bir uygulama icin belirleyici bir kaynak (ornegin bir donanım) yoksa
    // ayni rastgele sayilari ureten bir olusturucu (generator) olarak kullanilabilir.
    std::random_device rd{};
    
    // mersenne_twister_engine = yuksek hassasiyette UIntType tipinde isaretsiz random sayilar saglar.
    std::mt19937 gen{rd()};
 
    /*
    5 noktasinda 2 standart sapma degeriyle gauss dagilimi olusturulmustur
    */
    std::normal_distribution<> d{5,2};
 
    std::map<int, int> gauss{};
    for(int n=0; n<10000; ++n) {
        ++gauss[std::round(d(gen))];
    }
    for(auto & p : gauss) {
        std::cout << std::setw(2)
                  << p.first << ' ' << std::string(p.second/200, '*') << '\n';
    }
}
