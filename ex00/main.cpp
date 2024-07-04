
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

/*
	In order to utilize Polymorphism, we need to use pointers.
	The main idea is that we can do pointers of base classes
	that point to derived classes. These pointers don't have
	to be dynamically allocated pointers but they still have 
	to be pointers. So you can also do something like:
		const Dog buster;
		const Animal* dog = &buster;
	But you see, when you create an instance of a derived class
	and assign it to a base class pointer. These pointers would
	only work with base class functions but with derived class 
	functions, it would only work with the derived class functions
	that have been overridden! So if the Cat class has a unique
	function called doPurring(), a const Animal* cat = new Cat()
	would NOT be able to call cat.doPurring().
	In addition to that, if we have a function that is available
	in the base class but we want it to reuse it do different things
	in derived classes, like the function makeSound(), then we have
	to override this function. The way to do so is to use the 'virtual' 
	keyword in the class defintion of the Animal class before the
	function makeSound(). If we do not do so, then the compiler would
	always assume you want the default makeSound function of the Animal
	base class. That is because a redefined function like makeSound is
	bound at compile time. It is set in stone, its binding is static.
	So since our pointer is of type Animal when we say something like
	const Animal* cat =  new Cat(); then the compiler is to going to
	choose the Animal's definition of that function at COMPILE TIME. When
	we bypass that issue via the virtual keyword, the type of binding
	changes from static to dynamic and so, the decision as to which
	makeSound() function to use is now made at RUN TIME. So basically, 
	hen a function is declared as virtual in a base class, C++ uses a 
	virtual table (vtable) to determine which function to call at runtime,
	allowing the derived class's implementation to be executed.

	NOTE: This also applies to the destructors! If you do not use the virtual
	keyword with the destructor of Animal, it will always call the Animal's
	destructor (when you're working with base class pointers assigned to derived
	class instances), even if you had separate destructors for your derived 
	classes. So basically, if you had anything malloced within your derived 
	classes, those would leak. So to fix that issue, use the virtual keyword 
	with your base class destructor so that the derived class destructors are
	explicility called when you exit the program or when you free their
	memories.

	Source: https://www.youtube.com/watch?v=4NPOIaUxnnk&list=PLs8u0JIdefW3ivetf3rE4Sb3Jmas2YAND&index=72
*/
int main()
{
	/*
		MAIN 1
	*/
	std::cout << "\n----MAIN 1----\n" << std::endl;
	{
		const Animal* meta;
		const Animal* dog;
		const Animal* cat;

		meta = new Animal("Hyena");
		dog = new Dog();
		cat = new Cat();

		std::cout << "\n\n";

		std::cout << meta->getType() << " " << std::endl;
		std::cout << dog->getType() << " " << std::endl;
		std::cout << cat->getType() << " " << std::endl;
		
		std::cout << "\n\n";

		meta->makeSound();
		dog->makeSound();
		cat->makeSound();

		std::cout << "\n\n";

		delete(dog);
		delete(cat);
		delete(meta);
	}
	/*
		MAIN 2 -- WrongAnimal and WrongCat are the same as Animal and Cat
		classes but the difference is that WrongAnimal does not use the
		virtual keyword on its destructor and on the makeSound() method.
		As a result, the output would be wrong since we are creating base
		class pointers and passing them to derived class instances here.
		That is because of what we explained earlier (These pointers would
		only work with base class functions but with derived class 
		functions, it would only work with the derived class functions
		that have been overridden! The only way to override properly in 
		this scenario (base class pointer for derived class instance) 
		would be to use the virtual keyword)
	*/
	std::cout << "\n----MAIN 2----\n" << std::endl;
	{
		const WrongAnimal* meta;
		const WrongAnimal* cat;

		meta = new WrongAnimal("Hyena");
		cat = new WrongCat();

		std::cout << "\n\n";

		std::cout << meta->getType() << " " << std::endl;
		std::cout << cat->getType() << " " << std::endl;
		
		std::cout << "\n\n";

		meta->makeSound();
		cat->makeSound();

		std::cout << "\n\n";

		delete(cat);
		delete(meta);
	}
	/*
		MAIN 3 -- Since we are not creating base class pointers
		and passing them to derived class instances here, we won't
		have an issue even if we removed the virtual keyword. We 
		are testing that by using WrongAnimal and WrongCat classes 
		which do not have the virtual keywords on the makeSound() method
		and the destructor; yet, it still works properly. But 
		Main 1, on the other hand, will completely differ if you 
		remove the virtual keywords because there, we are using pointers
		of the base class even on instances of the derived classes .
	*/
	std::cout << "\n----MAIN 3----\n" << std::endl;
	{
		WrongAnimal		meta("Hyena");
		WrongCat		Ashley;

		std::cout << "\n\n";

		meta.makeSound();
		Ashley.makeSound();

		std::cout << "\n\n";

		std::cout << "I am Buster and my type is " << meta.getType() << std::endl;
		std::cout << "I am Ashley and my type is " << Ashley.getType() << std::endl;

		std::cout << "\n\n";
	}
}
