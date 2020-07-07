#include <stdio.h>

int main() {

    int  a = 10;
    int  *p1;    // this can store the address of variable a     
    int  **p2; 
                
    p1 = &a;  // store address of a
    p2 = &p1; // store address of p1

    printf("Address of a = %u\n", &a);
    printf("Address of p1 = %u\n", &p1);
    printf("Address of p2 = %u\n\n", &p2);

    // below print statement will give the address of 'a'
    printf("Value at the address stored by p2 = %u\n", *p2);  // display of value at the address stored by p2 = 6684188
    
    printf("Value at the address stored by p1 = %d\n\n", *p1); // display of value at the address stored by p1 = 10

    printf("Value of **p2 = %d\n", **p2); //read this *(*p2)  // display of value at the address stored by *p2 
                                                              // assume like that is *q (q=*p2)
    /*
        This is not allowed, it will give a compile time error
        p2 = &a;
        printf("%u", p2);
    */
    return 0;
}