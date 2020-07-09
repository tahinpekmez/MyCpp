/***********************************************************************
#include <iostream>
#include <string>

int main()
{
    std::string firstlevel ("home");
    std::string secondlevel ("at");
    std::string thirdlevel ("stay");
    std::string rule;

    rule = thirdlevel + ' ' + secondlevel + ' ' + firstlevel;
    std::cout << rule << '\n';

    return 0;
}
// BU YONTEM ILE KARAKTER DIZILERI BIRBIRINE EKLENIR ANCAK
// HER YENI KARAKTERDE YENI BIR BUFFER (ARA BELLEK) YER KAPLAR
// BU DA KODUMUZUN ZAMAN VERIMI ACISINDAN VERIMLILIGINI DUSURUR. 
**************************************************************************************/


// YENI BIR BUFFER OLUSTURMADAN ASAGIDAKI YONTEMLE DAHA VERIMLI BIR STRING BIRBIRINE EKLEME GOSTEREBILIRIZ
#include <iostream>
#include <string>

int main ()
{
  char str[50];
  strcpy (str,"MASKE\n"); 
  /* NULL-TERMINATOR ARAR, EKLENEN KELIMENIN SONUNDA İLAVE EDILEN 
   KELIMENIN UZERINE YAZILACAGI NULL-TERMINATORU YORUMLAR (strcat) */                  
  strcat (str,"MESAFE\n");
  strcat (str,"TEMIZLIK");
  puts (str);
  return 0;
}