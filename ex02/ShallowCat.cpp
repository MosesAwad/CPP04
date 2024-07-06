
#include "ShallowCat.hpp"

ShallowCat::ShallowCat() : Animal("Cat"), brain(new Brain())
{
	std::cout << "ShallowCat constructor called" << std::endl;
}

/*
	In here I commented out the part where I free the ShallowCat's
	brain for a reason. Obviously, as the name suggests, we are
	creating a shallow copy of the cat. So, in my main function,
	particulary the main3 section, we see that there are three
	cats:
		ShallowCat*	shallow_amie = new ShallowCat();
		ShallowCat*	shallow_amie_copy = new ShallowCat();
		ShallowCat* shallow_amie_copy2 = new ShallowCat(*shallow_amie);
	
	shallow_amie_copy basically gets a copy of shallow_amie but through
	the assignment operator while shallow_amie_cop2 gets a copy of
	shallow_amie through a copy constructor. But what happens is that
	both shallow_amie and shallow_amie_copy2 get the exact same Brain
	for shallow_amie because the Brain attribute is a pointer. This is
	what is known as a shallow copy. So, if I free the brain in the
	~ShallowCat() destructor, I would be freeing the same brain of
	shallow_amie two more times! That would cause an invalid free
	error. So just to bypass that issue, I removed the freeing of the
	brain from the destructor and I manually free shallow_amie's copy
	in the main function directly, so that it gets freed only once and
	I get to avoid that error.
*/
ShallowCat::~ShallowCat()
{
	// delete(this->brain);
	std::cout << "ShallowCat destructor called" << std::endl;
}

void	ShallowCat::makeSound() const
{
	std::cout << "Meow meow" << std::endl;
}

void	ShallowCat::getBrainAddress() const
{
	std::cout << "The memory address associated with this"
		" ShallowCat's brain is " << this->brain << std::endl;
}

void ShallowCat::shallowBrainFree() const
{
	delete(this->brain);
}
