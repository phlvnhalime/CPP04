#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    std::cout << RED << "WrongCat constructor has been created" << RESET << std::endl;
    name = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& copy) : WrongAnimal(copy){
    std::cout <<"WrongCat Copy constructor has been created" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& copy) {
    std::cout << "WrongCat operator assignment has been created" << std::endl;
    if(this != &copy)
    {
        name = copy.name;
    }
    return *this;
}

WrongCat::~WrongCat(){
    std::cout << GREEN <<"WrongCat Destructor has been created" << RESET << std::endl;
}

void WrongCat::makeSound() const{
    std::cout << BLUE << "WrongCat Meow Meow" << RESET << std::endl;
}


