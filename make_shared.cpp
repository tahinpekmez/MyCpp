#include <iostream>
#include <memory>


int main() {

	std::shared_ptr<int> foo = std::make_shared<int>(10);

	// yukaridaki gibi:
	std::shared_ptr<int> foo2(new int(10));

	auto bar = std::make_shared<int>(20);
	
	auto baz = std::make_shared<std::pair<int, int>>(30, 40);

	std::cout << "*foo: " << *foo << '\n'; //*foo: 10
	std::cout << "*bar: " << *bar << '\n'; // *bar: 20
	std::cout << "*baz: " << baz->first << ' ' << baz->second << '\n'; // *baz: 30 40

	return 0;
}