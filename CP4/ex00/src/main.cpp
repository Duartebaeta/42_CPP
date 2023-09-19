#include "../incl/Animal.hpp"
#include "../incl/Cat.hpp"
#include "../incl/Dog.hpp"
#include "../incl/WrongCat.hpp"
#include "../incl/WrongAnimal.hpp"

int main()
{
	// Test Animal, Cat, and Dog
	Animal* genericAnimal = new Animal();
	Animal* someCat = new Cat();
	Animal* someDog = new Dog();

	std::cout << "Animal, Cat, and Dog Testing:" << std::endl;

	// Check type
	std::cout << genericAnimal->getType() << std::endl;
	std::cout << someCat->getType() << std::endl;
	std::cout << someDog->getType() << std::endl;

	// Make sound
	genericAnimal->makeSound();
	someCat->makeSound();
	someDog->makeSound();

	// Clean up
	delete genericAnimal;
	delete someCat;
	delete someDog;

	std::cout << "---------------------------------" << std::endl;

	// Test WrongAnimal and WrongCat
	WrongAnimal* genericWrongAnimal = new WrongAnimal();
	WrongAnimal* wrongCat = new WrongCat();

	std::cout << "WrongAnimal and WrongCat Testing:" << std::endl;

	// Check type
	std::cout << genericWrongAnimal->getType() << std::endl;
	std::cout << wrongCat->getType() << std::endl;

	// Make sound
	genericWrongAnimal->makeSound();
	wrongCat->makeSound();

	// Clean up
	delete genericWrongAnimal;
	delete wrongCat;

	return 0;
}