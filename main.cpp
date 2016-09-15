#include "main.h"

int main() {
	int x = 10; // This is copy initialization
	int y(10); // direct initialization
	float z{10}; // uniform initialization - preferred for c++11

	// When a variable is given a value after it has been defined,
	// it is called a copy assignment (or assignment for short)
	int a;
	a = 5;

	std::cout << "x is " << x << std::endl;

	return 0;
}
