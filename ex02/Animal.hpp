
#pragma once

#include <iostream>
#include <string>


/* ************************************************************************** *
    Start by implementing a simple base class called Animal. It has one protected
    attribute:
    • std::string type;
    Implement a Dog class that inherits from Animal.
    Implement a Cat class that inherits from Animal.
    These two derived classes must set their type field depending on their name. Then,
    the Dog’s type will be initialized to "Dog", and the Cat’s type will be initialized to "Cat".
    The type of the Animal class can be left empty or set to the value of your choice.
    Every animal must be able to use the member function:
    makeSound()
    It will print an appropriate sound (cats don’t bark).
************************************************************************** */

#define RESET       "\033[0m"
#define BLACK       "\033[30m"
#define RED         "\033[31m"
#define GREEN       "\033[32m"
#define YELLOW      "\033[33m"
#define BLUE        "\033[34m"


class Animal{
    protected:
        std::string name;
    public:
        // Constructor (Default)
        Animal();
        // Copy of constructor
        Animal(const Animal& copy);
        // Assignment opperator
        Animal& operator=(const Animal& copy);

        // It must be virtual because without virtual destructor only animal will called
        virtual ~Animal();
        /*
         Every animal must be able to use the member function:
            makeSound() 
         It will print an appropriate sound (cats don’t bark).
        */
        // It is a function for polymorphism 
        virtual void makeSound() const = 0;
        std::string getType() const;
};

