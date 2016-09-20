#include "main.h"

int main() {
	int x = 10; // This is copy initialization
	int y(10); // direct initialization
	float z{10}; // uniform initialization - preferred for c++11

	std::cout << "x is " << x << std::endl;

	int a; // This is a declaration
	int b = 10; // This is initialization

	// The sizeof operator returns the amount of bytes
	// that a particular data type uses
	// This is because C++ only guarantees a minimum 
	// size for primitive types because of performance
	// reasons on different architectures
	std::cout << "int takes up " << sizeof(int) << " bytes" << std::endl;

	float c = 5.0f; // Use f to indicate float
	// Default is double

	double d = 5e10; // = 5 x 10^10
	// The e denotes scientific notation

	// Because C++ is based on C, 
	// 1 == true
	// 0 == false
	bool boolean = true;
	std::cout << boolean << std::endl;
	
	// std::boolalpha makes it so std::cout prints
	// out 'true' and 'false' instead of 1 and 0
	std::cout << std::boolalpha;
	std::cout << boolean << std::endl;


	// Type casting
	// use static_cast<new_type>(expression)
	// to convert between different representations
	int i{97};
	char j{static_cast<char>(i)};

	std::cout << i << " " << j << std::endl;

	//int x = 5; //5 is a literal
	// A literal is a constant that can't be changed.
	// Sometimes literals have suffixes that are used to determine
	// their type. But usually the compiler will figure it out.

	// A leading 0 on an integer means its a number in octal.
	// 0x denotes a hexadecimal number.
	// 0b denotes a binary number in C++14
	// C++14 also allows using ' as a digit separator
	int f = 0b0001'1011'1011;

	// A magic number is a hard-coded literal that does not
	// have any context.

	// To make a variable constant, use the const keyword
	const double g { 9.81 };


	return 0;
}
