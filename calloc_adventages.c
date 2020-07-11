/*
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n,i,*p;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    p=(int*)calloc(n, sizeof(int)); // 0 DEGERI VEYA NULL DEGERI GEREKTIGINDE "calloc" ILE BU DEGERLER ICIN INITIALIZATIN YAPILABILIR
    if(p == NULL)
    {
        printf("memory cannot be allocated\n");
    }
    else{
      printf("Elements of array are\n");
      for(i=0;i<n;i++)
      {
        printf("%d\n",*(p+i)); 
      }
    }
    return 0;
}
*/


#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n,i,*p;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    p=(int*)malloc(n* sizeof(int));
    if(p == NULL)
    {
        printf("memory cannot be allocated\n");
    }
    else
    {
      printf("Elements of array are\n");
      for(i=0;i<n;i++)
      {
        printf("%p\n",*(p+i)); 
      }                         
    }
    return 0;
}
