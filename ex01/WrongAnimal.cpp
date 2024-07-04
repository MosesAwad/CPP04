
#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(std::string type)
{
	this->type = type;
	std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal& other)
{
	if (this != &other)
	{
		this->type = other.type;
	}
	return (*this);
}

WrongAnimal::WrongAnimal(const WrongAnimal& other)
{
	*this = other;
}

void	WrongAnimal::makeSound() const
{
	std::cout << "This is the default sound (WrongAnimal)" << std::endl;
}

const	std::string& WrongAnimal::getType() const
{
	return (this->type);
}

