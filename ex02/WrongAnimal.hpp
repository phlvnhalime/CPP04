
#pragma once

#include <iostream>
#include <string>
#include "Animal.hpp"

class WrongAnimal {
    protected:
        std::string name;
    public:
        WrongAnimal();
        WrongAnimal(const WrongAnimal& copy);
        WrongAnimal& operator=(const WrongAnimal& copy);
        ~WrongAnimal();

        void makeSound() const;
        std::string getType() const;
};


