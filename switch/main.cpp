#include <iostream>

int main() {
	int x = 5;

	// expression in switch has to be integral type
	switch (x) {
	// Each case label has to be a constant expression
	case 1:
		std::cout << "x is one" << std::endl;
		break;
	case 2:
		std::cout << "x is two" << std::endl;
	case 3:
		std::cout << "fall through" << std::endl;
		break;
	default:
		break;
	}
	
	return 0;
}
