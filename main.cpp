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

	// Chapter 3.8a: Bit flags and masks
	{
		// Sometimes we want to use the invidivual bits in a
		// data type. This is usually used for more memory-intensive
		// tasks.
		// Most time they are used for flags
		unsigned char flags = 0b1101'0110;

		// To get a specific bit, use bitwise AND
		if (flags & 0b1000'0000) {
			std::cout << "MSB is set." << std::endl;
		}

		// To turn a bit on, use bitwise OR
		flags |= 0b0010'0000;

		// To turn a bit off, use bitwise AND with an inverse bit pattern
		flags &= ~0b0010'0000;

		// To toggle a bit, use bitwise XOR
		flags ^= 0b0010'0000;
		flags ^= 0b0100'0000 | 0b1000'0000; // flips both

		// std::bitset makes for easier use of bit flags and masks
		std::bitset<8> bits(0b0000'0001); // Start with the LSB set

		bits.set(4); // std::bitset uses indices. So this sets the 5th bit on
		bits.flip(7); // MSB
		bits.reset(7); // MSB

		std::cout << bits << std::endl;

	}


	// Chapter 4.1: Blocks (compound statements)
	{
		// A block (compound statement) is a group of statements that is 
		// treated by the compiler as if it were a single statement.
		// Blocks are started with a { and end with a }.
	}

	// Chapter 4.1a: Local variables, scope, and duration
	{
		// scope is the area in which a variable is accessible
		// duration determines where it is created and destroyed

		// local variables are variables defined inside a block
		// Local variables have automatic duration, which means they
		// are created at the point of definition, and are destroyed
		// when the block they are defined in is exited.
		// Local variables have block scope (local scope), which means they
		// enter scope at the point of declaration and go out of scope at the
		// end of the block that they are defined in.

		// Note: You can name a variable inside a nested block with the same
		// name as a variable inside the outer block.
		// This is called name hiding or shadowing.

		// Rule: Avoid using nested variables with the same names
		// as variables in an outer block.

		// Rule: Defined variables in the smallest scope possible.
		// By limiting the scope of a variable, you reduce the complexity
		// of the program because the number of active variables is reduced.
		// It also makes it easier to see where the variables are used.

	}

	// Chapter 4.2: Global variables and linkage
	{
		// Variables declared outside of a block are called global variables.
		// Global variables have static duration, which means they are created
		// when the program starts and are destroyed when it ends.
		// Global variables have global scope (also called global namespace scope,
		// or file scope), which means they are visible until the end of the file 
		// in which they are declared.

		// When a global variable is shadowed, but you want to access the global
		// one, use the globa scope operator (::).

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


	return 0;
}
