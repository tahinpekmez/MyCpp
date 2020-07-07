/*
#include <iostream> 
#define NDEBUG     
#include <cassert>
 
using namespace std;
 


void print_number(int* myint) {
  assert(myint!=NULL);
  cout << *myint << endl;
  assert(myint=NULL);
  cout << "\nassertation" << endl;
}

int main ()
{
  int a=20;
  // int d = 19;
  int * b = NULL;
  int * c = NULL; // assert() ile sayimiz NULL pointer yani boş veya sifir olmadikca yazdirilacak.
                  // NULL pointer oldugunda ise assert ile yakalanip kod derlenebilecek.
  b=&a;           // ancak assertation yakalanan yerden sonraki kodlar calistirilmayacak.
 // c=&d;

  print_number (b); // b ve c sirasi yer degistirildi ve assertation yakalanan yerden sonraki komut yani b sayisi ekrana yazdirilamadi.
  print_number (c);

  return 0;
}
*/

#include <iostream>
#define NDEBUG
#include <cassert>
using namespace std;
int main()
{
    assert(2+2==3+1);
    cout << "Expression valid...Execution continues.\n";
    assert(2+2==1+1);
    cout << "Assert disabled...execution continuous with invalid expression\n";
}

// NDEBUG ile assertation uyarisindan sonra da program calisabilecektir.