#include <iostream>
#include <cstdlib> 
#include <ctime> 

int rand (void); // MAIN FONKSIYONUNDAN ONCE URETICI HAZIR 
                 // FUNCTION PROTOTAYPE
int main()
{
    std::srand(static_cast<unsigned int>(std::time(nullptr))); 
  
    for (int count=1; count <= 100; ++count)
    {
        std::cout << std::rand() << "\t";
  
        // display 4 random numbers per row
        if (count % 4 == 0)
            std::cout << "\n";
     }
  return 0;
}