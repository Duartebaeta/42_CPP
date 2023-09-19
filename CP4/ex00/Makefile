NAME := animal

CC := c++
CFLAGS := -Wall -Wextra -Werror -std=c++98 -g

PATH_SRC := ./src
PATH_OBJ := ./obj
PATH_INCL := ./incl

INCL := $(PATH_INCL)/Animal.hpp $(PATH_INCL)/Dog.hpp $(PATH_INCL)/Cat.hpp \
		$(PATH_INCL)/WrongCat.hpp $(PATH_INCL)/WrongAnimal.hpp

SRCS := $(PATH_SRC)/main.cpp $(PATH_SRC)/Animal.cpp $(PATH_SRC)/Dog.cpp $(PATH_SRC)/Cat.cpp \
		$(PATH_SRC)/WrongCat.cpp $(PATH_SRC)/WrongAnimal.cpp

OBJS := $(SRCS:.cpp=.o)

%.o: %.cpp
	@$(CC) $(CFLAGS) -c $< -o $@

$(PATH_OBJ)%.o: $(PATH_SRC)%.cpp
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(PATH_OBJ)
	@rm -f $(NAME)

re: fclean all

.PHONY:	all clean fclean re