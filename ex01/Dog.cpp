
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

void	Dog::makeSound() const
{
	std::cout << "Woof woof" << std::endl;
}

void	Dog::getBrainAddress() const
{
	std::cout << "The memory address associated with this"
		" dog's brain is " << this->brain << std::endl;
}
