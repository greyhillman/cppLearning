#include <iostream>

int main() {
	int x = 5;

	// The expression in the switch () has to be an integral type
	switch (x) {
		// Each case label has to be a constant expression
	case 1:
		std::cout << "x = 1" << std::endl;
		break;
	default:
		std::cout << "x = " << x << std::endl;
		break;
	}

	return 0;
}
