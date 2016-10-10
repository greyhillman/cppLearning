#include <iostream>

using age_t  = int;
using wage_t = float;
using eid_t   = long;

// An aggregate data type is a data type that groups multiple individual
// variables together

// The struct is the simplest aggregate data type
struct Employee {
	eid_t  id;
	age_t  age; // these are members (fields) of the struct
	wage_t wage;
}; // don't forget semi-colon
// struct names begin with a capital to distinguish them from variable names

struct Triangle {
	float height = 1.0f; // C++11 allows you to give non-static struct members a
	float width  = 1.0f; // default value
};
// However, this doesn't work with initializer lists
// This restriction is lifted in C++14 though

struct Company {
	Employee ceo; // nested structs
	int      numEmployees;
};

struct DataAlignment {
	short x;
	int   y;
}; // size should be 6 bytes
// But it's actually 8. there's two bytes of padding after x

int main() {
	Employee joe;
	joe.id   = 0;
	joe.age  = 20;
	joe.wage = 20.0f;
	// use the . operator to access fields of a struct

	// You can initialize a struct using an initializer list
	Employee frank = { 1, 21, 18.0f };
	Employee john  = { 2, 22 }; // wage defaults to 0

	// C++11 allows for uniform initialization
	Employee greg { 3, 25, 30.0f };

	// order matters in initializer lists
	Triangle x;
	std::cout << x.height << " " << x.width << std::endl;

	Triangle y { 2.0f, 1.5f };
	std::cout << y.height << " " << y.width << std::endl;

	Triangle z { 2.0f };
	std::cout << z.height << " " << z.width << std::endl;

	// before c++11, you can to manually assign values to a struct's fields
	// like for joe
	// C++11 allows you to use initializer lists
	joe = { 0, 20, 20.0f };

	Company co { {5, 55, 100.0f}, 10 }; // nested initializer lists

	std::cout << "Actual size: " << sizeof(DataAlignment) << std::endl;

	return 0;
}
