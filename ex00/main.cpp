
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>


int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << j->getType() << "Cat" << std::endl;
    std::cout << i->getType() << "Dog" << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();

    std::cout << std::endl;
    std::cout << "=== Testing Wrong PolyMorphism ===" << std::endl;
    const WrongAnimal* wrongAnimal = new WrongAnimal();
    const WrongCat* wrongCat = new WrongCat();
    std::cout << wrongAnimal->getType() << "WrongAnimal" << std::endl;
    std::cout << wrongCat->getType() << "WrongCat" << std::endl;

    std::cout << std::endl;
    std::cout << "=== Wrong Sound ===" << std::endl;
    wrongAnimal->makeSound();
    wrongCat->makeSound();

    std::cout << std::endl;
    std::cout << "=== Clean ===" << std::endl;
    delete meta;
    delete j;
    delete i;
    delete wrongAnimal;
    delete wrongCat;

    return 0;
}
