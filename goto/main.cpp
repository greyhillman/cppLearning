#include <iostream>

int main() {
	double x;

	tryAgain: // Statement label
	// Statement labels have function scope
	std::cout << "Enter a non-negative number";
	std::cin >> x;

	if ( x < 0.0 ) {
		goto tryAgain; // goto statement
	}

	std::cout << x << std::endl;

	return 0;
}
