#include "Cat.hpp"

Cat::Cat()
{
    std::cout << RED << "Cat constructor has been created" << RESET << std::endl;
    name = "Cat";
    brain = new Brain();
}

Cat::Cat(const Cat& copy) : Animal(copy){
    std::cout <<"Cat Copy constructor has been created" << std::endl;
    brain = new Brain(*copy.brain);
}

Cat& Cat::operator=(const Cat& copy) {
    std::cout << "Cat operator assignment has been created" << std::endl;
    if(this != &copy)
    {
        name = copy.name;
        delete brain;
        brain = new Brain(*copy.brain);
    }
    return *this;
}

Cat::~Cat(){
    std::cout << GREEN <<"Cat Destructor has been created" << RESET << std::endl;
    delete brain;
}

void Cat::makeSound() const{
    std::cout << BLUE << "Meow Meow" << RESET << std::endl;
}

Brain* Cat::getBrain() const{
    return brain;
}

