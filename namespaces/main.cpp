#include <iostream>

namespace Foo {
	int func() {
		return 7;
	}
}

namespace Foo {
	int test() {
		return 4;
	}
}

namespace Bar {
	namespace Baz {
		int func() {
			return 10;
		}

		const int lel = 69;
	}
}

namespace BadThing = Bar::Baz;

int func() {
	return 1;
};

int main() {
	std::cout << func() << std::endl;
	std::cout << ::func() << std::endl;
	std::cout << Foo::func() << std::endl;
	std::cout << Bar::Baz::func() << std::endl;
	std::cout << BadThing::func() << std::endl;

	using namespace BadThing;

	std::cout << lel << std::endl;

	using BadThing::func;

	std::cout << func() << std::endl;
}
