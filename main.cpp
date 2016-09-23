#include "main.h"

// Macros are of the form
//#define identifier substitutionText
#define BAD_FOR_CONSTANTS 123
// Macros are bad because they are resolved by the preprocessor and thus don't show in a
// debugger. All you would see is BAD_FOR_CONSTANTS instead of 123.
// Also, they live in global scope. And remember, globals are PURE EVIL!

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
	// Assigning to a const variable results in a compile-error
	//g = 10; // will throw an compile error

	// const variables can be initialized from non-const values.
	int temp;
	std::cout << "Enter a number: ";
	std::cin >> temp;
	std::cout << std::endl;
	const int h { temp }; // run-time const

	// C++ has two kinds of constants: compile-time and run-time
	// const can be both compile-time and run-time
	// constexpr is only used for compile-time
	constexpr double compileConst = 123.0;
	
	// The best way to deal with constants is to have them all in one place.
	// Like a header file in a namespace.


	// Chapter 3.4: sizeof(), comma operator, and conditional operator
	{
		// The sizeof() operator returns the number of bytes allocated for a
		// variable or data type.
		std::cout << "Number of bytes for int: " << sizeof(int) << std::endl;
		std::cout << "Number of bytes for compileConst: " 
				  << sizeof(compileConst) << std::endl;

		// The comma operator evualates all the expressions and then returns the right
		// most expression
		int x = 5;
		int y = 6;
		int z = (++x, ++y); // x = 6, y = 7, z = 7
		
		// Most programmers don't use this except in for-loops

		// Conditional Operator
		// <condition> ? <expression1> : <expression2>
		// if condition is true, return expression1. Else return expression2.

		// Much similar to an if statement but the conditional operator evaluates
		// as an expression. This means you can initialize a const based on a condition.
		bool condition = true;
		const int test = condition ? 30 : 20;
		// You can't do this with an if-else statement.

		// In general, use an if-else statement. But if the expression is very
		// simple, and is more readable using a conditional operator, go ahead.

	}

	// Chapter 3.5: Relational operators (comparisons)
	{
		// Greater than: >
		// Less than: <
		// Greater than or equal: >=
		// Less than or equal: <=
		// Equality: ==
		// Inequality: !=
		// All return either true or false.

		// You shouldn't use this operators when comparing floating-point numbers
		// due to round-off errors.
		// If you need to compare numbers that are close to each other,
		// use a comparison function with some epsilon.

	}

	// Chapter 3.6: Logical operators
	{
		// NOT: !<condition>
		// AND: <condition> && <condition>
		// OR:  <condition> || <condition>

		// && and || have short circuit evaluation

		// There is not explicit XOR operator, but != has the same effect.
	}

	// Chapter 3.7: Converting between binary and decimal.
	// Already know this stuff.

	// Chapter 3.8: Bitwise operators
	{
		// Left shift : x << y : Moves bits in x left y times (times by 2)
		// Right shift: x >> y : Moves bits in x right y times (divide by 2)
		// bitwise NOT:  ~x    : Flip the bits
		// bitwise AND: x & y  : Does AND on each pair of bits
		// bitwise OR : x | y  : Does OR on each pair of bits
		// bitwise XOR: x ^ y  : Does XOR on each pair of bits

		// Because they work on all bits, a rule is to only use them on
		// unsigned data types.

		unsigned int x = 0b0001;
		std::cout << "x << 1 = " << (x << 1) << std::endl;
		// Should be 2.

		x = 0b1000;
		std::cout << "x >> 3 = " << (x >> 3) << std::endl;
		// Should be 1

		// You can also append an = to each operator to get it's
		// assignment operator.

	}


	return 0;
}
