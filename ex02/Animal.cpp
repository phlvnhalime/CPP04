
#include "Animal.hpp"

Animal::Animal(): name("Animal"){
    std::cout << GREEN <<"Animal default constructor called" << RESET << std::endl;
}

Animal::Animal(const Animal& copy): name(copy.name){
    std::cout << "Animal copy Constructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& copy){
    if(this != &copy)
    {
        name = copy.name;
    }
    std::cout << "Animal assignment opperator called" << std::endl;
    return *this;
}

Animal::~Animal(){
    std::cout << GREEN << "Animal destructor called" << RESET << std::endl;
}
//  I don't need makeSound for this exercise
// void Animal::makeSound() const{
//     std::cout << "Animal sounds" << std::endl;
// }

std::string Animal::getType() const{
    return name;
}
