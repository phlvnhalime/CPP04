
#include "Dog.hpp"

Dog::Dog() {
    std::cout << RED <<"Dog contructor is called"<< RESET << std::endl;
    name = "Dog";
}

Dog::Dog(const Dog& copy) : Animal(copy){
    std::cout << "Dog Copy constructor has been created" << std::endl;
}

Dog& Dog::operator=(const Dog& copy)
{
    std::cout << "Dog Operator Assignment has been created" << std::endl;
    if(this != &copy)
    {
        name = copy.name;
    }
    return *this;
}

Dog::~Dog(){
    std::cout << GREEN <<"Dog Destructor has been created" << RESET << std::endl;
}

void Dog::makeSound() const {
    std::cout << BLUE <<"HAV HAV" << RESET << std::endl;
}
