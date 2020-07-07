#include <stdio.h> 
#include <stdlib.h> 

int main()  
{           
    
	int* ptr; 
	int n, i; 
 
	n = 5; 
	printf("eleman sayisini giriniz: %d\n", n); 
 
	ptr = (int*)malloc(n*sizeof(int));    // malloc(arg) tek arguman alir. malloc tum veri boyutunu tek bir hafiza blogunda saklar
                                            // malloc intialize edilemez. Tum datanin toplam veri boyutu kadar tek bir hafiza blogu olusur
	if (ptr == NULL) {                      
		printf("memory allocation yoktur.\n");  // eger NULL pointer varsa yani eleman sayisi sifir ise memory allocation olmayacak
		exit(0); 
	} 
	else { 

        // memory allocation islemi basarili mi degil mi kontrol ediliyor.	
		printf("malloc ile memory allocation basarili bir sekilde gerceklesti.\n"); 
 
		for (i = 0; i < n; ++i) { 
			ptr[i] = i + 1; 
		} 
 
		printf("dizinin elemanlari: \n"); 
		for (i = 0; i < n; ++i) { 
			printf("%d, ", ptr[i]);        
		} 

            free (ptr); 
            printf("\nmalloc memory say that freedom"); 
	} 

	return 0; 
} 

// CONNTIGIOUS ALLOCATION (calloc)
/*****************************************************
#include <stdio.h> 
#include <stdlib.h> 

int main()  
{           
    
	int* ptr; 
	int n, i; 
 
	n = 5; 
	printf("eleman sayisini giriniz: %d\n", n); 
 
	ptr = (int*)calloc(n, sizeof(int));    // calloc(arg) iki arguman alir. 
                                           // calloc intialize edilebilir. 
	                                       // calloc, tum datayi bloklara ayirarak hafizada tutar
	if (ptr == NULL) {                     
		printf("memory allocation yoktur.\n");  // eger NULL pointer varsa yani eleman sayisi sifir ise memory allocation olmayacak
		exit(0); 
	} 
	else { 

        // memory allocation islemi basarili mi degil mi kontrol ediliyor.	
		printf("calloc ile memory allocation basarili bir sekilde gerceklesti.\n"); 
 
		for (i = 0; i < n; ++i) { 
			ptr[i] = i + 1; 
		} 
 
		printf("dizinin elemanlari: \n"); 
		for (i = 0; i < n; ++i) { 
			printf("%d, ", ptr[i]);        
		} 

            free (ptr); 
            printf("\ncalloc memory say that freedom"); 
	} 

	return 0; 
} 
**********************************************************************/