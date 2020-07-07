 
#include <stdio.h> 
int main() 
{ 
	int x = 10; 

    const int *ptr; 

   // & operator give the address of value
   // *ptr give the value that is stored at address
	ptr = &x; 
  
  printf("\nvalue at stored address: %d ", *ptr);
  printf("\naddress: %p ",&x );
   printf("\naddress: %p ", ptr);

	return 0; 
}
