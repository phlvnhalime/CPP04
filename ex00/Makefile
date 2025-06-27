NAME = Animal

CXX = c++

CXXFLAG = -Wall -Wextra -Werror -std=c++11

SRCS= main.cpp Animal.cpp Cat.cpp Dog.cpp WrongAnimal.cpp WrongCat.cpp

OBJ = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAG) $(OBJ) -o $(NAME)

%.o:%.cpp
	$(CXX) $(CXXFLAG) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all 

.PHONY: all clean fclean re
