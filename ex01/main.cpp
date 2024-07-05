
#include "Dog.hpp"
#include "Cat.hpp"
#include "ShallowCat.hpp"

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
		MAIN 2 -- Deep copy exhbit.
	*/
	std::cout << "\n----MAIN 2----\n" << std::endl;
	{
		Cat* amie = new Cat();
		Cat* amie_copy = new Cat();
		Cat* amie_copy2 = new Cat(*amie);

		*amie_copy = *amie;

		std::cout << "\n\n";
	
		std::cout << "The memory address of amie's brain is -> ";
		amie->getBrainAddress();
		std::cout << "The memory address of amie_copy's brain is -> ";
		amie_copy->getBrainAddress();
		std::cout << "The memory address of amie_copy2's brain is -> ";
		amie_copy2->getBrainAddress();

		std::cout << "\n\n";
		delete(amie);
		delete(amie_copy);
		delete(amie_copy2);
	}
	/*
		MAIN 3 -- Shallow copy exhibit

		Since I do not have separate versions of the copy constructors and the
		equal sign operator overloader for ShallowCat, the Animal base class
		versions of those are the ones being called. So they will copy all
		the Animal class specific attributes but since Brain* brain is local
		to the derived ShallowCat classes, it won't copy them. So what happens
		is that shallow_amie_copy and shallow_amie_copy2 would recive the exact
		same brain as shallow_amie because brain is a pointer. 

		But even if you have sepatate versions of the copy constructors and the
		equal sign operator overloader for ShallowCat as follows:
		
		ShallowCat& ShallowCat::operator=(const ShallowCat& other)
		{
			if (this != &other)
			{
				this->Animal::operator=(other);
				delete(this->brain);
				this->brain = other.brain;
			}
			return (*this);
		}

		ShallowCat::ShallowCat(const Cat& other) : Animal(other), brain(new Brain())
		{
			*this = other;
		}


		this would still be a shallow copy. The only way to create a deep copy is
		to "realloc" as shown in the copy constructor and equal sign operator
		overloader of the Cat class (the correct one with the deep copy).
	*/
	std::cout << "\n----MAIN 3----\n" << std::endl;
	{
		ShallowCat*	shallow_amie = new ShallowCat();
		ShallowCat*	shallow_amie_copy = new ShallowCat();
		ShallowCat* shallow_amie_copy2 = new ShallowCat(*shallow_amie);

		std::cout << "\n\n";

		// Manually free shallow_amie_copy's brain here because this ShallowCat
		// had its own brain which was created when we said new ShallowCat() 
		// (which is the constructor). And since the ShallowCat() function
		// does not have its own copy.
		shallow_amie_copy->shallowBrainFree();
		*shallow_amie_copy = *shallow_amie; 

		std::cout << "\n\n";
		std::cout << "The memory address of amie's brain is -> ";
		shallow_amie->getBrainAddress();
		std::cout << "The memory address of amie_copy's brain is -> ";
		shallow_amie_copy->getBrainAddress();
		std::cout << "The memory address of amie_copy's brain is -> ";
		shallow_amie_copy2->getBrainAddress();

		std::cout << "\n\n";

		shallow_amie->shallowBrainFree();

		delete(shallow_amie);
		delete(shallow_amie_copy);
		delete(shallow_amie_copy2);
	}
	return (0);
}
