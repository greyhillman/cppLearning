#include "main.h"

static int internalLinkage = 10;
// statis makes a variable have internal linkage
// internal linkage means a variable can only be used
// within the file they are defined in

// Forward declaration of externalLinkage
extern int externalLinkage; // defined in external.cpp
// extern makes a variable have external linkage
// external linkage means a variable can be used in the file
// they are in and other files

// By default, global non-const variables are assumed to be external
// Global const variables are assumed to be internal

// static and extern can also be used for functions

static int add(int x, int y) {
	return x + y;
}

extern int minus(int x, int y);

int main() {
	// A variable's linkage determines whether multiple instances of an
	// identifier refer to the same variable or not.
	// There are three types: no, internal, or external linkage.

	// no linkage means a variable can only be referred to from the limited
	// scope it exists in.

	std::cout << internalLinkage << std::endl;
	std::cout << externalLinkage << std::endl;

	extern int externalLocal;

	std::cout << externalLocal << std::endl;


	std::cout << add(3, 4) << std::endl;
	std::cout << minus(10, 3) << std::endl;

	// TIP
	// Sometimes you will have a header file with a bunch of constants.
	// Everytime you include that file, the constants are copied. This
	// leads to code bloat. To prevent this, try using external variables.
	// Forward-declare the variables in the header file and have a cpp file
	// with the actual variables and their values.

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
