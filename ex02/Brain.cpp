#include "Brain.hpp"

 Brain::Brain(){
    std::cout << RED << "Brain Constructor has been created" << RESET << std::endl;
    for(int i = 0; i < 100; i++)
    {
        ideas[i] = "";
    }
 }
Brain::Brain(const Brain& copy){
    std::cout << "Brain Copy Constructor has been created" << std::endl;
    for(int i = 0; i < 100; i++)
    {
        ideas[i] = copy.ideas[i];
    }
}
Brain& Brain::operator=(const Brain& copy){
    std::cout << "Brain Operator Assignment has been created" << std::endl;
    if(this != &copy)
    {
        for(int i = 0; i < 100; i++)
        {
            ideas[i] = copy.ideas[i];
        }
    }
    return *this;
}
Brain::~Brain(){
    std::cout << GREEN << "Brain Destructor has been created" << RESET << std::endl;
}

void Brain::setIdea(int i, const std::string& idea){
    if(i >= 0 && i < 100)
    {
        ideas[i] = idea;
    }
}
std::string Brain::getIdea(int i) const {
    if(i >= 0 && i < 100)
    {
        return ideas[i];
    }
    return "";
}