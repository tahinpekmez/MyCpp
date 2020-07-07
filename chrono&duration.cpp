#include <iostream>
#include <chrono>
using namespace std;
 
 // chrono cok sayida zaman noktasi saglayan bir kutuphanedir.
 // high_resolution_clock, daha hassas yani en kucuk zaman birimini saglar
int main()
{
	cout << chrono::high_resolution_clock::period::den << endl; // alinacak zaman noktasinin uzunlugunu verir.
	auto start_time = chrono::high_resolution_clock::now();     // den, sahip oldugumuz uzunluk; payda olarak belirlenir
	int temp;
	for (int i = 0; i< 242000000; i++)
		temp+=temp;
	auto end_time = chrono::high_resolution_clock::now(); 
	
    cout 
     << chrono::duration_cast<chrono::seconds>(end_time - start_time).count() // duration_cast ile gecen sure farki alinir. (saniye)
     << ":\n";
	
    cout 
    << chrono::duration_cast<chrono::milliseconds>(end_time - start_time).count() // duration_cast ile gecen sure farki alinir. (milisaniye)
    << ":";
	return 0;
}


/*
#include <iostream>
#include <ctime>
#include <ratio>
#include <chrono>

int main ()
{

  using namespace std::chrono;
  
  high_resolution_clock::time_point t1 = high_resolution_clock::now(); // epoch (baslangic zamani)

  std::cout << "1000 yidizi goster  ...\n";
  for (int i=0; i<1000; ++i) std::cout << "*";
  std::cout << std::endl;

  high_resolution_clock::time_point t2 = high_resolution_clock::now(); // yildizlarin sayiminin bitis noktasi
                                                                         
  duration<double> time_span = duration_cast<duration<double>>(t2 - t1); // duration_cast ile baslangic - bitis farki (milisaniye)

  std::cout << "It took me " << time_span.count() << " seconds."; // 1000 yildizi saymasi ne kadar zaman aldi gosterir 
  std::cout << std::endl;                                         // bir onceki satirda "time_span" kullanarak gecen zamani belirlemis olduk
                                                                  // burada da count ile saydirip ekrana yansiticaz.
  return 0;
}
*/



