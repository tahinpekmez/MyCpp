#include <stdio.h>

typedef enum {true, false} bool;

void main(void)
{
    // NOT: C DILINDE C++ GIBI "string" OZELLIGI YOKTUR.
    char kelime[75]; // TURKCEDEKI EN UZUN KELIME UZUNLUGU
    int uzunluk,n;
    bool kalin_unlu_uyumu = false, ince_unlu_uyumu = false;

    printf("LUTFEN TURKCE DILINDE BIR KELIME GIRINIZ: ");
    gets(kelime);

    uzunluk=strlen(kelime); // KELIMENIN UZUNLUGU

    for(n=0;n<uzunluk;++n)
    {
       if(kelime[n]=='a'||kelime[n]=='ı'||kelime[n]=='o' || kelime[n]=='u')
       {
         kalin_unlu_uyumu = true;
       }

       if(kelime[n]=='e'|| kelime[n]=='i' || kelime[n]=='ö' || kelime[n]=='ü')
        {
        ince_unlu_uyumu = true;
        }
    }

    if(kalin_unlu_uyumu || ince_unlu_uyumu)
        {
            printf("buyuk unlu uyumu var");
        }
    else
        {
            printf("buyuk unlu uyumu yok");
        }
    getchar();

    }
