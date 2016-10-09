#include <iostream>

// An enumerated type (enumeration) is a data type
// where every possible value is defined as a symbolic
// constant (called an enumerator).

enum Color {
	// These are the enumerators
	COLOR_RED, // assigned 0
	COLOR_BLACK, // 1 
	COLOR_WHITE // 2
}; // enum must end with a semicolon
// Declaring an enumerator does not allocate any memory

// We prefix the enumerators with the name of the enum since
// enumerators exist in the global namespace, in this case
// They're in all caps since they're much like a macro

enum Animal {
	ANIMAL_CAT = -3,
	ANIMAL_DOG, // -2
	ANIMAL_PIG = 0,
	ANIMAL_COW = 0 // same as ANIMAL_PIG
	// Therefore, PIG and COW are intechangable
	// This is bad
};

// enums can't be forward declared since their memory allocation
// is dependent on the compiler. Must often its an int.

int main() {
	Color paint = COLOR_WHITE;
	// When a variable of the enumerated type is declared,
	// memory is allocated
	Color house{ COLOR_RED };

	std::cout << paint << std::endl;
	std::cout << house << std::endl;

	// Each enumerated type is considered a distinct type
	// Animal animal = COLOR_RED; // compiler error

	// Enums are useful for giving magic numbers meaning

	// standard enums aren't type safe and can do some weird things
	Color color = COLOR_RED; // 0
	Animal animal = ANIMAL_PIG; // 0

	// The compiler will complain, but only gives a warning
	if (color == animal) {
		std::cout << "weird stuff happens" << std::endl;
	}
	return 0;
}
