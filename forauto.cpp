#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // 10 elemanli basit bir dizi olsun.
    int x[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    //diziye iterasyon islemi yapmak icin Range-based for loop kullanacagiz .
    for( int y : x ) { // x dizisindeki her eleman icin bir kopya y icin olusur
                       // tercih edilmez. cunku pahali bir yontemdir. dizideki her eleman "y" icin kopyalanir 
        cout << y << " ";
    }
    cout << endl;

    // auto ile otomatik olarak dizinin donus tipi algilanir

    for( auto y : x ) { // yine x icindeki her eleman y icin kopyalanir
        cout << y << " ";
    }
    cout << endl;

    for( auto &y : x ) { // y, burada x dizisi icin referans edilir ve kopyalama isleminden kurtulmus oluruz
                        //  kopya elemanlar yerine orjinal elemanlari y icin yazdirmis oluruz.
        cout << y << " ";
    }
    cout << endl;

    for( const auto &y : x ) { // eger sonradan bir modifikasyon olamayacaksa const yani sabit referans kullanilabilir.
        cout << y << " ";
    }
    cout << endl;
    cout << "array iterasyon bitimi" << endl;
    cout << endl;

    // 10 elemani olacak bir vektor nesnesi olusturalim
    vector<double> v;
    for (int i = 0; i < 10; ++i) {
        v.emplace_back(i + 0.14159); // emplace_back ile eklenen arguman dogrudan vektor icinde olusturuldu
    }                                // push_back ile once eklenecek arguman olusturulup sonra kopyasi vektor icine tasiniyordu
             
    // range-based loop ile vetorumuzu iterasyon islemine aliyoruz
    for( const auto &j : v ) { //sabit referans ile sonradan degismeyecek ve orjinal elemanlar ile itere edilmiş vektor elemanlari yazdirilacak
        cout << j << " ";
    }
    cout << endl;
    cout << "vektor iterasyon bitimi" << endl;
}