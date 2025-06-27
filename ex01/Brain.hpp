#pragma once

#include <iostream>
#include <string>

#define RESET       "\033[0m"
#define BLACK       "\033[30m"
#define RED         "\033[31m"
#define GREEN       "\033[32m"
#define YELLOW      "\033[33m"
#define BLUE        "\033[34m"

class Brain{
    private:
    std::string ideas[100];
    public:
    Brain();
    Brain(const Brain& copy);
    Brain& operator=(const Brain& copy);
    ~Brain();

    void setIdea(int i, const std::string& idea);
    std::string getIdea(int i)const;
};
