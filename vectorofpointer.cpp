#include <iostream>
#include <vector>

// vektoru ekrana yazdiriyoruz
void PrintVector(std::vector<int> v) {
    for(auto x : v) std::cout << x << ", ";
    std::cout << "\n";
}

void PrintVector(std::vector<int*> v) {
    for(auto x : v) std::cout << *x << ", ";
    std::cout << "\n";
}

int main() {
    std::vector<int> vector1;
    std::vector<int> vector2;
    std::vector<int*> ptrvector; // integer tipi pointer vektoru


    for( int i = 1; i<=3; i++) {
        vector1.push_back(i);    // (1, 2, 3)
        vector2.push_back(2*i); // (2, 4, 6)
    }
    // vector1 eleman adreslerini referans alıp pointer olarak ptrvector icine ekliyoruz ( emplace_back() )
    ptrvector.reserve(vector1.size());
    for(auto& r : vector1)
        ptrvector.emplace_back(&r);

    //Print out:
    PrintVector(vector1);   // (1,2,3)
    PrintVector(vector2);   // (2,4,6)
    PrintVector(ptrvector); // (1,2,3)

    ptrvector[0] = &vector2[2];
    PrintVector(ptrvector); // (6,2,3);

    vector2[2] = 20;
    PrintVector(ptrvector); // (20,2,3)
}