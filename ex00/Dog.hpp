
#pragma once

#include "Animal.hpp"

class Dog : public Animal {
    public:
        // Constructor
        Dog();
        // Copy constructor
        Dog(const Dog& copy);
        // Operatoin assignment
        Dog& operator=(const Dog& copy);
        // Destructor
        ~Dog();
        
        void makeSound() const override;

};

