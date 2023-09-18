#include "../incl/Animal.hpp"
#include "../incl/Cat.hpp"
#include "../incl/Dog.hpp"
#include "../incl/WrongCat.hpp"
#include "../incl/WrongAnimal.hpp"

int main()
{
	const WrongAnimal* meta = new WrongAnimal();
	const Animal* j = new Dog();
	const WrongAnimal* i = new WrongCat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	delete i;
	delete meta;
	delete j;
	return 0;
}