
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"
#include <iostream>


int main()
{
    // const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    // meta->makeSound();

    std::cout << std::endl;
    std::cout << "=== Testing Wrong PolyMorphism ===" << std::endl;
    const WrongAnimal* wrongAnimal = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();
    std::cout << wrongAnimal->getType() << " " << std::endl;
    std::cout << wrongCat->getType() << " " << std::endl;

    std::cout << std::endl;
    std::cout << "=== Wrong Sound ===" << std::endl;
    wrongAnimal->makeSound();
    wrongCat->makeSound();

    std::cout << std::endl;
    std::cout << "++++ Brain Test ++++" << std::endl;
    const Animal* animal[4];
    animal[0] =new Dog();
    animal[1] =new Dog();
    animal[2] =new Cat();
    animal[3] =new Cat();

    for(int i = 0;  i < 4; i++)
    {
        animal[i]->makeSound();
    }

    std::cout << std::endl;
    std::cout << "=== Clean ===" << std::endl;
    // delete meta;
    delete j;
    delete i;
    delete wrongAnimal;
    delete wrongCat;


    for(int i = 0;  i < 4; i++)
    {
        delete animal[i];
    }
    
    return 0;
}
