#include <iostream> 
#include <vector>  
using namespace std; 

// buradaki vect referans edilmistir 
void func(vector<int> &vect) 
{ 
vect.push_back(30); // burada yapilan degisiklik disariya da yansir
}                   // int main() icinde yapilan ilk degisiklik ile eklenen sayi buradaki 30 ile birlikte vektorun icine girer 
                    // void fonksiyonu icindeki degisiklik disari yansir.
int main() 
{ 
	vector<int> vect; 
	vect.push_back(10); 
    vect.push_back(20); 

	func(vect); 

	// vect remains unchanged after function 
	// call 
	for (int i=0; i<vect.size(); i++) 
	cout << vect[i] << " "; 

	return 0; 
} 

// OUTPUT: 10 20 30