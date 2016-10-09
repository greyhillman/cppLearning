#include <iostream>

int increment() {
	int value = 1;
	return ++value;
}


int incrementStatic() {
	static int value = 1;
	return ++value;
}

int main() {
	std::cout << "Non-static value increment:" << std::endl;
	std::cout << increment() << std::endl;
	std::cout << increment() << std::endl;
	std::cout << increment() << std::endl;

	std::cout << "Static value increment:" << std::endl;
	std::cout << incrementStatic() << std::endl;
	std::cout << incrementStatic() << std::endl;
	std::cout << incrementStatic() << std::endl;

	// Putting static on a local variable makes it so it has static duration
	// which means that it retains it value even after the scope in which is 
	// has been created has been exited.

	// This makes it safer than a global variable.

	return 0;
}
