
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

Cat::Cat(const Cat& other) : Animal(other), brain(new Brain())
{
    *this = other;
}

/*
    Saying this:
        Brain* newBrain = new Brain(*other.brain);
		delete (this->brain);
		this->brain = newBrain;
    Is the same as doing this:
        Brain* brain_deep = new Brain();
        *brain_deep = *other.brain;
        delete (this->brain);
        this->brain = brain_deep;
    
    Also, we have to delete the current instance of brain
    because even if we do this:
        Cat* amie = new Cat();
		Cat* amie_copy = new Cat();
        *amie_copy = *amie;
    Then amie_copy got its own brain from the line 
    Cat* amie_copy = new Cat(), because the constructor is
    initialized as follows:
        Cat::Cat() : Animal("Cat"), brain(new Brain())
    So that brain has to be freed as well because the 
    assignment operator will assign it a new brain called
    newBrain which has a separate allocation via the keyword
    new.

    Also, C++ allows implicit conversion from a derived class (Cat)
    to its base class (Animal). This means you can pass a const Cat& 
    to a function expecting a const Animal&, as long as Cat is derived 
    from Animal. So, Animal::operator=(other is valid even though other
    is const Cat& and not const Animal& because Cat inherits from Animal. 
    The compiler understands that other can be treated as an Animal due 
    to inheritance. So this is why it works in case you were wondering 
    how it worked even though the Animal::operator= function should expect
    a const Animal& argument.
*/
Cat& Cat::operator=(const Cat& other)
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

void	Cat::makeSound() const
{
	std::cout << "Meow meow" << std::endl;
}

void	Cat::getBrainAddress() const
{
	std::cout << "The memory address associated with this"
		" Cat's brain is " << this->brain << std::endl;
}
