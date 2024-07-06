
#include "Brain.hpp"

// The std::string class has a default constructor that initializes
// its instance automatically to an empty string. So each element
// in the ideas array is an empty string ("") by default. Not need to
// worry about uninitialized random values.
Brain::Brain()
{
	std::cout << "Brain constructor has been called" << std::endl;
}

Brain&	Brain::operator=(const Brain& other)
{
	if (this != &other)
	{
		for (int i = 0; i < 100; i++) {
			this->ideas[i] = other.ideas[i];
		}
	}
	return (*this);
}

Brain::Brain(const Brain& other)
{
	*this = other;
}

Brain::~Brain()
{
	std::cout << "Brain destructor has been called" << std::endl;
}
