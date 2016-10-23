#include <iostream>

int main() {
	int count = 10;
	do {
		std::cout << count-- << std::endl;
	} while (count > 0);

	count = 10;
	while (count > 0) {
		std::cout << count-- << std::endl;
	}

	for (count = 10; count > 0; --count) {
		std::cout << count << std::endl;
	}

	// A use of the comma operator
	for (int i = 0, j = 9; i < 10; i++, j--) {
		std::cout << i << " " << j << std::endl;
	}

	return 0;
}
