#include <iostream>

// typedef allows a programmer to make an alias for a data type
// typedef <data type> <alias>
typedef long miles_t;
typedef long score_t;
// We have a _t suffix to indicate that it is a type
// This prevents naming collisions with variables

// C++11 introduced the type alias
using distance_t = double; // is the same as
//typedef double distance_t;
// but looks and reads a lot easierly

int main() {
	miles_t miles = 5;
	score_t score = 3;

	// typedef is just an alias, so no errors are thrown
	miles = score;

	// typedef can allow for easier readability and maintenance,
	// since they "hide" the data type

	// typedef can allow for platform independent coding
	// the cstdint library gives us typedefs for fixed length
	// data types
	
	return 0;
}
