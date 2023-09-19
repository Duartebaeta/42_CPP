#include "../incl/Animal.hpp"
#include "../incl/Cat.hpp"
#include "../incl/Dog.hpp"
#include "../incl/WrongCat.hpp"
#include "../incl/WrongAnimal.hpp"

int main()
{
    {
        std::cout << "===== Array Test =====\n";
        Animal *animals[4];
        animals[0] = new Dog();
        animals[1] = new Cat();
        animals[2] = new Dog();
        animals[3] = new Cat();

        for (int i = 0; i < 4; ++i)
        {
            std::cout << animals[i]->getType() << ": ";
            animals[i]->makeSound();
        }

		for (int i = 0; i < 4; i++) {
			delete(animals[i]);
		}
    }

    {
        std::cout << "===== Brain Ideas Test =====\n";
        Dog* dog1 = new Dog();
        dog1->getBrain()->ideas[0] = "Idea 1";
        dog1->getBrain()->ideas[1] = "Idea 2";

        std::cout << "Dog1 Ideas: " << dog1->getBrain()->ideas[0] << ", " << dog1->getBrain()->ideas[1] << '\n';

        Dog dog2 = *dog1; // Testing deep copy

        std::cout << "Dog2 Ideas: " << dog2.getBrain()->ideas[0] << ", " << dog2.getBrain()->ideas[1] << '\n';

        dog2.getBrain()->ideas[0] = "New Idea 1";
        std::cout << "Dog2 New Idea: " << dog2.getBrain()->ideas[0] << '\n';
		std::cout << "Dog1 Old Idea: " << dog1->getBrain()->ideas[0] << '\n';
		delete dog1;
    }

    {
        std::cout << "===== Assignment Operator Test =====\n";
        Dog dog1;
        Dog dog2;
        dog1.getBrain()->ideas[0] = "Dog1 Idea";
        dog2 = dog1; // Using assignment operator
        
        std::cout << "Dog2 Idea after assignment: " << dog2.getBrain()->ideas[0] << '\n';
    }

    return 0;
}
