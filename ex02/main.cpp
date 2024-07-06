
#include "Dog.hpp"
#include "Cat.hpp"
#include "ShallowCat.hpp"

/*
	A pure virtual function is a function that has no implementation in the base class 
	and must be overridden in derived classes. Doing this (using a pure virtual function)
	makes the class abstract and prevents it from being instantiated. The function we 
	made pure virtual in this case was Animal::makeSound() and all we have to do to make
	a virtual function is add an equal 0 at the end of it like this:
		virtual void makeSound() const = 0;
	
	Now that we have a pure virtual function in the Animal class, the Animal class in ex02
	has become an Abstract Class. Abstract classes in C++ are classes that cannot be
	instantiated directly. They are designed to be base classes for other classes, providing
	a common interface and functionality.

	So basically, we can no longer do:
		Animal	animal1;
	
	But, we can still create Animal class pointers:
		Animal* cat = new Cat();
*/
int main()
{
	Cat		cat;
	Animal*	dog = new Dog();

	std::cout << "\n";

	cat.makeSound();
	dog->makeSound();

	std::cout << "\n";

	delete(dog);

	return (0);
}
