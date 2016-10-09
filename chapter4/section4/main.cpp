#include <iostream>

#include <typeinfo> // for typeid()

int main() {
	// Type conversion
	// Converting a value from one data type to another

	float f = 3; // converts the integer 3 to a float
	std::cout << f << std::endl;

	// implicit type conversion (coercion)
	// When the compiler automatically transforms one
	// fundamental data type into another

	// explicit type conversion (casting)
	// When the programmer uses a casting operator to 
	// direct the conversion

	// numeric promotion (widening)
	// converting a data type to a large similar data type
	long x{ 3 }; // int to long
	double d{ 3.1f }; // float to double

	std::cout << x << std::endl;
	std::cout << d << std::endl;

	// numeric conversion (narrowing)
	int y{ 3L }; // long to int
	float g{ 3.1 }; // double to float
	// This can result in loss of data
	std::cout << y << std::endl;
	std::cout << g << std::endl;

	short a{ 4 };
	short b{ 5 };

	std::cout << typeid(a + b).name() << " " << a + b << std::endl;


	std::cout << 10 / 4 << std::endl;
	std::cout << (float) 10 / 4 << std::endl;
	// Casts an int to a float

	// You use the () operator to cast
	// You can also use a function-like operator in C++
	std::cout << float(10) / 4 << std::endl;
	// The compiler doesn't check this C-style cast so try to avoid it

	std::cout << static_cast<float>(10) / 4 << std::endl;
	// static_cast is a casting operator that provides compile-time
	// type checking.
	// It also doesn't do stupid stuff like removing a const.
	return 0;
}
