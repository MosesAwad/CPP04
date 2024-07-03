
#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("cat")
{
	std::cout << "WrongCat constructor called" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called" << std::endl;
}

void	WrongCat::makeSound() const
{
	std::cout << "Meow meow" << std::endl;
}
