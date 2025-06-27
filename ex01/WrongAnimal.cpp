#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(): name("WrongAnimal"){
    std::cout << RED << "WrongAnimal Constructor has been created" << RESET << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& copy) : name(copy.name){
    std::cout << "WrongAnimal Copy constructor has been created" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& copy){
    if(this != &copy)
    {
        name = copy.name;
    }
    std::cout << "WrongAnimal Operator assignment has been created" << std::endl;
    return *this;
}

WrongAnimal::~WrongAnimal(){
    std::cout << GREEN << "WrongAnimal Destructor has been created" << RESET << std::endl;
}

void WrongAnimal::makeSound() const{
    std::cout << BLUE << "Wrong Animal" << RESET << std::endl;
}
std::string WrongAnimal::getType() const{
    return name;
}
