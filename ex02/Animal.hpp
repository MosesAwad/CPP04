
#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <string>
#include <iostream>

class Animal
{
	protected:
		std::string type;
	public:
		Animal(std::string type);
		Animal(const Animal& other);
		virtual ~Animal();
		Animal& operator=(const Animal& other);

		virtual void makeSound() const = 0; // By setting a virtual function equal to 0 (aka making it a PURE virtual function), we make Animal class an Abstract class.
		const std::string&	getType() const;
};

#endif