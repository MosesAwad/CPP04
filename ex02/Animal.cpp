
#include "Animal.hpp"

Animal::Animal(std::string type)
{
	std::cout << "Animal constructor called" << std::endl;
	this->type = type;
}

Animal&	Animal::operator=(const Animal&	other)
{
	if (this != &other)
	{
		this->type = other.type;
	}
	return (*this);
}

Animal::Animal(const Animal& other)
{
	*this = other;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

const std::string&	Animal::getType() const
{
	return (this->type);
}
