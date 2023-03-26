NAME := zombie

CC := c++
CFLAGS := -Wall -Wextra -Werror -std=c++98 -fsanitize=address -g

PATH_SRC := ./src
PATH_OBJ := ./obj
PATH_INCL := ./incl

INCL := $(PATH_INCL)/Zombie.hpp

SRCS := $(PATH_SRC)/main.cpp $(PATH_SRC)/newZombie.cpp \
		$(PATH_SRC)/randomChump.cpp $(PATH_SRC)/Zombie.cpp

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