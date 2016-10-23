
// typedef allows a programmer to make an alias for
// a data type
typedef long miles_t;
typedef long score_t;
// the _t denotes a type, which prevents naming collisions

// C++11 introduced the type alias
using distance_t = double;
// same as
//typedef double distance_t;

int main() {
	miles_t miles = 5;
	score_t score = 3;

	miles = score; // typedef is just an alias

	double g = 9.81;

	distance_t d = g;
}
