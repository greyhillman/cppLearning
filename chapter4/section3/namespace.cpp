#include <iostream>

// You can use
//     using namspace std;
// or some other namespace at the global level because
// there is still a chance of naming collisions, which defeats
// the purpose of namespaces in the first place

// A namespace defines an area of code in which all identifiers
// are guaranteed to be unique
namespace Foo {
	int func() {
		return 7;
	}
}

// You can have multiple namespace blocks with the same name
// but the constraint of unique identifiers still holds. You
// can even have it in multiple files (much like the std namespace).
// The compiler considers it part of the same namespace
namespace Foo {
	int test() {
		return 20;
	}
}

namespace Bar {
	int func() {
		return 23;
	}
	// It even allow nested namespaces
	namespace Baz {
		const int test = 4;
	}
}

// namespace alias
namespace BadThing = Bar::Baz;

// This is declared in the global namespace
int func() {
	return 3;
}

int main() {

	// This allows you to have two functions with the same identifier
	// but refer to different code
	std::cout << func() << std::endl;
	std::cout << Foo::func() << std::endl;

	// In this case, the :: is the scope resolution operator
	// where the left-side is the namespace and the right is
	// the identifier

	// The using keyword tells the compiler that if it can't find
	// the definition for an identifier, look in the particular
	// namespace
	using namespace Foo;

	std::cout << test() << std::endl;

	// This tells the compiler to map func() to Bar::func()
	using Bar::func;

	std::cout << func() << std::endl;

	// Note that once a using statement has been declared, there's no way 
	// to cancel or replace it
	// The best way to limit it is to have a nested block

	std::cout << BadThing::test << std::endl;

	// C++ namespaces were designed to prevent naming collisions
	// and not information hierarchy.
	
	return 0;
}
