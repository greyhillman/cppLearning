#include <iostream>
#include <typeinfo>

auto divide(int x, int y) -> int; // C++11 allows for trailing return syntax
// In this case, auto is assigned the type int

// In C++14, auto can be used for a function's return type
auto add(int x, int y) {
	return x + y;
}

int main() {
	// Before C++11 the auto keyword was used to tell the compiler that a
	// variable had automatic duration.
	// But since this was the default behaviour, the word wasn't used alot.

	// In C++11, the auto keyword is used to deduce the type of a variable.

	auto d = 5.0; // should be a double since 5.0 is a double literal
	std::cout << typeid(d).name() << std::endl;

	// the auto keyword only works for variable that are initialized, and not
	// declared
	auto sum = add(5, 4);
	std::cout << sum << std::endl;
	return 0;
}
