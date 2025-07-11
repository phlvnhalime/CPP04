
#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
    private:
        Brain* brain;
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
        Brain* getBrain() const;
};

