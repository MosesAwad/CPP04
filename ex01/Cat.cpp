
#include "Cat.hpp"

Cat::Cat() : Animal("Cat"), brain(new Brain())
{
	std::cout << "Cat constructor called" << std::endl;
}

Cat::~Cat()
{
	delete(this->brain);
	std::cout << "Cat destructor called" << std::endl;
}

void	Cat::makeSound() const
{
	std::cout << "Meow meow" << std::endl;
}

void	Cat::getBrainAddress() const
{
	std::cout << "The memory address associated with this"
		" cat's brain is " << this->brain << std::endl;
}
