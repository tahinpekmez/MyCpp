// GAUSS DAGILIMI (NORMAL DISTRIBUTION)
#include <iostream>
#include <string>
#include <random>

int main()
{
  const int nrolls=10000;  // DENEK SAYISI
  const int nstars=100;    // DAGILIM YAPILACAK MAX YILDIZ SAYISI

  std::default_random_engine generator; // PSEUDO RASTGELE NUMARALAR OLUSTURAN BİR SINIF
  std::normal_distribution<double> distribution(5.0,2.0); 

  int p[10]={}; // 10 ELEMANLI BİR DIZI INITIALIZATION

  for (int i=0; i<nrolls; ++i) {
    double number = distribution(generator); 
    if ((number>=0.0)&&(number<10.0)) ++p[int(number)];
  }

  std::cout << "normal_distribution (5.0,2.0):" << std::endl;

  for (int i=0; i<10; ++i) {
    std::cout << i << "-" << (i+1) << ": "; // 0-1: , 2-3:, 7-8:, vb. CIKIS VERIR
    std::cout << std::string(p[i]*nstars/nrolls,'*') << std::endl;
  }

  return 0;
}