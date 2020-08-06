#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

typedef enum {true, false} bool;

void main()
{
    setlocale(LC_ALL, "Turkish");

    // NOT: C DÝLÝNDE C++ GÝBÝ "string" KELÝMESÝ YOKTUR.
    char *kelime;
    kelime = (char*)malloc(75*sizeof(char)); // TÜRKÇE' deki EN UZUN KELÝME BOYUTU

    int uzunluk,n;
    bool kalin_unlu_uyumu = false, ince_unlu_uyumu = false;

    printf("Lütfen Türkçe dilinde bir kelime giriniz: ");
    scanf("%s", kelime);

    uzunluk=sizeof(kelime); // KELIMENIN UZUNLUGU

    for(n=0;n<uzunluk;++n)
    {
       if(kelime[n]=='a'|| kelime[n]=='ý'|| kelime[n]=='o' || kelime[n]=='u')
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
    free(kelime);

    }



