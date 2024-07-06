
#include "Dog.hpp"

Dog::Dog() : Animal("Dog"), brain(new Brain())
{
	std::cout << "Dog constructor called" << std::endl;
}

Dog::~Dog()
{
	delete(this->brain);
	std::cout << "Dog destructor called" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other), brain(new Brain())
{
	*this = other;
}

Dog& Dog::operator=(const Dog& other)
{
	if (this != &other)
	{
		this->Animal::operator=(other);
		Brain* newBrain = new Brain(*other.brain); // Deep copy using the copy constructor of the Brain() class
		delete (this->brain);
		this->brain = newBrain;
	}
	return (*this);
}

void	Dog::makeSound() const
{
	std::cout << "Woof woof" << std::endl;
}

void	Dog::getBrainAddress() const
{
	std::cout << "The memory address associated with this"
		" dog's brain is " << this->brain << std::endl;
}
