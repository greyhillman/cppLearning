#include <iostream>

int main() {

	int expression = -4;
	// A loop that is guaranteed to run at least once
	do {
		std::cout << expression << " ";
	} while (expression > 0);
	std::cout << "done";

	return 0;
}
