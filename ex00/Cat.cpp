#include "Cat.hpp"

Cat::Cat()
{
    std::cout << RED << "Cat constructor has been created" << RESET << std::endl;
    name = "Cat";
}

Cat::Cat(const Cat& copy) : Animal(copy){
    std::cout <<"Cat Copy constructor has been created" << std::endl;
}

Cat& Cat::operator=(const Cat& copy) {
    std::cout << "Cat operator assignment has been created" << std::endl;
    if(this != &copy)
    {
        name = copy.name;
    }
    return *this;
}

Cat::~Cat(){
    std::cout << GREEN <<"Cat Destructor has been created" << RESET << std::endl;
}

void Cat::makeSound() const{
    std::cout << BLUE << "Meow Meow" << RESET << std::endl;
}


