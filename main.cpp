#include "main.h"

// Macros are of the form
//#define identifier substitutionText
#define BAD_FOR_CONSTANTS 123
// Macros are bad because they are resolved by the preprocessor and thus don't show in a
// debugger. All you would see is BAD_FOR_CONSTANTS instead of 123.
// Also, they live in global scope. And remember, globals are PURE EVIL!

void printSeparator() {
	std::cout << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << std::endl;
}

int main() {

	// The different forms of initialization
	{
		int x = 10; // copy
		int y(10); // direct
		int z{10}; // uniform - preferred for c++11
	}

	printSeparator();

	// sizeof operator
	{
		// sizeof outputs the number of bytes allocated for a type or variable
		std::cout << "sizeof(char) = " << sizeof(char) << std::endl;
		std::cout << "sizeof(int) = " << sizeof(int) << std::endl;

		int x[3] = {10, 11, 12};
		std::cout << "sizeof(x) = " << sizeof(x) << std::endl;

		float z{ 1.5 };
		std::cout << "sizeof(z) = " << sizeof(z) << std::endl;

		// C++ only guarantees a minimum number of bytes for each
		// data type because it wanted compiler writers to pick
		// the approriate size to use to have the best performance
		// on their hardware.
	}

	printSeparator();

	// scientific notation
	{
		double d = 5e10;
		std::cout << d << std::endl;
	}

	printSeparator();

	// boolean
	{
		// 0 == false
		// anything else if true
		bool boolean = true;
		std::cout << boolean << std::endl;

		// std::boolalpha sets it so that std::cout prints
		// out 'true' and 'false' instead of 1 and 0
		std::cout << std::boolalpha;
		std::cout << boolean << std::endl;

	}

	printSeparator();

	// type casting
	{
		int i {97};
		char j {static_cast<char>(i)};

		std::cout << i << " " << j << std::endl;

	}

	printSeparator();

	// different integer bases
	{
		// C++14 allow the use of ' as a digit separator
		// C++14 allows use of binary numbers
		int binary  = 0b0000'0000'1100;
		int decimal = 12;
		int octal   = 014;
		int hex     = 0xC;

		std::cout << "binary  = " << binary << std::endl;
		std::cout << "decimal = " << decimal << std::endl;
		std::cout << "octal   = " << octal << std::endl;
		std::cout << "hex     = " << hex << std::endl;
	}

	printSeparator();

	// literals
	{
		// Literals are constants that can't be changed
		// like 5 below
		int x = 5;

		// Sometimes literals have suffixes that are used to
		// determine their type.
		// The compiler will usually figure it out.
	}

	printSeparator();

	// const and constexpr
	{
		const double g {9.81}; // const keyword makes it constant

		//g = 10; // This would result in error

		// The compiler makes sure that a const is not modified

		// const variables can be initialized from non-const values

		int temp = 3;

		const int x = temp; // compile- or run-time const

		constexpr int y = 12; // compile-time const

		// const can be both compile-time and run-time
		// constexpr can only be for compile-time

	}

	printSeparator();

	// TIP: The best way to deal with constants is to have them
	// all in one place. Like a header file in a namespace

	// comma operator
	{
		int x = 5;
		int y = 6;
		int z = (++x, ++y); // x = 6, y = 7, z = 7

		// The comma operator evaluates all the expressions and then
		// returns the right most expression

		// Most programmers don't use this except in for loops
	}

	printSeparator();

	// conditional operator
	{
		bool condition = true;

		const int test = condition ? 30 : 20;
		// If condition is true, return 30. else return 20
		std::cout << "test = " << test << std::endl;

		// TIP: Use if-else for most thing but if a conditional
		// makes it more readable, use it.
	}

	printSeparator();

	// logical operators
	{
		// they can short circuit

		// != has the same effect as XOR
	}

	printSeparator();

	// bitwise operators
	{
		unsigned short x {0b0000'1011};
		unsigned short y {0b0000'0101};

		std::cout << x << std::endl;

		// << bit-shift left
		std::cout << "x << 1 = " << (x << 1 ) << std::endl;
		std::cout << "x << 2 = " << (x << 2 ) << std::endl;

		// >> bit-shift right
		std::cout << "x >> 1 = " << (x >> 1) << std::endl;
		std::cout << "x >> 2 = " << (x >> 2) << std::endl;

		// ~ bitwise not
		std::cout << "~x = " << static_cast<unsigned short>(~x) << std::endl;
		// We use static_cast<unsigned short> because std::cout was
		// treating (~x) as a signed int

		// & bitwise and
		std::cout << "x & y = " << (x & y) << std::endl;

		// | bitwise or
		std::cout << "x | y = " << (x | y) << std::endl;

		// ^ bitwise xor
		std::cout << "x ^ y = " << (x ^ y) << std::endl;

		// TIP: Only use bitwise operators on unsigned integers.
		// Things might mess up with other data types
	}

	printSeparator();

	// std::bitset
	{
		std::bitset<8> bits(0b0000'0001);
		std::cout << bits << std::endl;
		
		bits.set(1); // uses indices
		std::cout << bits << std::endl;

		bits.flip(0);
		std::cout << bits << std::endl;

		bits.reset(1);
		std::cout << bits << std::endl;

		// Makes it easier to deal with bit masks and flags
	}

	printSeparator();

	// Chapter 4.1a: Local variables, scope, and duration
	{
		// scope is the area in which a variable is accessible
		// duration determines where it is created and destroyed

		// Local variables have automatic duration, which means they
		// are created at the point of definition, and are destroyed
		// when the block they are defined in is exited.

		// Note: You can name a variable inside a nested block with the same
		// name as a variable inside the outer block.
		// This is called name hiding or shadowing.
		int x = 5;
		{
			float x = 5; // this x shadows the other x
		}

		// Rule: Define variables in the smallest scope possible.
		// By limiting the scope of a variable, you reduce the complexity
		// of the program because the number of active variables is reduced.
		// It also makes it easier to see where the variables are used.
	}

	printSeparator();

	// Chapter 4.2: Global variables and linkage
	{
		// A variable's linkage determines whether multiple instances of an
		// identifier refer to the same variable or not.
		// There are three types: no, internal, or external linkage.

		// no linkage means a variable can only be referred to from the limited
		// scope it exists in.

		// internal linkage means a variable can only be used within the file
		// they are defined in. (internal variable)

		// external linkage means a variable can be used in the file they are
		// defined in and other files too. (external variable)

		// To make a global variable internal, use the static keyword.
		// To make a global variable external, use the extern keyword.

		// By default, global non-const variables are assumed to be external.
		// Global const variables are assumed to be internal.

		
		// Sometimes you will have a header file with a bunch of constants.
		// Everytime you include that file, the constants are copied. This
		// leads to code bloat. To prevent this, try using external variables.
		// Forward-declare the variables in the header file and have a cpp file
		// with the actual variables and their values.
	}

	// Chapter 4.3b
	{
		// a naming collision is when two identifiers with the same name
		// appear in the same scope

		// A namespace defines an area of code in which all identifiers are 
		// guaranteed to be unique.

		// global variables and normal functions reside in the global namespace

		// We can declare our own namespaces via the namespace keyword

		// We can access something inside a namespace using the 
		// scope resolution operator (::)


	}


	return 0;
}
