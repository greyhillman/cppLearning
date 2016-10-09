#include <iostream>
#include <string>



int main() {
	std::string name{ "Grey Hill" };
	std::cout << name << std::endl;

	name = "Can assign strings to it as well.";
	std::cout << name << std::endl;

	// Funky things happen with std::cin though
	std::string in{ "" };
	int age = 0;

	std::cout << "Enter your full name:" << std::endl;
	std::cin >> name;

	std::cout << "Enter your age:" << std::endl;
	std::cin >> age;

	std::cout << name << " is " << age << " years old." << std::endl;

	// This doesn't work because std::cin breaks on whitespace.

	std::string ageString;
	std::getline(std::cin, name); // Reads a full line of test
	std::getline(std::cin, ageString); // The second param is a std::string
	std::cout << name << " is " << ageString << " years old." << std::endl;

	// I didn't do the whole lession because it isn't really
	// a language feature, but a library.

	return 0;
}
