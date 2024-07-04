
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	/*
		MAIN 1 -- What you would think to do typically is this:
			const Animal* animals;
			animals = new Animal[4];
		This works but the issue is that our Animal class does
		not have a default constructor, so we get the following
		error:
			no default constructor exists for class "Animal"
		To bypass this issue, we initialize it as follows:
			const Animal* animals[4];
			for (int i = 0; i < 2; i++) {
				animals[i] = new Cat();
			}
			for (int i = 2; i < 4; i++) {
				animals[i] = new Dog();
			}

			OR

			const Animal* animals[4] = {new Cat(), new Cat(), new Dog(), new Dog()};

		In both options shown above, we are dynamically allocating memory
		for Cats and Dogs classes directly because these classes don't 
		need default constructors, while the array itself is just statically
		allocating Animal class POINTERS! not OBJECTS! with a size of 4. That's
		why it worked without needing a default constructor. In the previous 
		attempt, I was trying to directly assign 4 new animals objects via the
		key word new to the Animal pointer array, which wouldn't work because
		I cannot directly assign 4 new Animal class objects without a default
		constructor!
	*/
	std::cout << "\n----MAIN 1----\n" << std::endl;
	{
		const Animal* animals[4];
	
		// Assign half cats and half dogs to the animal pointer array of size 4.
		for (int i = 0; i < 2; i++) {
			animals[i] = new Cat();
		}
		for (int i = 2; i < 4; i++) {
			animals[i] = new Dog();
		}

		std::cout << "\n\n";
		// Free the dynamically allocated memory for members of the animals array.
		for (int i = 0; i < 4; i++) {
			delete (animals[i]);
		}
	}

	/*
		MAIN 2 -- Testing shallow copies vs. deep copies.
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
	// /*
	// 	MAIN 3 -- Since we are not creating base class pointers
	// 	and passing them to derived class instances here, we won't
	// 	have an issue even if we removed the virtual keyword. We 
	// 	are testing that by using WrongAnimal and WrongCat classes 
	// 	which do not have the virtual keywords on the makeSound() method
	// 	and the destructor; yet, it still works properly. But 
	// 	Main 1, on the other hand, will completely differ if you 
	// 	remove the virtual keywords because there, we are using pointers
	// 	of the base class even on instances of the derived classes .
	// */
	// std::cout << "\n----MAIN 3----\n" << std::endl;
	// {
	// 	WrongAnimal		meta("Hyena");
	// 	WrongCat		Ashley;

	// 	std::cout << "\n\n";

	// 	meta.makeSound();
	// 	Ashley.makeSound();

	// 	std::cout << "\n\n";

	// 	std::cout << "I am Buster and my type is " << meta.getType() << std::endl;
	// 	std::cout << "I am Ashley and my type is " << Ashley.getType() << std::endl;

	// 	std::cout << "\n\n";
	// }
	return (0);
}
