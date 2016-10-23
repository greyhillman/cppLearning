#include <iostream>
#include <cstdlib>
#include <ctime>

// C++11 added lotsof RNGs to the C++ standard library
#include <random>

const unsigned int initialSeed = 5323;

unsigned int prng() {
	static unsigned int seed = initialSeed;

	seed = (57843921 * seed + 743829);

	return seed % 32768;
}

int main() {
	std::cout << "Our own pseudo-random number generator." << std::endl;
	for (int c = 0; c < 100; c++) {
		std::cout << prng() << "\t";

		if ( (c + 1) % 5 == 0 ) {
			std::cout << std::endl;
		}
	}

	srand(initialSeed);
	std::cout << "C's rand() with constant seed" << std::endl;
	std::cout << "RAND_MAX = " << RAND_MAX << std::endl;
	for (int c = 0; c < 100; c++) {
		std::cout << rand() << "\t";

		if ( (c + 1) % 5 == 0 ) {
			std::cout << std::endl;
		}
	}

	std::cout << "C's rand() with time(0) as seed" << std::endl;
	srand(static_cast<unsigned int>(time(0)));
	for (int c = 0; c < 100; c++) {
		std::cout << rand() << "\t";

		if ( (c + 1) % 5 == 0 ) {
			std::cout << std::endl;
		}
	}


	std::cout << "C++11's mersene twister" << std::endl;
	std::random_device rd; // Use a hardware entropy source if avaible,
	// otherwise use PRNG
	std::mt19937 mersenne(rd()); // initialize mersenne twister
	for (int c = 0; c < 100; c++) {
		std::cout << mersenne() << "\t";

		if ( (c + 1) % 5 == 0 ) {
			std::cout << std::endl;
		}
	}

	return 0;
}
