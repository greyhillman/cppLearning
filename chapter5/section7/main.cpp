#include <iostream>

int main() {

	for (int i = 0; i < 10; i++) {
		std::cout << i << " ";

	}
	std::cout << std::endl;

	// A use of the comma operator
	// most used place
	for (int i = 0, j = 9; i < 10; i++, j--) {
		std::cout << i << " " << j << std::endl;
	}

	return 0;
}
