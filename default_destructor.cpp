#include <iostream>
#include <type_traits>

class X {
    public:
        ~X() {}
};

class Y {
    public:
        ~Y() = default;
};

int main(){
static_assert(std::is_trivially_move_constructible<X>::value == false, "");
static_assert(std::is_trivially_move_constructible<Y>::value == true, "");
return 0;
}
