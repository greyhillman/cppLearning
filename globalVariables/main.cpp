#include "main.h"

int x = 10; // global variable

int func() {
	int x = 4;

	std::cout << x << std::endl;
	std::cout << ::x << std::endl;
}

int main() {
	func();

}
