#include <iostream>
#include <typeinfo> // for typeid()

int main() {
	// Explicit conversion (casting)
	// When the programmer uses a casting operator to
	// transform a fundamental data type into another
	std::cout << 10 / 4 << std::endl;
	std::cout << (float) 10 / 4 << std::endl;
	std::cout << float(10) / 4 << std::endl;
	std::cout << static_cast<float>(10) / 4 << std::endl;
	// static_cast provides compile-time type checking
	// the other ones don't
	
	// Implicit conversion (coercion)
	// When the compiler automatically transforms one
	// fundamental data type to another
	
	// numeric promotion (widening)
	// converting a data type to a large similar data type
	long x{ 3 }; // int to long
	double d{ 3.1f }; // float to double

	// numeric conversion (narrowing)
	// converting a data type to a smaller similar data type
	int y{ 3L }; // long to int
	float g{ 4.1 }; // double to float

	// typeid can be used to find out the type of an value or expression
	std::cout << typeid(y + g).name() << std::endl;




	return 0;
}
