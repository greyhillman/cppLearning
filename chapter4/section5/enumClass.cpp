#include <iostream>

// C++11 introduced enum classes,
// which are exactly like enums but have stronger scoping
// and typing

enum class Color {
	RED,
	BLUE,
	BLACK,
	WHITE
};

enum class Animal {
	PIG,
	COW,
	CHICKEN
};

int main() {
	Color color = Color::RED;
	Animal animal = Animal::PIG;

	/*
	if (color == animal) { // This is a compile error
		std::cout << "equal" << std::endl;
	}
	*/

	//std::cout << color << std::endl; // This doesn't work either
	return 0;
}
