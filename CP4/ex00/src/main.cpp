#include "../incl/Animal.hpp"
#include "../incl/Cat.hpp"
#include "../incl/Dog.hpp"
#include "../incl/WrongCat.hpp"
#include "../incl/WrongAnimal.hpp"

int main()
{
	{	
		std::cout << "\e[1;35m====================Constructing======================\033[0m" << std::endl;
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		std::cout << "\e[1;35m=====================Testing=========================\033[0m" << std::endl;
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		meta->makeSound();
		i->makeSound(); //will output the cat sound!
		j->makeSound();
		std::cout << "\e[1;35m====================Deconstructing===================\033[0m" << std::endl;
		delete meta;
		delete i;
		delete j;
	}
	std::cout << "\n\n\e[1;36m====================WrongAnimal======================\033[0m\n\n" << std::endl;
	{
		std::cout << "\e[1;31m====================Constructing======================\033[0m" << std::endl;
		const WrongAnimal *wrgan = new WrongAnimal();
		const WrongAnimal *wrn = new WrongCat();
		const WrongCat wrnc;
		std::cout << "\e[1;31m=====================Testing=========================\033[0m" << std::endl;
		std::cout << wrgan->getType() << " " << std::endl;
		std::cout << wrn->getType() << " " << std::endl;
		std::cout << wrnc.getType() << " " << std::endl;
		wrgan->makeSound();
		wrn->makeSound(); 
		wrnc.makeSound(); //will output the wrong cat sound!
		std::cout << "\e[1;31m====================Deconstructing===================\033[0m" << std::endl;
		delete wrgan;
		delete wrn;
	}
    return 0;
}