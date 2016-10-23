#include <iostream>
#include <typeinfo>

auto subtract(int, int) -> int; // Much like Rust

auto add(int x, int y) {
	return x + y;
}

int main() {
	auto d = 5.0; // d has type double
	std::cout << typeid(d).name() << std::endl;

	auto sum = add(4, 6);
	std::cout << sum << std::endl;

	return 0;
}
