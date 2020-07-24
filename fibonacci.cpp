#include <iostream>
using namespace std;

int main()
{   
    int t1 {1}; // FIBONACCI ICIN ILK TERIM OLAN "1" SAYISI (t1 INITIALIZATION; YANI t1 ICIN GIRIS DEGERI OLUSTURDUK)
    int t2 {1}; // FIBONACCI ICIN IKINCI TERIM OLAN "1" SAYISI (t2 INITIALIZATION; YANI t1 ICIN GIRIS DEGERI OLUSTURDUK)
    int nxt, N; // "nxt" = BIR SONRAKI TERIM. N = UST SINIR

    cout << "enter a positive numbers as N: ";
    cin >> N;

    cout << "fibonacci series: " << t1 << ", " << t2 << ", "; // BURADA ILK IKI TERIMI BASTIRIYORUZ
    
    // "nxt" OLARAK TANIMLANAN BIR SONRAKI TERIM; "while" 'dan ONCE DE YAZILABILIR.
    // nxt = t1 + t2; // 1, 1, 2 SIRALAMASINDAKI 2' yi OLUSTURDUK; BURADA nxt = 2 OLUR
     
    while (nxt <= N)
    {   
        nxt = t1 + t2;
        cout << nxt << ", "; // BU DONGUDE FIBONACCI SERIYI YAZDIRIYORUZ, YUKARIDA "1, 1, " YANINA BURADAKI "nxt" ile "1, 1, 2, " OLUSTURDUK
        t1 = t2; // ORNEGIN 1 + 2 = 3 OLSUN. ARTIK YENI "t1" BIR SONRAKI TERIM ICIN "t2" YANI BURADAKI "t2 (2)" OLUR 
        t2 = nxt; // SERIMIZ ARTIK ...1, 2, 3, ... OLARAK DEVAM EDECEGINDEN BIR SONRAKI TERIM OLARAK BULDUGUMUZ "nxt (3)" ARTIK "t2" OLUR.  
        nxt = t1 + t2; // BURADA HER ZAMAN YENI TERIM BULMAK ICIN SERIDEKI SON IKI TERIM "t1 + t2" OLARAK TOPLANIR.
    }

return 0;

}