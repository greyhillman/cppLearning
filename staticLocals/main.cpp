#include <iostream>

int getID() {
	int value = 0;
	return ++value;
}

int getStaticID() {
	static int value = 0;
	return ++value;
}

int main() {
	std::cout << "Non-static local variable" << std::endl;
	for (int i = 0; i < 10; i++) {
		std::cout << getID() << std::endl;
	}

	std::cout << "Static local variable" << std::endl;
	for (int i = 0; i < 10; i++) {
		std::cout << getStaticID() << std::endl;
	}
}
