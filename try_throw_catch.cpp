#include <iostream>
#include <vector>
#include <algorithm>

//using namespace std;

void printx2(int a)
{
    std::cout << a*2 << " ";
    if (a % 2 == 0)
    {
        throw a;
    }
}

struct A
{
    void operator() (int a) // operator overloading
    {
        std::cout << a*3 << " ";
        if (a % 2 == 0)
        {
            throw a;
        }
    }
} obj;

int main()
{
    int arr[5] = {1, 5, 2, 4, 3 };

    std::cout << "using array:" << std::endl;

    try
    {
        std::for_each(arr, arr + 5, printx2);
    }
    catch(int i)
    {
        std::cout << "\nthe exception element is: " << i;
    }
    std::cout << std::endl;

    try
    {
        std::for_each(arr, arr+5, obj);
    }
    catch(int i)
    {
        std::cout << "\nthe exception element is: " << i;
    }   
}