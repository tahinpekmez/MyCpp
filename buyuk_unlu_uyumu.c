#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

typedef enum {true, false} bool;

void main()
{
    setlocale(LC_ALL, "Turkish");

    // NOT: C D�L�NDE C++ G�B� "string" KEL�MES� YOKTUR.
    char *kelime;
    kelime = (char*)malloc(75*sizeof(char)); // T�RK�E' deki EN UZUN KEL�ME BOYUTU

    int uzunluk,n;
    bool kalin_unlu_uyumu = false, ince_unlu_uyumu = false;

    printf("L�tfen T�rk�e dilinde bir kelime giriniz: ");
    scanf("%s", kelime);

    uzunluk=sizeof(kelime); // KELIMENIN UZUNLUGU

    for(n=0;n<uzunluk;++n)
    {
       if(kelime[n]=='a'|| kelime[n]=='�'|| kelime[n]=='o' || kelime[n]=='u')
       {
         kalin_unlu_uyumu = true;
       }

       if(kelime[n]=='e'|| kelime[n]=='i' || kelime[n]=='�' || kelime[n]=='�')
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



