#include "main.h"

int x = 10; // global variable
// global varabiesl have global/file scope
// global variables have static durataion
// which means they are created when the program starts
// and are destroyed when the program ends

int func() {
	int x = 4;

	std::cout << x << std::endl; // local x
	std::cout << ::x << std::endl; // global x
	// :: is the global namespace operator
}

int main() {
	func();
}
