#include <iostream>

using age_t = int;
using wage_t = float;
using eid_t = long;

// Aggregate data type
// A data type that groups multiple data types together

struct Employee {
	eid_t id; // members or fields
	age_t age;
	wage_t wage;
};

struct Triangle {
	float height = 1.0f; // C++11 allows non-static fields to have
	float width = 1.0f; // a default value
};

struct Company {
	Employee ceo;
	int numEmployees = 1;
};

struct DataAlignment {
	short x;
	int y;
}; // size should be 6 bytes, but its 8
// There's two bytes of padding after x

int main() {
	Employee joe {1, 20, 20.0f}; // Uniform initialization
	Employee frank = {2, 22, 18.0f};
	Employee john {3, 22}; // wage defaults to 0

	// Use . operator for access to fields
	if (joe.age > frank.age) {
		std::cout << "Joe is older than frank" << std::endl;
	}

	Company co {{1, 20, 35.0f}, 2}; // nested initializer lists



	return 0;
}
