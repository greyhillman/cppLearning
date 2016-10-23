#include <iostream>

// C++11 introduced enum classes, which are exactly
// like enums but have strong scoping and typing
enum class Color {
	RED,
	BLUE,
	BLACK,
	WHITE
};

enum class Feeling {
	SAD,
	BLUE,
	TIRED
};

int main() {
	Color color = Color::BLUE;
	Feeling feeling = Feeling::BLUE;

	if (color == Color::BLUE) {
		std::cout << "color is blue" << std::endl;
	}

	if (feeling == Feeling::BLUE) {
		std::cout << "feeling is blue" << std::endl;
	}


	return 0;
}
