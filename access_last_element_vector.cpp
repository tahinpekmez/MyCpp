#include <iostream>
#include <vector>
#include <iterator>

void vec()
    {
        std::vector<int> v {2, 5, 72, 93, 25};
        //std::vector<int>::iterator it = --v.end(); // output 25
        //std::vector<int>::iterator it = std::prev(v.end()); // output 25
        std::vector<int>::iterator it = v.end() - 1;
        std::cout << *it ;
    }

int main()
{
    vec();    
    
    // int var = v.back();
    // std::cout << "\n" << var; // output 25

    return 0;
}
