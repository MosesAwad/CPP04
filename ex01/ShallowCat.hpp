
#ifndef SHALLOWCAT_HPP
# define SHALLOWCAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class ShallowCat : public Animal
{
	private:
		Brain*	brain;
	public:
		ShallowCat();
		~ShallowCat();
		void makeSound() const;
		void getBrainAddress() const;
		void shallowBrainFree() const;
};

#endif