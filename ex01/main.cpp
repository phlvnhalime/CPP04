
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"
#include <iostream>


int main()
{

    const Animal* j = new Dog();
    const Animal* i = new Cat();


    delete j;//should not create a leak
    delete i;

    std::cout << std::endl;
    const Animal* animal[4];
    animal[0] =new Dog();
    animal[1] =new Dog();
    animal[2] =new Cat();
    animal[3] =new Cat();

    for(int i = 0;  i < 4; i++)
    {
        delete animal[i];
    }
    
    return 0;
}
