
// This is a preprocessor directive. This tells the compiler to include
// the contents of the iostream header file to the program.
#include <iostream>
// A library is a collection of precompiled code that has been packaged up for
// reuse in many different programs.

// The C++ standard library is a collection of libraries that provides lots of
// functionality for a program.
// iostream is a library to output and receive input from the command-line.

// This is a function
int function() {
	// A function is a sequence of statements
	return 10;
}

// This is also a function
int main() {
	// main() is the function that is called when a program is run

	// A statement is the smallest independent unit in C++
	// All statements end with an semicolon

	int x; // This is a declaration statement

	x = 5; // This is an assignment statement
	
	// << is called the output operator in this context
	std::cout << x << std::endl; // This is an output statement

	// An expression is a mathematical entity that evaluates to a value
	x = 2 + 3; // 2 + 3 is an expression
	
	// An expression can involve values, variables, operators, and functions

	
	// The rules that govern how sentences are constructed in a language
	// is called syntax.

	// C++ has the same thing. If you violate a rule of the syntax,
	// the compiler will output a syntax error.
	// int x = 5 // This would have a syntax error since the statement isn't
	// terminated with a semicolon



	return 0; // This is a return statement
	// The value returned from main signals to the OS whether or not the
	// program ran successfully or not.
	// 0 means success
	// non-zero means some sort of failure
}
